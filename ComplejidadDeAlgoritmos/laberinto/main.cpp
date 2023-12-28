#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// tamaño del laberinto
#define n 21

using namespace std;

// Estructura para representar un punto (coordenadas)
struct Point {
    int x, y;

    //constructor
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Función para generar un laberinto con densidad dada
int **generarLaberinto(int **maze, float densidad) {
    // se le asigna un arreglo o Asignamos memoria para el laberinto
	maze = new int *[n];

    // Creamos una matriz bidimensional para representar el laberinto (asignamos columanos)
	for (int i = 0; i < n; i++) {
		maze[i] = new int[n];
	}

	// Cantidad de paredes inicial basada en la densidad
    int FParedes = densidad * 8;

    // Ajustar la densidad para considerar el tamaño de la matriz
    densidad = n * n * densidad / 4;

    // Inicialización de la matriz del laberinto
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Esquina superior izquierda
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == n - 1 && j == n - 1) || (i == n - 1 && j == n - 2))
                maze[i][j] = 0;
            // Borde superior, borde izquierdo, borde derecho y borde inferior
            else if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                maze[i][j] = 1;
            // Paredes adicionales cerca del centro del laberinto
            else if ((i == ((n + 1) / 2) && j == n - 2) || (i == ((n + 1) / 2) && j == 1) || (j == ((n + 1) / 2) && i == 1) || (j == ((n + 1) / 2) && i == n - 2))
                maze[i][j] = 1;
            // Interior vacío del laberinto
            else {
                maze[i][j] = 0;
            }
        }
    }

	// Generación del laberinto
    srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios

    for (int i = 0; i < densidad; i++) {
        // Genera coordenadas aleatorias x e y para una pared
        int x = rand() % (n - 4) + 2; // Valores aleatorios entre 2 y n - 2
        x = (x / 2) * 2; // Asegura que x sea par
        int y = rand() % (n - 4) + 2; // Valores aleatorios entre 2 y n - 2
        y = (y / 2) * 2; // Asegura que y sea par

        // Coloca una pared en la posición (y, x)
        maze[y][x] = 1;

        // Genera paredes adicionales cercanas a la posición recién creada
        for (int j = 0; j < FParedes; j++) {
            int mx[4] = {x, x, x + 2, x - 2};
            int my[4] = {y + 2, y - 2, y, y};
            int r = rand() % 4; // Elige una dirección aleatoria

            // Verifica si la celda vecina está vacía y coloca una pared
            if (maze[my[r]][mx[r]] == 0) {
                maze[my[r]][mx[r]] = 1;

                // Coloca una pared en el punto medio entre la posición actual y la celda vecina
                maze[my[r] + (y - my[r]) / 2][mx[r] + (x - mx[r]) / 2] = 1;
            }
        }
    }

    return maze; // Devuelve la matriz del laberinto generada
}

// Función para imprimir el laberinto, marcando la ruta más corta con asteriscos
void imprimir(int **maze) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == 1) {
                cout << "###"; // Paredes
            } else if (maze[i][j] == 2) {
                cout << " * "; // Ruta más corta marcada con asteriscos
            } else {
                cout << "   "; // Espacios vacíos
            }
        }
        cout << "\n";
    }
}

// Función para verificar si una coordenada es válida en el laberinto
bool esValido(int x, int y, int **maze) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0);
}

void imprimirPadre(vector<vector<Point>>& padre) {
    int N = padre.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "(" << padre[i][j].x << "," << padre[i][j].y << ") ";
        }
        cout << endl;
    }
}

void imprimirRuta(const vector<Point>& ruta) {
    cout << "Ruta encontrada:" << endl;
    for (const Point& punto : ruta) {
        cout << "(" << punto.x << "," << punto.y << ") ";
    }
    cout << endl;
}

// Función para encontrar la ruta más corta utilizando BFS y marcarla en la matriz
vector<Point> encontrarRutaCorta(int **maze) {
    // posibles direcciones
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    vector<vector<bool>> visitado(n, vector<bool>(n, false)); // Matriz de celdas visitadas 
    queue<Point> cola; // Cola para el algoritmo BFS

    visitado[0][0] = true; // Marcamos la entrada como visitada
    cola.push(Point(0, 0)); // Agregamos la entrada a la cola

    vector<vector<Point>> padre(n, vector<Point>(n, Point(-1, -1))); // Almacenamos padres para reconstruir la ruta (matriz)

    while (!cola.empty()) {
        // Extraer el primer elemento de la cola para su procesamiento
        Point actual = cola.front();
        cola.pop();

        // Verificar si hemos llegado al destino (la salida del laberinto)
        if (actual.x == n - 1 && actual.y == n - 1) {
            // Hemos llegado al destino (S), terminamos la búsqueda.
            break;
        }

        // Explorar las cuatro posibles direcciones desde la celda actual
        for (int i = 0; i < 4; i++) {
            // Calcular las nuevas coordenadas (nx, ny) en la dirección actual
            int nx = actual.x + dx[i];
            int ny = actual.y + dy[i];

            // Verificar si las nuevas coordenadas son válidas y no han sido visitadas
            if (esValido(nx, ny, maze) && !visitado[nx][ny]) {
                visitado[nx][ny] = true; // Marcamos como visitado
                cola.push(Point(nx, ny)); // Agregamos las nuevas coordenadas a la cola
                padre[nx][ny] = actual; // Almacenamos la celda actual como el padre de las nuevas coordenadas
                
                // cout << "\n";
            }
        }
    }
    
    imprimirPadre(padre);
    
    vector<Point> ruta; // Almacenamos la ruta más corta
    int x = n - 1, y = n - 1; // Comenzamos desde la salida (S)

    while (x != -1 && y != -1) {
        ruta.push_back(Point(x, y)); // Agregamos el punto a la ruta
        Point padre_actual = padre[x][y]; // Obtenemos el padre
        x = padre_actual.x;
        y = padre_actual.y;
        // imprimirRuta(ruta);
    }

    reverse(ruta.begin(), ruta.end()); // Invertimos la ruta para que sea de la entrada (E) a la salida (S)

    // Marcamos la ruta en la matriz con valor 2
    for (const Point &p : ruta) {
        maze[p.x][p.y] = 2;
    }

    return ruta;
}

int main() {
    srand(time(NULL)); // Inicializamos el generador de números aleatorios con una semilla basada en el tiempo

    int **maze = generarLaberinto(maze,0.8); // Generamos un laberinto con densidad 0.3 (ajusta según lo desees)
    imprimir(maze); // Imprimimos el laberinto

    vector<Point> ruta = encontrarRutaCorta(maze); // Encontramos la ruta más corta

    cout << "Ruta más corta:\n";
    for (const Point &p : ruta) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    cout << "Laberinto con la ruta marcada:\n";
    imprimir(maze); // Imprimimos el laberinto con la ruta marcada con asteriscos

    return 0;
}

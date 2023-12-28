package ejemplo9;

public class SopaLetras {
    private char [][] sopa;
    private int filas, columnas;

    public SopaLetras(int filas, int columnas){
        this.filas = filas;
        this.columnas = columnas;
    }
    public char[][] getSopa(){
        return sopa;
    }
    public void setSopa(char[][] sopa){
        this.sopa = sopa;
    }
    public int getFilas(){
        return filas;
    }
    public void setFilas(int filas){
        this.filas = filas;
    }
    public int getColumnas(){
        return columnas;
    }
    public void setColumnas(int columnas){
        this.columnas = columnas;
    }

    public void imprimirSopa(){
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.print(sopa[i][j]+ " ");
            }
            System.out.println();
        }
    }
    public void encontrarPalabra(String palabra){
        // guardo el tamaño de la palabra
        int N;
        N = palabra.length();
        //creo lista de letras
        char [] letras = new char[N];
        //guardo cada letra en la lista mediante un for
        for (int i = 0; i < N; i++) {
            letras[i] = palabra.charAt(i);
        }
        int count;
        int cords[] = new int[] {-1,-1,-1,-1};
        int llave = 0;
        for (int i = 0; i < filas; i++) {
            count = 0;
            for (int j = 0; j < columnas; j++) {
                if (letras[count] == sopa[i][j]){
                    
                    if ((count != 0)){
                        count++;
                    }

                    if(count == 0){
                        cords[0] = i;
                        cords[1] = j;
                        count++;
                    }

                    if(count == N){
                        cords[2] = i;
                        cords[3] = j;
                        llave = 1;
                        break;
                    }
                }
            }
            if(llave == 1){
                llave = 0;
                break;
            }
        }

        if (cords[2] == -1){
            for (int i = 0; i < columnas; i++) {
                count = 0;
                for (int j = 0; j < filas; j++) {
                    if (letras[count] == sopa[j][i]){
                        
                        if ((count != 0)){
                            count++;
                        }

                        if(count == 0){
                            cords[0] = j;
                            cords[1] = i;
                            count++;
                        }

                        if(count == N){
                            cords[2] = j;
                            cords[3] = i;
                            llave = 1; 
                            break;
                        }
                    }
                }
                if(llave == 1){
                    llave = 0;
                    break;
                }
            }
        }
        
        if ((cords[2] != -1)) {
            System.out.print("Las coordenadas de inicio son: ");
            System.out.print(cords[0]);
            System.out.print(" , ");
            System.out.println(cords[1]);
            System.out.print("Las coordenadas finales son: ");
            System.out.print(cords[2]);
            System.out.print(" , ");
            System.out.println(cords[3]);
        }
        else{
            System.out.println("No se encuentra en la sopa");
        }
    }
}
class Nodo{
    int numero, altura; // Valor numérico del nodo y su altura en el árbol
    Nodo izquierda, derecha; // Referencias a los hijos izquierdo y derecho del nodo

    // Constructor para crear un nodo con un valor numérico dado
    public Nodo(int numero) {
        this.numero = numero; // Asigna el valor numérico al nodo
        altura = 1; // Inicializa la altura del nodo en 1 (altura predeterminada de un nodo)
    }
}

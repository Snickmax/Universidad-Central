class ArbolAVL {
    Nodo raiz; // Nodo raíz del árbol AVL

    // Función para obtener la altura de un nodo
    int altura(Nodo nodo) {
        if (nodo == null)
            return 0; // Si el nodo es nulo, su altura es 0
        return nodo.altura; // Devuelve la altura del nodo
    }

    // Función para obtener el factor de equilibrio de un nodo
    int getBalanceo(Nodo nodo) {
        if (nodo == null)
            return 0; // Si el nodo es nulo, su balanceo es 0
        return altura(nodo.izquierda) - altura(nodo.derecha); // Resta las alturas de los subárboles izquierdo y derecho
    }

    // Rotación a la derecha
    Nodo rotacionDerecha(Nodo y) {
        Nodo x = y.izquierda; // Guarda el nodo izquierdo de y en x
        Nodo T2 = x.derecha; // Guarda el subárbol derecho de x en T2

        // Realiza la rotación a la derecha
        x.derecha = y;
        y.izquierda = T2;

        // Actualiza las alturas de y y x
        y.altura = Math.max(altura(y.izquierda), altura(y.derecha)) + 1;
        x.altura = Math.max(altura(x.izquierda), altura(x.derecha)) + 1;

        return x; // Devuelve el nuevo nodo raíz después de la rotación
    }

    // Rotación a la izquierda
    Nodo rotacionIzquierda(Nodo x) {
        Nodo y = x.derecha; // Guarda el nodo derecho de x en y
        Nodo T2 = y.izquierda; // Guarda el subárbol izquierdo de y en T2

        // Realiza la rotación a la izquierda
        y.izquierda = x;
        x.derecha = T2;

        // Actualiza las alturas de x y y
        x.altura = Math.max(altura(x.izquierda), altura(x.derecha)) + 1;
        y.altura = Math.max(altura(y.izquierda), altura(y.derecha)) + 1;

        return y; // Devuelve el nuevo nodo raíz después de la rotación
    }

    // Función para insertar un nodo con el valor "numero" en el árbol AVL
    Nodo insertar(Nodo nodo, int numero) {
        if (nodo == null)
            return new Nodo(numero); // Crea un nuevo nodo si el nodo actual es nulo

        if (numero < nodo.numero)
            nodo.izquierda = insertar(nodo.izquierda, numero); // Inserta en el subárbol izquierdo
        else if (numero > nodo.numero)
            nodo.derecha = insertar(nodo.derecha, numero); // Inserta en el subárbol derecho
        else
            return nodo; // No permitir duplicados

        // Actualiza la altura del nodo actual
        nodo.altura = 1 + Math.max(altura(nodo.izquierda), altura(nodo.derecha));

        int balanceo = getBalanceo(nodo); // Calcula el factor de equilibrio

        // Casos de desequilibrio
        if (balanceo > 1) {
            if (numero < nodo.izquierda.numero) {
                // Rotación simple a la derecha
                return rotacionDerecha(nodo);
            } else {
                // Rotación izquierda-derecha
                nodo.izquierda = rotacionIzquierda(nodo.izquierda);
                return rotacionDerecha(nodo);
            }
        }
        if (balanceo < -1) {
            if (numero > nodo.derecha.numero) {
                // Rotación simple a la izquierda
                return rotacionIzquierda(nodo);
            } else {
                // Rotación derecha-izquierda
                nodo.derecha = rotacionDerecha(nodo.derecha);
                return rotacionIzquierda(nodo);
            }
        }

        return nodo; // Devuelve el nodo actual (sin cambios si no hay desequilibrio)
    }

    // Función para encontrar el nodo con el valor mínimo en un árbol
    Nodo minValorNodo(Nodo nodo) {
        Nodo actual = nodo;
        while (actual.izquierda != null)
            actual = actual.izquierda;
        return actual; // Devuelve el nodo con el valor mínimo
    }

    // Función para eliminar un nodo con el valor "numero" del árbol AVL
    Nodo eliminar(Nodo raiz, int numero) {
        if (raiz == null)
            return raiz; // Retorna nulo si la raíz es nula

        if (numero < raiz.numero)
            raiz.izquierda = eliminar(raiz.izquierda, numero); // Elimina en el subárbol izquierdo
        else if (numero > raiz.numero)
            raiz.derecha = eliminar(raiz.derecha, numero); // Elimina en el subárbol derecho
        else {
            // Nodo con un solo hijo o sin hijos
            if ((raiz.izquierda == null) || (raiz.derecha == null)) {
                Nodo temp = raiz.izquierda != null ? raiz.izquierda : raiz.derecha;

                if (temp == null) {
                    temp = raiz;
                    raiz = null;
                } else
                    raiz = temp;
            } else {
                // Nodo con dos hijos, obtener el sucesor inmediato
                Nodo temp = minValorNodo(raiz.derecha);

                raiz.numero = temp.numero;

                raiz.derecha = eliminar(raiz.derecha, temp.numero);
            }
        }

        if (raiz == null)
            return raiz;

        // Actualiza la altura del nodo actual
        raiz.altura = Math.max(altura(raiz.izquierda), altura(raiz.derecha)) + 1;

        int balanceo = getBalanceo(raiz); // Calcula el factor de equilibrio

        // Casos de desequilibrio
        if (balanceo > 1) {
            if (getBalanceo(raiz.izquierda) >= 0)
                return rotacionDerecha(raiz);
            else {
                raiz.izquierda = rotacionIzquierda(raiz.izquierda);
                return rotacionDerecha(raiz);
            }
        }
        if (balanceo < -1) {
            if (getBalanceo(raiz.derecha) <= 0)
                return rotacionIzquierda(raiz);
            else {
                raiz.derecha = rotacionDerecha(raiz.derecha);
                return rotacionIzquierda(raiz);
            }
        }

        return raiz; // Devuelve el nodo actual después de la eliminación (sin cambios si no hay desequilibrio)
    }

    // Función para insertar un nodo con el valor "numero" en el árbol AVL
    void insertar(int numero) {
        raiz = insertar(raiz, numero);
    }

    // Función para eliminar un nodo con el valor "numero" del árbol AVL
    void eliminar(int numero) {
        raiz = eliminar(raiz, numero);
    }

    // Función para recorrer el árbol en preorden (Raíz - Izquierda - Derecha)
    void preordenRID(Nodo nodo) {
        if (nodo != null) {
            System.out.print("matricula: "+nodo.numero+"\n");
            preordenRID(nodo.izquierda);
            preordenRID(nodo.derecha);
        }
    }
    
    // Función para recorrer el árbol en inorden (Izquierda - Raíz - Derecha)
    void inordenIRD(Nodo nodo) {
        if (nodo != null) {
            inordenIRD(nodo.izquierda);
            System.out.print("matricula: "+nodo.numero+"\n");
            inordenIRD(nodo.derecha);
        }
    }
    
    // Función para recorrer el árbol en postorden (Izquierda - Derecha - Raíz)
    void postordenIDR(Nodo nodo) {
        if (nodo != null) {
            postordenIDR(nodo.izquierda);
            postordenIDR(nodo.derecha);
            System.out.print("matricula: "+nodo.numero+"\n");
        }
    }
}
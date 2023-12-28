import java.util.Scanner;

// 6 3 8 2 1 10 11 7
public class AVLTreeMenu {
    public static void main(String[] args) {
        ArbolAVL arbol = new ArbolAVL();
        Scanner sc = new Scanner(System.in);

        int choice;
        do {
            System.out.println("\nMenú del Árbol AVL:");
            System.out.println("1. Insertar matriculas");
            System.out.println("2. Eliminar una matricula");
            System.out.println("3. Mostrar las matriculas en Preorden");
            System.out.println("4. Mostrar las matriculas en Inorden");
            System.out.println("5. Mostrar las matriculas en Postorden");
            System.out.println("6. Salir");
            System.out.print("Seleccione una opción: ");

            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    int insertValue;
                    do {
                        System.out.print("Ingrese el numero de matricula (0 para detener): ");
                        insertValue = sc.nextInt();
                        if (insertValue != 0) {
                            arbol.insertar(insertValue);
                            System.out.println("Matricula insertada: " + insertValue);
                        } else {
                            System.out.println("Deteniendo el registro.");
                            break;
                        }
                    } while (true);
                    break;
                case 2:
                    System.out.print("Ingrese la matricula a eliminar: ");
                    int deleteValue = sc.nextInt();
                    arbol.eliminar(deleteValue);
                    System.out.println("Matricula eliminada: " + deleteValue);
                    break;
                case 3:
                    System.out.println("Recorrido Preorden:");
                    arbol.preordenRID(arbol.raiz);
                    break;
                case 4:
                    System.out.println("Recorrido Inorden:");
                    arbol.inordenIRD(arbol.raiz);
                    break;
                case 5:
                    System.out.println("Recorrido Postorden:");
                    arbol.postordenIDR(arbol.raiz);
                    break;
                case 6:
                    System.out.println("Saliendo del programa.");
                    break;
                default:
                    System.out.println("Opción no válida. Por favor, seleccione una opción válida.");
            }
        } while (choice != 6);

        sc.close(); // Cierra el Scanner antes de salir
    }
}
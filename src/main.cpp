#include <iostream> 
#include "nodo.h"
#include "arbol.h"

/** 
 * @file 
 * @brief El programa completo del árbol binario.
 *
 * @details Las opciones son las siguientes:
 * - Opción: 1 Insertar un nodo del valor que el usuario desee.
 * - Opción 2: Mostrar el número total de nodos, y el número de nodos internos.
 * - Opción 3: Mostrar el promedio de los valores de los nodos, así como el valor máximo.
 * - Opción 4: Mostrar la categoría y valor de los nodos por nivel (de 0 en adelante).
 * - Opción 5: Mostrar el contenido del árbol en pre-orden, in-orden y post-orden.
 * - Opción 6: Salir del programa.
 */

int menu();
using namespace std;

int main()
{
    Arbol<int> arbol;  ///< Inicializa un árbol de tipo "int".
    int info; 

    while (true)
	{
		switch (menu())
		{
        case 1:
        {
            cout << "\n¿Qué valor desea agregar al árbol?: ";
            cin >> info;

            arbol.insertarDato(info);
            break;
        }
		case 2:
        {
            int aspecto1 = arbol.contarNodos();

            if (aspecto1 == 0)
            {
                cout << "\n¡El árbol se encuentra vacío!";
            }
            else
            {
                int aspecto2 = arbol.contarInternos();

                cout << "\nNúmero total de NODOS: " << aspecto1;
                cout << "\nNúmero total de NODOS INTERNOS: " << aspecto2;
            }
			break;
        }
		case 3:
        {
            try
            {
                int aspecto1 = arbol.buscarMax();
                double aspecto2 = arbol.promedio();
    
                cout << "\nValor MÁXIMO en el árbol: " << aspecto1;
                cout << "\nPROMEDIO de los nodos : " << aspecto2;
            }
            catch(const std::exception& e)
            {
                cerr << e.what() << "\n";
            }
            break;
        }
        case 4:
        {
            try
            {
                arbol.visualizacion();
            }
            catch(const std::exception& e)
            {
                cerr << e.what() << "\n";
            }
            break;
        }
        case 5:
        {
            try
            {
                arbol.orden();
            }
            catch(const std::exception& e)
            {
                cerr << e.what() << "\n";
            }
            break;
        }
        case 6:
        {
			cout << "\nSaliendo del programa...";
			exit(0);
			break;
        }
        }
    }
}

/***********************************************************************/

/** 
 * @brief Menú del programa que maneja el input (aportación) del usuario.
 *
 * @details Devuelve una opción a la función main().
 */

int menu()
{
    int opcion;
	do
	{
		cout << "\n\n\n\t--- MENU! ---";
        cout << "\n\n1) Insertar un nodo.\n";
		cout << "2) Conteo de estructura (Total de nodos y de nodos internos).\n";
		cout << "3) Análisis de datos (Valor máximo y promedio aritmético de los nodos).\n";
		cout << "4) Visualización selectiva (Información de los nodos hojas y de internos).\n";
        cout << "5) Visualización en pre-orden, in-orden y post-orden.\n";
        cout << "6) Salir del programa.\n";
		cout << "\n--> Seleccione una opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 6);
	return opcion;
}

/***********************************************************************/

/** 
 * @page Pruebas
 * @brief ¡Ejecución del programa!
 * @section pruebas_arbol Resultados de pruebas
 * 
 * Las siguientes imágenes muestran la ejecución exitosa del programa correspondiente
 * al árbol binario, el cual tiene las funciones...
 *
 * - Inserción de nodos.
 * - Conteo de la estructura.
 * - Análisis de datos.
 * - Visualización selectiva.
 * 
 * \image latex prueba1.png "Ejecución del Árbol Binario (Parte 1)"
 * \image html prueba1.png
 * 
 * \image latex prueba2.png "Ejecución del Árbol Binario (Parte 2)"
 * \image html prueba2.png
 * 
 * \image latex prueba3.png "Ejecución del Árbol Binario (Parte 3)"
 * \image html prueba3.png
 * 
 * \image latex prueba4.png "Ejecución del Árbol Binario (Parte 4)"
 * \image html prueba4.png
 * 
 * Si se usan excepciones, dado el caso que el árbol se encuentre vacío, el programa lanzará un mensaje de error, como se muestra a continuación...
 * 
 * \image latex prueba5.png "Uso de excepción (Parte 5 - Final)"
 * \image html prueba5.png
 */

#include <iostream>
#include <queue>
#include "arbol.h"
#include "nodo.h"
#include "excepcion.h"

/** 
 * @file 
 * @brief Implementación de los constructores y métodos de la plantilla Arbol.
 */

using namespace std;

/***********************************************************************/

/** 
 * @brief Inicializa el árbol vacío.
 * @details La referencia a la raíz del árbol se establece a nullptr.
 */

template <typename T>
Arbol<T>::Arbol()
{
    raiz = nullptr;
}

/***********************************************************************/

/** 
 * @brief Elimina los nodos asociados al árbol mediante una función recursiva.
 * @details Esta función es llamada por el destructor del árbol para liberar la memoria asignada a
 * los nodos del árbol.
 */

template <typename T>
void Arbol<T>::eliminarArbol(Nodo<T>* inicio)
{
    if (inicio != nullptr)
    {
        eliminarArbol(inicio->nodo_izq);
        eliminarArbol(inicio->nodo_der);
        delete inicio;
    }
}

/** 
 * @brief Destruye el árbol, liberando la memoria asignada a este.
 * @details Destructor del árbol que llama a la función eliminarArbol(Nodo<T>* inicio) para
 * liberar la memoria asignada al árbol binario.
 */

template <typename T>
Arbol<T>::~Arbol()
{
    eliminarArbol(raiz);
}

/***********************************************************************/

/** 
 * @brief Inserta un nuevo nodo con el valor de "dato" en el árbol.
 * @details El nuevo nodo se inserta en la "raiz" dado el caso que esta se encuentre vacia.
 * De lo contrario, se insertará en el subárbol izquiero si el valor del nuevo nodo es 
 * inferior al de la raíz, o en el subárbol derecho si es superior.
 * 
 * @param dato El valor que se almacenará en el nuevo nodo del árbol.
 */

template <typename T>
void Arbol<T>::insertarDato(T dato)
{
    Nodo<T>* nuevo_nodo = new Nodo<T>(dato);
    if (raiz == nullptr)
    {
        raiz = nuevo_nodo;
    }
    else
    {
        Nodo<T>* anterior = nullptr;
        Nodo<T>* inicio = raiz;

        while(inicio != nullptr)
        {
            anterior = inicio;
            inicio = (dato < inicio->valor) ? inicio->nodo_izq : inicio->nodo_der; 
        }

        if (dato < anterior->valor)
        {
            anterior->nodo_izq = nuevo_nodo;
        }
        else
        {
            anterior->nodo_der = nuevo_nodo;
        }
    }

    cout << "¡Se ha añadido con éxito el nodo con valor " << dato << "!\n";
}

/***********************************************************************/

/** 
 * @brief Cuenta el número total de nodos en el árbol.
 * @details Devuelve el número total de nodos del árbol, sean la raíz, nodos internos u hojas.
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
int Arbol<T>::contarNodos(Nodo<T>* inicio)
{
    if (inicio == nullptr)
    {
        return 0;
    }
    
    return 1 + contarNodos(inicio->nodo_izq) + contarNodos(inicio->nodo_der); ///< El nodo raíz se cuenta.
}

/** 
 * @brief Función pública que llama a contarNodos(Nodo<T>* inicio).
 */

template <typename T>
int Arbol<T>::contarNodos()
{
    return contarNodos(raiz);
}

/***********************************************************************/

/** 
 * @brief Cuenta el número de nodos hoja en el árbol.
 * @details Devuelve el número de nodos hoja (sin ningún nodos hijo) del árbol. Dado el caso
 * que no se haya insertado ningún nodo, la función devuelve 0; si solo se ha insertado el nodo
 * raíz, este cuenta como un nodo hoja al no tener ningún nodo hijo.
 * 
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
int Arbol<T>::contarHojas(Nodo<T>* inicio)
{
    if (inicio == nullptr)
    {
        return 0;
    }
    else if (inicio->nodo_izq == nullptr && inicio->nodo_der == nullptr)
    {
        return 1; ///< El nodo raíz, que es igual una hoja, se cuenta.
    }
    else
    { 
        return contarHojas(inicio->nodo_izq) + contarHojas(inicio->nodo_der);
    };
}

/** 
 * @brief Función pública que llama a contarHojas(Nodo<T>* inicio).
 */

template <typename T>
int Arbol<T>::contarHojas()
{
    return contarHojas(raiz);
}

/***********************************************************************/

/** 
 * @brief Cuenta el número de nodos internos en el árbol.
 * @details Devuelve el número de nodos internos (con al menos un nodo hijo) del árbol.
 * 
 * Con el operador lógico "OR", se pregunta si el nodo raíz es igual a nullptr (no se ha creado un nodo raiz)
 *  o si el nodo raiz tiene hijos. Si cualquiera de estas es verdad, la función devuelve 0, pues el nodo raíz
 * no es un nodo hoja.
 * 
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 * @param arbol_raiz Permite comparar "inicio" con "arbol_raiz" (es decir, "raiz" con "raiz") para evitar contar el nodo raíz.
 */

template <typename T>
int Arbol<T>::contarInternos(Nodo<T>* inicio,  Nodo<T>* arbol_raiz)
{
    if (inicio == nullptr)
    {
        return 0;
    }

    int nodos = 0;

    if ((inicio->nodo_izq != nullptr || inicio->nodo_der != nullptr) && inicio != arbol_raiz)
    {
        nodos = 1; ///< El nodo raíz, al no tener hijos, no cuenta como nodo interno.
    }

    return nodos + contarInternos(inicio->nodo_izq, arbol_raiz) + contarInternos(inicio->nodo_der, arbol_raiz); ///< El nodo raíz cuenta como nodo interno al tener al menos un nodo hijo.
}

/** 
 * @brief Función pública que llama a contarInternos(Nodo<T>* inicio).
 */

template <typename T>
int Arbol<T>::contarInternos()
{
    return contarInternos(raiz, raiz);
}

/***********************************************************************/

/** 
 * @brief Busca el nodo cuyo valor es el máximo en el árbol.
 * @details Devuelve el valor del nodo cuyo valor es el máximo en el árbol.
 * 
 * Dado que el subárbol derecho almacena valores superiores al nodo raíz, el nodo con el máximo
 * valor se encontrará en este. La función recorre el subárbol derecho hasta encontrar el último
 * nodo del lado derecho que, por consiguiente, tendrá el valor máximo.
 * 
 * Dado el caso que el árbol se encuentre vacío, se lanza una excepción.
 * 
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
T Arbol<T>::buscarMax(Nodo<T>* inicio)
{
    if (inicio == nullptr)
    {
        throw excepcion("¡El árbol se encuentra vacío!");
    }
    
    while (inicio->nodo_der != nullptr)
    {
        inicio = inicio->nodo_der; ///< Recorre el subárbol derecho.
    }

    return inicio->valor;
}

/** 
 * @brief Función pública que llama a buscarMax(Nodo<T>* inicio).
 */

template <typename T>
T Arbol<T>::buscarMax()
{
    return buscarMax(raiz);
}

/***********************************************************************/

/** 
 * @brief Suma los valores almacenados en todos los nodos del árbol.
 * @details Devuelve la suma de los valores almacenados en los nodos del árbol.
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
double Arbol<T>::sumaNodos(Nodo<T>* inicio)
{
    if (inicio == nullptr)
    {
        return 0;
    }

    return inicio->valor + sumaNodos(inicio->nodo_izq) + sumaNodos(inicio->nodo_der);
}

/***********************************************************************/

/** 
 * @brief Calcula el promedio de los valores almancenados en los nodos del árbol.
 * @details Devuelve la suma de los valores almacenados en los nodos dividida
 * por el número total de nodos en el árbol. 
 * 
 * Dado el caso que el árbol se encuentre vacío, se lanza una excepción.
 */

template <typename T>
double Arbol<T>::promedio()
{
    if (raiz == nullptr)
    {
        throw excepcion("¡El árbol se encuentra vacío!");
    }

    double suma = sumaNodos(raiz);
    double num = contarNodos();

    return suma / num;
}

/***********************************************************************/

/** 
 * @brief Imprime el contenido de los nodos por nivel.
 * @details Se organizan los nodos almacenados en el árbol dentro de una cola para mostrarlos
 * por nivel; gracias al bucle while, primero imprime el número del nivel actual, seguido de 
 * los nodos y la categoría a la que pertenecen (raíz, hoja u interno). El uso de !cola.empty()
 * asegura el no perder ningún nodo del árbol.
 * 
 * Dado el caso que el árbol se encuentre vacío, se lanza una excepción.
 */

template <typename T>
void Arbol<T>::visualizacion()
{
    if (raiz == nullptr)
    {
        throw excepcion("¡El árbol se encuentra vacío!");
    }

    queue<Nodo<T>*> cola;
    cola.push(raiz);

    int nivel = 0;

    while (!cola.empty())
    {
        int elementosNivel = cola.size();
        cout << "Nivel " << nivel << " = ";

        for (int i = 0; i < elementosNivel; i++)
        {

            Nodo<T>* nodo_actual = cola.front();
            cola.pop();

            string categoria;
            
            if (nodo_actual == raiz)
            {
                categoria = "(Raíz)";
            }
            else if (nodo_actual->nodo_izq == nullptr && nodo_actual->nodo_der == nullptr)
            {
                categoria = "(Hoja)";
            }
            else
            {
                categoria = "(Interno)";
            }

            cout << categoria << " " << nodo_actual->valor << " | ";

            if (nodo_actual->nodo_izq != nullptr)
            {
                cola.push(nodo_actual->nodo_izq);
            }

            if (nodo_actual->nodo_der != nullptr)
            {
                cola.push(nodo_actual->nodo_der);
            }
        }

        cout << endl;
        nivel++;
    }
}

/***********************************************************************/

/** 
 * @brief Imprime el recorrido del árbol en pre-orden (raíz, subárbol izquierdo, subárbol derecho).
 * @details Primero, se imprime el contenido del nodo raíz, después, se imprime el contenido de los nodos
 * correspondientes al subárbol izquierdo y, finalmente, el de los nodos en el subárbol izquierdo. 
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
void Arbol<T>::ordenPre(Nodo<T>* inicio)
{
    if (inicio != nullptr)
    {
        cout << inicio->valor << "  |  ";
        ordenPre(inicio->nodo_izq);
        ordenPre(inicio->nodo_der);
    }
} 

/***********************************************************************/

/** 
 * @brief Imprime el recorrido del árbol en in-orden (subárbol izquierdo, raíz, subárbol derecho).
 * @details Primero, imprime el contenido de los nodos correspondientes al subábol izquierdo, después,
 * se imprime el valor del raíz a tal modo que se encuentre en medio de ambos subárboles y, finalmente,
 * se imprime el contenido de los nodos en el subárbol derecho.
 * 
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
void Arbol<T>::ordenIn(Nodo<T>* inicio)
{
    if (inicio != nullptr)
    {
        ordenPre(inicio->nodo_izq);
        cout << inicio->valor << "  |  ";
        ordenPre(inicio->nodo_der);
    }
} 

/***********************************************************************/

/** 
 * @brief Imprime el recorrido del árbol en post-orden (subárbol izquierdo, subárbol derecho, raíz).
 * @details Primero, imprime el contenido de los nodos correspondientes al subábol izquierdo,
 * y continúa con los nodos en el subárbol derecho, siendo el contenido de la raíz lo último
 * que se imprime.
 * 
 * @param inicio El nodo del cual comienza el recorrido del árbol.
 */

template <typename T>
void Arbol<T>::ordenPost(Nodo<T>* inicio)
{
    if (inicio != nullptr)
    {
        ordenPre(inicio->nodo_izq);
        ordenPre(inicio->nodo_der);
        cout << inicio->valor << "  |  ";
    }
} 

/***********************************************************************/


/** 
 * @brief Imprime el contenido de los nodos en pre-orden, in-orden y post-orden.
 * @details Es la función de acceso público que utiliza la función privadas que permiten la obtención
 * del contenido del árbol en diferentes ordenes, es decir, ordenPre(Nodo<T>* inicio), ordenIn(Nodo<T>* inicio) 
 * y ordenPost(Nodo<T>* inicio).
 * 
 * Dado el caso que el árbol se encuentre vacío, se lanza una excepción.
 */

template <typename T>
void Arbol<T>::orden()
{
    if (raiz == nullptr)
    {
        throw excepcion("¡El árbol se encuentra vacío!");  
    }

    cout << "\n--- PRE-ORDEN ---\n";
    ordenPre(raiz);

    cout << "\n\n--- IN-ORDEN ---\n";
    ordenIn(raiz);

    cout << "\n\n--- POST-ORDEN ---\n";
    ordenPost(raiz);
}


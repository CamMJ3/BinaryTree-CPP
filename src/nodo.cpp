#include "nodo.h"

/** 
 * @file 
 * @brief Implementación de los constructores y métodos de la plantilla Nodo.
 */

/***********************************************************************/

/** 
 * @brief Inicializa el Nodo con un valor, estableciendo sus punteros a los nodos "izquierdo" y "derecho".
 *
 * @param dato El valor que se almacenará en el Nodo.
 * @param nuevo_izq La dirección de memoria del nodo conectado a este por el lado izquierdo.
 * @param nuevo_der La dirección de memoria del nodo conectado a este por el lado derecho.
 */

template <typename T>
Nodo<T>::Nodo(T dato, Nodo<T>* nuevo_izq, Nodo<T>* nuevo_der)
{
    valor = dato;
    nodo_izq = nuevo_izq;
    nodo_der = nuevo_der;
}

/***********************************************************************/

/** 
 * @brief Inicializa el Nodo con un valor, estableciendo sus punteros a nullptr.
 *
 * @param dato El valor que se almacenará en el Nodo.
 */

template <typename T>
Nodo<T>::Nodo(T dato)
{
    valor = dato;
    nodo_izq = nullptr;
    nodo_der = nullptr;
}

/***********************************************************************/

/** 
 * @brief Inicializa el Nodo vacío (sin valor ni referencias).
 * Es el constructor predeterminado del Nodo.
 */

template <typename T>
Nodo<T>::Nodo()
{
    valor = T();
    nodo_izq = nullptr;
    nodo_der = nullptr;
}
#pragma once
#include <string>

/** 
 * @file 
 * @brief Define la estructura de un Nodo.
 * @details Su estructura consta de un valor tipo T y dos punteros que referencian a los nodos conectados a este, es decir,
 * los nodos "izquierdo" y "derecho".
 * 
 * Este archivo define los constructures y métodos de la plantilla Nodo.
 */

template <typename T>
class Nodo
{
    public:
        T valor;
        Nodo<T>* nodo_izq;
        Nodo<T>* nodo_der;

        Nodo(T dato, Nodo<T>* nuevo_izq, Nodo<T>* nuevo_der); ///< Inicializa el Nodo con un valor, estableciendo sus punteros a los nodos "izquierdo" y "derecho".
        Nodo(T dato); ///< Inicializa el Nodo con un valor, estableciendo sus punteros a nullptr.
        Nodo(); ///< Inicializa el Nodo vacío (sin valor ni referencias); Es el constructor predeterminado del Nodo.
};

#include "../src/nodo.cpp" 
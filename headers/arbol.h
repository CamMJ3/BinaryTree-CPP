#pragma once
#include <string>
#include "nodo.h"

/** 
 * @file 
 * @brief Define la estructura del árbol binario.
 * @details Su estructura consta de un puntero que referencia a la raíz 
 * del árbol, del cual se pueden derivar nodos internos y hojas.
 * 
 * Este archivo define los constructures y métodos de la plantilla Arbol.
 */

template <typename T>
class Arbol
{
    private:
        Nodo<T>* raiz;
        void eliminarArbol(Nodo<T>* inicio); ///< Elimina los nodos asociados al árbol mediante una función recursiva.

        int contarNodos(Nodo<T>* inicio); ///< Cuenta el número total de nodos en el árbol.
        int contarHojas(Nodo<T>* inicio); ///< Cuenta el número de nodos hoja en el árbol.
        int contarInternos(Nodo<T>* inicio, Nodo<T>* arbol_raiz); ///< Cuenta el número de nodos internos en el árbol.
        double sumaNodos(Nodo<T>* inicio); ///< Suma los valores almacenados en todos los nodos del árbol.
        T buscarMax(Nodo<T>* inicio); ///< Busca el nodo cuyo valor es el máximo en el árbol.

        void ordenPre(Nodo<T>* inicio); ///< Imprime el recorrido del árbol en pre-orden (raíz, subárbol izquierdo, subárbol derecho).
        void ordenIn(Nodo<T>* inicio); ///< Imprime el recorrido del árbol en in-orden (subárbol izquierdo, raíz, subárbol derecho).
        void ordenPost(Nodo<T>* inicio); ///< Imprime el recorrido del árbol en post-orden (subárbol izquierdo, subárbol derecho, raíz).

    public:
        Arbol(); ///< Inicializa el árbol vacío.
        ~Arbol(); ///< Destruye el árbol, liberando la memoria asignada a este.

        void insertarDato(T dato); ///< Inserta un nuevo nodo con el valor de "dato" en el árbol.

        int contarNodos(); ///< Función pública que llama a contarNodos(Nodo<T>* inicio).
        int contarHojas(); ///< Función pública que llama a contarHojas(Nodo<T>* inicio).
        int contarInternos(); ///< Función pública que llama a contarInternos(Nodo<T>* inicio).
        T buscarMax(); ///< Función pública que llama a buscarMax(Nodo<T>* inicio).
        double promedio(); //< Calcula el promedio de los valores almancenados en los nodos del árbol.
        void visualizacion(); ///< Imprime el contenido de los nodos por nivel.
        void orden(); ///< Imprime el contenido de los nodos en pre-orden, in-orden y post-orden.
};

#include "../src/arbol.cpp" 
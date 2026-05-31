#pragma once
#include <exception>
#include <string>

/** 
 * @file 
 * @brief Define la clase "excepción".
 * La clase excepción permite la gestión de excepciones que pueda presentar la lista.
 *
 * @details Se define una función en excepción capaz de lanzar un mensaje de error personalizado
 * a través del parámetro "mensaje". Dentro de arbol.cpp, esta función es implementada con un
 * "throw excepcion".
 */

class excepcion : public std::runtime_error
{
    public: 
        explicit excepcion(const std::string& mensaje) : std::runtime_error(mensaje) {}
};
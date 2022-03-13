/** @file Idioma.hh
  @brief Especificación de la clase Idioma
  */
#ifndef _IDIOMA_HH_
#define _IDIOMA_HH_

#include "Tabla.hh"
#include "Treecode.hh"

#ifndef NO_DIAGRAM //ver expliación en Treecode.hh
#include <string>
#endif

/*
 *  Clase Idioma
 */
/** @class Idioma
    @brief Representa un idioma

    Contine un nombre del idioma, junto con una tabla con las letras y las
    frecuencias de cada palabra y un treecode con el arbol y los codigos de los diferentes
    caracteres del idioma.

    Sus operaciones son las de lectura de un idioma, consultar el nombre de un idioma
    escribir el treecode del idioma leido, su lista de codigos, su tabla de frecuencias,
    codificar, decodificar una string, y actualizar un idioma.

    Notad que esta clase sirve para acceder a las funciones de treecode y tabla de una
    forma senzilla y eficiente.
*/
class Idioma
{

public:

  //Constructora

  /** @brief Creadora por defecto.
      \pre <em>cierto<\em>
      \post El resultado es Igual a un Idioma vacio.
  */
  Idioma();

  /** @brief Creadora por defecto.
      \pre Nombre no es una string vacía
      \post El resultado es Igual a un Idioma con una ID.
  */
  Idioma(string nombre);

  //Modificadoras
  /** @brief Modifica el idioma
      \pre <em>cierto<\em>
      \post El resultado es un idioma con una tabla de frecuencias actualizada, y treecode tambien
  */
  void modificar();

  //Consultoras
  /** @brief Consultar el nombre del Idioma
      \pre <em>cierto<\em>
      \post Retorna la ID del Idioma
  */
  string consultar_nombre();

  //Lectura y Escritura
  /** @brief Operación de lectura
      \pre <em>cierto<\em>
      \post Se lee un Idioma vacio o con nombre
  */
  void leer_idioma();

  /** @brief Operación de escritura del arbol del idioma
      \pre Cierto
      \post Se escribe por el canal de salida el arbol del idioma en preorden y en inorden
  */
  void escribir_treecode();

  /** @brief Operación de escritura de los codigos del idioma
      \pre Cierto
      \post Retorna por el canal de salida la tabla de codigos del treecode del idioma
  */
  void escribir_xuleta();

  /** @brief Operación de escritura de la tabla de frecuencias del idioma
      \pre Cierto
      \post Se escribe por el canal de salida la tabla de frecuencias del idioma
  */
  void escribir_tabla();

  /** @brief Operación de escritura del caracter codificado
      \pre caracter != ""
      \post Si el caracter es del Idioma se escribe por el canal de salida su codificación sino informa que no es parte del idioma
  */
  void xuleta_caracter(const string& caracter);

  /** @brief Operación de escritura de la string envida codificada
      \pre string != ""
      \post Se escribe por el canal de salida la string codificas, sino informa el motivo y lugar del fallo
  */
  void codifica_palabra(const string& palabra);

  /** @brief Operación de escritura de la palabra decodificada
      \pre palabra formada unicamente por '0's y '1's
      \post Se escribe por el canal de salida la strind decodificada, sino informa el motivo y el lugar del fallo
  */
  void decodificar_palabra(const string& palabra);

private:
  /** @brief nombre del idioma*/
  string ID;
  /** @brief tabla de frecuencias del idioma*/
  Tabla freq;
  /** @brief treecode del idioma*/
  Treecode arbre;
};
#endif

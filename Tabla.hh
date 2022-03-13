/** @file Tabla.hh
  @brief Especificación de la clase Tabla
*/
#ifndef _TABLA_HH_
#define _TABLA_HH_

using namespace std;

#ifndef NO_DIAGRAM
#include <map>
#include <set>
#include <string>
#include <iostream>
#endif

/*
 * Clase Tabla
 */
/** @class Tabla
    @brief Representa la tabla de frecuencias de un idioma

    Ofrece la operación actualizar cuando se tiene que modificar la tabla de codigos
    existente con nuevos parametros. Aparte de las operaciones que lectura y escritura.

    La tabla consta de un map y un set, ordenados de manera inversa, una por las frecuencias
    y otra por los caracteres, para facilitar la creacion de un treecode y la impresión de la
    misma tabla. La ordenada por caracter solo se utiliza dentro de la clase.

    Tambien hay diversas funciones para acceder a valores del treecode, la mida, limpiarlo, etc.
*/
class Tabla {
public:

  //Constructora
  /** @brief Creadora por defecto

      Se ejecuta automaticamente al declarar una Tabla.
      \pre <em>cierto<\em>
      \post El resultado es una Tabla_de_frecuencias vacia.
  */
  Tabla();

  //Modificadoras
  /** @brief Actualiza la tabla con nuevos parametros
      \pre cierto
      \post la tabla de idiomas se actualiza con los nuevos parametros, sumandolos o anadiendolos
  */
  void actualizar();

  /** @brief Limpia la tabla de frecuencias
      \pre cierto
      \post la tabla de frecuencias "las dos" quedaran vacias;
  */
  void limpiar();

  //Consultoras
  /** @brief Retorna la primera posición de la tabla
      \pre Cierto
      \post Retorna un iterador de la primera posición de la tabla.
  */
  set<pair<int, string>>::const_iterator begin();

  /** @brief Retorna la última posición de la tabla
      \pre cierto
      \post Retorna un iterador de la última posición de la tabla.
  */
  set<pair<int, string>>::const_iterator end();

  /** @brief Retorna un caracter y una frecuencia
      \pre El iterador apunta dentro de la tabla de frecuencias
      \post Retorna el caracter y la frecuencia del iterador al que apunta de la tabla
  */
  pair<int, string> consultarit(set<pair<int, string>>::iterator it);

  /** @brief Consultora del número de parámetros de la tablas
      \pre cierto
      \post El resultado es el número de parámetros de la tabla de frecuencias
  */
  int size();

  //Escritura Y lectura
  /** @brief Operación de lectura
      \pre Cierto
      \post Se ha escrito el identificador por el párametro implícito.
  */
  void leer(int N);

  /** @brief Operación de escritura.
      \pre Cierto
      \post Escribe el contenido del parámetro implícito.
  */
  void escribir();

private:

  /** @brief Parámetros de la tabla ordenados por la frecuencia*/
  set<pair<int, string>> freq;
  /** @brief Parámetros de la tabla ordenados por caracter*/
  map<string, int> ordenados;
};
#endif

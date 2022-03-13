/** @file cj_Idiomas.hh
    @brief Especidicación de la clase cj_Idiomas
*/

#ifndef _CJ_IDIOMAS_HH_
#define _CJ_IDIOMAS_HH_

using namespace std;

#include "Idioma.hh"
#include "Tabla.hh"
#include "Treecode.hh"

/*
 *  Clase Cj_Idiomas
 */
/**@class Cj_Idiomas
    @brief Representa un conjunto de Cj_Idiomas

    Contine un map con diferentes idiomas.

    Ofrece la operaciones anadir idioma, escribir treecode, escribir tabla, escribir codigos
    codifica, decodifica y anadir_modificar que acceden a los idiomas del map para realizar
    las operaciones solicitadas, si el idioma no existe lo informa y no hace nada más.

    Notad que al utilizar esta clase el codigo principal program.cc es un codigo más facil de entender,
    y además eficiente al ver que si no se cumple algo lo informa y no hace nada más.

*/
class Cj_Idiomas
{
public:

  //Constructoras
  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Cj_Idiomas
      \pre <em>cierto<\em>
      \post El resultado es un Conjunto de Idiomas vació
  */
  Cj_Idiomas();

  //Modificadoras

  /** @brief Añade un Idioma al Conjunto de Idiomas.
      \pre El Idioma no existe en el Conjunto de Idiomas.
      \post Se añade un nuevo Idioma al conjunto
  */
  void anadir_idioma();

  /** @brief Añade o modifica el idioma.
      \pre <em>cierto<\em>
      \post Añade un Idioma si no existe, sino lo modifica añadiendo los nuevos valores.
  */
  void anadir_modificar(string& qual);

  // Escritura
  /** @brief Escribe el treecode
      \pre Cierto
      \post Se pasa el Treecode del Idioma por el canal de salida standard, si no existe el idioma se informa
  */
  void escribir_treecode(string idiom);

  /** @brief Escribe la tabla de idiom
      \pre Cierto
      \post Se pasa la tabla del Idioma por el canal de salida standard, si no existe el idioma se informa
  */
  void escribir_tabla(string idiom);

  /** @brief Escribe los codigos del idioma enviado
      \pre Cierto
      \post Se pasa la lista de codigos del Idioma por el canal de salida standard, si no existe el idioma se informa
  */
  void escribir_codigos(string idiom);

  /** @brief Codifica en el idioma selecionado
      \pre Cierto
      \post Se codifica una string que se leerá, si el idioma no existe se informa, si no se puede también
  */
  void codifica_idioma(string idiom);

  /** @brief Decodifica en el idioma seleccionado
      \pre Cierto
      \post Se decodifica un string que se leerá, si el idioma no existe se informa, si no se puede tambien
  */
  void decodificar_idioma(string idiom);

private:

  /** @brief Conjunto de Idiomas*/
  map<string, Idioma> idiomas;
};
#endif

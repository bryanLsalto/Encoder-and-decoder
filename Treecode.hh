/** @file Treecode.hh
    @brief Especificación de la clase Treecode
*/

#ifndef _TREECODE_HH_
#define _TREECODE_HH_

using namespace std;

#include "Tabla.hh"

#ifndef NO_DIAGRAM      //esto hace que el Doxyfle de la sesión no
#include "BinTree.hh"   // incluya estas clases en los diagramas modulares,
#include <map>
#include <string>
#include <set>          // mientras que el compilador de C++
#endif                  // sí que las procesa correctamente

/*
 *  Clase Treecode
 */

/** @class Treecode
    @brief Representa un arbol con las letras y frecuencias, y una lista con
    los diferentes codigos del treecode "arbol".

    Ofrece las operaciones modificar treecode y crear codigos para actualizar o
    crear de zero el arbol y su lista de codigos. También tiene la funcion imprimir;
    con sus subfunciones, escribir treecode, escribir codigos. Para escribir lo que
    se solicite segun el contenido del treecode.

    Contine un arbol con las frecuencias y las letras, aparte de una xuleta con el caracter
    y su codificación;
*/
class Treecode
{
public:

  //Constructora
  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un Treecode
      \pre <em>cierto<\em>
      \post El resultado es un arbol "Treecode" y codigos vació
      \coste Constante
  */
  Treecode();

 //Modificadoras
  /** @brief actualiza el arbol con una tabla de frecuencias
      \pre <em>cierto<\em>
      \post Cambia el arbol por uno nuevo actualizado con los nuevos datos enviados.
  */
  void modificar_treecode( Tabla& f);

  /** @brief actualiza los codigos apartir de un treecode.
      \pre  El arbol no esta vacio, y codigo y codigos sí que lo están.
      \post los codigos se han creado a partir del arbol.
  */
  void crear_codigos(const BinTree<pair<int, string>>& a, string& codigo);


  // escritura y lectura;

  /**  @brief Operación de Escritura del treecode en preorden i inorden
     \pre <em>cierto<\em>
     \post Escribe el contenido del parametro implícito por el canal de salida.
  */
  void escribir_treecode();

  /** @brief Operación de escritura de la tabla de tabla_de_codigos
      \pre Cierto
      \post se escribe por el canal de salida la tabla de codigos.
  */
  void escribir_codigos() const;

  /** @brief Operación de escritura de un caracter codificado
      \pre Cierto
      \post Si el caracter está en la lista de codigos se escribe por el canal de salida su codificación sino informa que no está
  */
  void xuleta_caracter(const string& caracter) const ;

  /** @brief  Codifica una palabra
      \pre Cierto
      \post codifica el string enviado, en caso de no ser posible lo informa y dice el caracter del string que falla
  */
  void codificar(const string& palabra);

  /** @brief Decodifica una string
      \pre Cierto
      \post decodifica la palabra enviada, si no es posible lo informa e indica donde se produce el error
  */
  void decodificar(const string& palabra);

private:

  /** @brief Arbol necesario para codificar y decodificar*/
  BinTree <pair<int, string>> arbol;
  /** @brief lista con los caractes y sus codificado según el treecode*/
  map<string, string> codigos;

  /** @brief Operación de escritura del treecode en preorden
      \pre Cierto
      \post Se escribe por el canal de salida el treecode en preorden
  */
  void preorden(const BinTree<pair<int, string>>& a);

  /** @brief Operación de escritura del treecode en inorden
      \pre Cierto
      \post Se escribe por el canal de salida el treecode en inorden
  */
  void inorden(const BinTree<pair<int, string>>& a);

  /** @brief retorna el caracter del string
      \pre S no esta vació, i >= 0
      \post Según i se seleciona el caracter del string al que apunta
  */
  void next_symbol(const string& s, int& i, string& out);

  /** @brief decodifica un caracter de la string enviada apartir de pos
      \pre i >= 0; palabra no está vacía, arbol no está vació;
      \post decodificado va añadiendo caracteres cada vez que el treecode llega a una hoja, el caracter
      es la decodificaion apartir de i hasta el final del arbol. Si el arbol no se ha recorrido
      pero palabra sí, el iterador pasa a length+5 para saber que falla.
  */
  void decodificacion(const BinTree<pair<int, string>>& a,const string& palabra, int& pos, string& decodificado);
};
#endif

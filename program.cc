/** @mainpage

    Programa que lee y actualiza idiomas formados por strings y frecuencias, aparte de esto codifica y decodifica strings, enseña su tabla de frecuencias
    y su arbol.

    El programa está formado por 4 clase, Cj_Idiomas, TreeCode, Tabla, e Idioma. para facilitar la escritura del codigo


*/

/** @file program.cc

    @brief  Programa Principal

    Suponemos que todos los datos leídos son correctos y la tabla es como mínimo de 2 caracteres
    con las frecuencias positivas, para decodificar la estring enviada esta formada únicamente por '1's
    y '0's, simpre se indica el idioma donde hacer la operación y la información necesaria que va concorde a
    lo que se solicita, por ejemplo si añade o modifica un idioma va un nombre y unas frecuencias.
*/

#include "Cj_Idiomas.hh"

using namespace std;

int main() {

    int n;
    cin >> n;
    Cj_Idiomas tuidioma;

    for (int i = n; i > 0; --i) tuidioma.anadir_idioma();

    string ordenes, qual;
    cin >> ordenes;

    while (ordenes != "fin") {
      cin >> qual;
      //qual es el nombre del idioma donde se realizará la operación
      if (ordenes == "tabla_frec") tuidioma.escribir_tabla(qual);
      else if (ordenes == "treecode") tuidioma.escribir_treecode(qual);
      else if (ordenes == "codigos") tuidioma.escribir_codigos(qual);
      else if (ordenes == "codifica") tuidioma.codifica_idioma(qual);
      else if (ordenes == "decodifica") tuidioma.decodificar_idioma(qual);
      else if (ordenes == "anadir/modificar") tuidioma.anadir_modificar(qual);

      cout << endl;
      cin >> ordenes;
    }
}

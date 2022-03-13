/** @file Idioma.cc
    @brief Código de la clase Idiomas
*/

#include "Idioma.hh"

Idioma::Idioma()
{
  ID = "";
  freq.limpiar();
}

Idioma::Idioma(string nombre)
{
  ID = nombre;
  freq.limpiar();
}

void Idioma::leer_idioma()
{
  if (ID == "") {
    string nombre;
    cin >> nombre;
    ID = nombre;
  }
  int n;
  cin >> n;
  freq.leer(n);
  arbre.modificar_treecode(freq);
}

string Idioma::consultar_nombre()
{
  return ID;
}

void Idioma::escribir_treecode()
{
  arbre.escribir_treecode();
}

void Idioma::escribir_xuleta()
{
  arbre.escribir_codigos();
}

void Idioma::escribir_tabla()
{
  freq.escribir();
}

void Idioma::xuleta_caracter(const string& caracter)
{
  arbre.xuleta_caracter(caracter);
}
void Idioma::codifica_palabra(const string& palabra)
{
  arbre.codificar(palabra);
}

void Idioma::decodificar_palabra(const string& palabra)
{
  arbre.decodificar(palabra);
}

void Idioma::modificar()
{
  freq.actualizar();
  arbre.modificar_treecode(freq);
}

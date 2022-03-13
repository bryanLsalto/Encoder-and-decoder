/** @file Cj_Idiomas.cc
    @brief Código de la clase Cj_Idiomas
*/

#include "Cj_Idiomas.hh"

Cj_Idiomas::Cj_Idiomas()
{
  map<string, Idioma > b;
  idiomas = b;
}

void Cj_Idiomas::anadir_idioma()
{
  Idioma lengua;
  lengua.leer_idioma();
  idiomas.insert(make_pair(lengua.consultar_nombre(), lengua));
}

void Cj_Idiomas::escribir_treecode(string idiom)
{
  cout << "Treecode de " << idiom << ':' << endl;
  map<string, Idioma>::iterator it = idiomas.find(idiom);
  if (it == idiomas.end()) cout << "El idioma no existe" << endl;
  else {
    it->second.escribir_treecode();
  }
}

void Cj_Idiomas::escribir_tabla(string idiom)
{
  cout << "Tabla de frecuencias de " << idiom << ':' << endl;
  map<string, Idioma>::iterator it = idiomas.find(idiom);
  if (it == idiomas.end()) cout << "El idioma no existe" << endl;
  else {
    it->second.escribir_tabla();
  }
}

void Cj_Idiomas::escribir_codigos(string idiom)
{
  string caracter;
  cin >> caracter;

  map<string, Idioma>::iterator it = idiomas.find(idiom);
  if (caracter == "todos") {
    cout << "Codigos de " << idiom << ':' << endl;
    if (it == idiomas.end()) cout << "El idioma no existe" << endl;
    else it->second.escribir_xuleta();
    }
  else {
    cout << "Codigo de " << caracter << " en " << idiom << ':'<< endl;
    if (it == idiomas.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    else it->second.xuleta_caracter(caracter);
  }
}

void Cj_Idiomas::codifica_idioma(string idiom) {
  string palabra;
  cin >> palabra;
  cout << "Codifica en " << idiom << " el texto:" << endl;
  cout << palabra <<  endl;
  map<string, Idioma>::iterator it = idiomas.find(idiom);
  if (it == idiomas.end()) cout << "El idioma no existe" << endl;
  else it->second.codifica_palabra(palabra);
}

void Cj_Idiomas::decodificar_idioma(string idiom)
{
  string palabra;
  cin >> palabra;
  cout << "Decodifica en " << idiom << " el texto:"  << endl;
  cout << palabra << endl;
  map<string , Idioma>::iterator it = idiomas.find(idiom);
  if (it == idiomas.end()) cout << "El idioma no existe" << endl;
  else it->second.decodificar_palabra(palabra);
}

void Cj_Idiomas::anadir_modificar(string& qual)
{

  map<string, Idioma>::iterator it = idiomas.find(qual);
  if (it == idiomas.end()) {
    Idioma idiomita(qual);
    idiomita.leer_idioma();
    idiomas.insert(make_pair(qual, idiomita));
    cout << "Anadido " << qual << endl;
  }
  else  {
    it->second.modificar();
    cout << "Modificado " << qual << endl;
  }
}

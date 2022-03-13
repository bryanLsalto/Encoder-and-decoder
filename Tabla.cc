/** @file Tabla.cc
    @brief Código de la clase Tabla
*/

#include "Tabla.hh"

bool operator<(pair<int, string> a, pair<int, string> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  else {
    return a.first < b.first;
  }
}

Tabla::Tabla()
{
  //Inicializada una tabla con el id de una tabla vacía
  freq = set<pair<int,string>> ();
  ordenados = map<string, int> ();
}

void Tabla::limpiar()
{
  freq.clear();
  ordenados.clear();
}

set<pair<int, string>>::const_iterator Tabla::begin()
{
  return freq.begin();
}

set<pair<int, string>>::const_iterator Tabla::end()
{
  return freq.end();
}

pair<int, string> Tabla::consultarit(set<pair<int, string>>::iterator it)
{
  return *it;
}

int Tabla::size()
{
  return freq.size();
}

void Tabla::leer(int N)
{
  //Lee todos los componentes de la tablas
  string caracter;  int frecuencia;
  for (int i = N; i > 0; --i) {
    cin >> caracter >> frecuencia;
    freq.insert(make_pair(frecuencia, caracter));
    ordenados.insert(make_pair(caracter, frecuencia));
  }
}

void Tabla::escribir()
{
  // Imprime la tabla de frecuencias que pide en una
  // de las funciones del programa principal.
  for (map<string, int>::iterator i = ordenados.begin(); i != ordenados.end(); ++i) {
      cout << i->first << ' ' << i->second << endl;
    }
}

void Tabla::actualizar()
{
  int n; cin >> n;
  string caracter; int frecuencia;

  for(int i = 0; i < n; ++i) {
    cin >> caracter >> frecuencia;

    map<string , int>::iterator itord = ordenados.find(caracter);

    if (itord == ordenados.end()) {
       freq.insert(make_pair(frecuencia, caracter));
       ordenados.insert(make_pair(caracter, frecuencia));
    }
    else  {
      frecuencia += itord->second;
      freq.erase(make_pair(itord->second, caracter));
      freq.insert(make_pair(frecuencia, caracter));
      itord->second = frecuencia;
    }
  }
}

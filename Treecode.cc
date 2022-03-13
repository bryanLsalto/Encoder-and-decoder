/** @file BinTre.cc
    @brief Código de la clase Treecode
*/

#include "Treecode.hh"

bool operator<(BinTree<pair<int, string> > a, BinTree<pair<int, string> > b) {
  if (a.value().first == b.value().first) {
    return a.value().second < b.value().second;
  }
  else {
    return a.value().first < b.value().first;
  }
}

void Treecode::next_symbol(const string& s, int& i, string& out)
{
/* Pre: i=I<s.length() es la primera posicion de un caracter de s */
/* Post: out es el caracter que comienza en s[I]; si out es normal
retorna true y i=I+1, si es especial retorna false y i=I+2 */
if (s[i]>=0) {out = string(1, s[i]); ++i;}
else {out = string(s, i, 2); i+=2;;}
}

void Treecode::crear_codigos(const BinTree<pair<int, string> >& a, string& codigo)
{
  if (a.left().empty()) {
    pair<string, string> m(a.value().second, codigo);
    codigos.insert(m);
    codigo.pop_back();
  }
  else {
    codigo += "0";
    crear_codigos(a.left(), codigo);
    codigo += "1";
    crear_codigos(a.right(), codigo);
    if (not codigo.empty()) codigo.pop_back();
  }
}

Treecode::Treecode()
{
  arbol = BinTree<pair<int, string> >();
  codigos = map<string, string>();
}

void Treecode::modificar_treecode( Tabla& f)
{

//  set<pair<int, string>>::const_iterator it = f.begin();
  set<BinTree<pair<int, string>>> arboles;
//  for (int i = 0; i < f.size(); ++i) {
  for( auto it = f.begin(); it!=f.end(); ++it){
    BinTree<pair<int, string> > arb(f.consultarit(it));
    arboles.insert(arb);
  }

  while (arboles.size() > 1) {
    set<BinTree <pair<int, string> > >::iterator it1 = arboles.begin();
    BinTree <pair<int, string> > primer = *it1;
    it1 = arboles.erase(it1);
    BinTree <pair<int, string> > segon = *it1;
    it1 = arboles.erase(it1);

    int freq = primer.value().first + segon.value().first;

    string letras;
    if (primer.value().second < segon.value().second)
      letras = primer.value().second + segon.value().second;
    else letras = segon.value().second + primer.value().second;

    BinTree<pair<int, string> > a(make_pair(freq, letras), primer, segon);

    arboles.insert(a);
  }
   set<BinTree <pair<int, string> > >::iterator it2 = arboles.begin();
   arbol = *it2;
   string codigo = "";
   codigos.clear();
   crear_codigos(arbol, codigo);
 }

 void Treecode::preorden (const BinTree<pair<int, string>>& a)
 {
   if (not a.empty()) {
     cout << a.value().second << ' ' << a.value().first << endl;
     preorden(a.left());
     preorden(a.right());
   }
 }

 void Treecode::inorden(const BinTree<pair<int, string>>& a)
 {
   if (not a.empty()) {
     inorden(a.left());
     cout << a.value().second << ' ' << a.value().first << endl;
     inorden(a.right());
   }
 }

 void Treecode::escribir_treecode()
 {
   cout << "recorrido en preorden:" << endl;
   preorden(arbol);
   cout << "recorrido en inorden:" << endl;
   inorden (arbol);
 }

 void Treecode::escribir_codigos() const
 {
   for (map<string, string>::const_iterator it = codigos.begin();
     it != codigos.end(); ++it) {
       cout << it->first << ' ' << it->second << endl;
     }
 }

void Treecode::xuleta_caracter(const string& caracter) const
{
  map<string, string>::const_iterator it = codigos.find(caracter);
  if (it == codigos.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
  else cout << it->first << ' ' << it->second << endl;
}

void Treecode::codificar(const string& palabra)
{
  int i=0;
  string codificado = "";
  bool correcto = true;
  while (i<palabra.length()){
    string aux;
    // los caracteres de s, uno a uno, se copian en aux,
    // se clasifican y se escriben
    next_symbol(palabra,i,aux);

    map<string, string>::iterator it = codigos.find(aux);
    if (it != codigos.end()) codificado += it->second;
    else {
      codificado = aux; i = palabra.length(); correcto = false;
    }
  }
  if (correcto) cout << codificado << endl;
  else cout << "El texto no pertenece al idioma; primer caracter que falla: " << codificado << endl;
}

void Treecode::decodificacion(const BinTree<pair<int, string>>& a, const string& palabra, int& pos, string& decodificado)
{
  if (a.left().empty()) {
     decodificado += a.value().second;
   }
  else {
    if (pos == palabra.length()) pos = palabra.length()+5;
    else {
      if (palabra[pos] == '0') decodificacion(a.left(), palabra, ++pos, decodificado);
      else decodificacion(a.right(), palabra, ++pos, decodificado);
    }
  }
}

void Treecode::decodificar(const string& palabra)
{
  string decodificado = "";
  int pos = 0, ultimpos_segura = 0;
  while (pos < palabra.length()) {
    ultimpos_segura = pos;
    decodificacion(arbol, palabra, pos, decodificado);
  }

  if (pos == palabra.length()+5){
    cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar:";
    cout << ' ' << ultimpos_segura << endl;
  }
  else cout << decodificado << endl;
}

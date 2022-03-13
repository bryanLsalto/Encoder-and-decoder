void esborrar_tots(const T& x) {
 /* Pre: parametre implicit = P */ /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
   resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
   referenciava a una aparicio d'x, passa a referenciar al primer element
   diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
   a la dreta el tot); en cas contrari, el punt d'interes no canvia */

   node_llista* aux;
   aux = primer_node;
   bool trobat = false;
   while (aux != null) {
     if (aux -> info == x ) {
       bool trobat = true;
       if (act = aux) act = act -> seg;
       node_llista* aux1 = aux -> ant;
       aux1 -> seg = aux -> seg;
       aux -> seg -> ant = aux1;
       delete aux;
       aux = aux -> seg;
     }
     else aux = aux -> seg;
   }
   if (not trobat) act = NULL;
 }

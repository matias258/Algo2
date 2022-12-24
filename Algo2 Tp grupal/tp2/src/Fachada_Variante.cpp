#include "Fachada_Variante.h"

Fachada_Variante::Fachada_Variante(
        Nat tamanoTab, 
        Nat cantFichas, 
        const map<Letra, Nat>& puntajes, 
        const set<vector<Letra>>& palabrasLegitimas)
{
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 1);
    for (auto it: puntajes) {
        puntos_letra[ord(it.first)] = it.second;
    }

    trie_set* legitimas = new trie_set;
    for (auto it: palabrasLegitimas) {
        legitimas->insert(it);
    }

    Variante v(tamanoTab, cantFichas, puntos_letra, legitimas); 
    variante = v;
}

Nat Fachada_Variante::tamanoTablero() const { return variante.tam_tablero(); }

Nat Fachada_Variante::fichas() const { return variante.cantidad_fichas(); }

Nat Fachada_Variante::puntajeLetra(Letra l) const { return variante.puntaje_letra(l); }

bool Fachada_Variante::palabraLegitima(const Palabra& palabra) const { return variante.es_legitima(palabra); }

Variante& Fachada_Variante::variante_interna() { return variante; }

Fachada_Variante& Fachada_Variante::operator=(const Fachada_Variante& v) {
    variante = v.variante;
    return *this;
}

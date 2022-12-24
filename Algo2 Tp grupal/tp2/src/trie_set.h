#ifndef GUGEL_TRIE_SET_H
#define GUGEL_TRIE_SET_H

#include "Letra.h"

using namespace std;

class trie_set {
public:
    /**
    CONSTRUCTOR
    * Construye un set vacio.
    **/
    trie_set();

    trie_set(trie_set&);

    trie_set& operator=(trie_set&);

    /**
    DESTRUCTOR
    **/
    ~trie_set();

    /**
    INSERT 
    * Inserta un elemento
    **/
    void insert(const vector<Letra>);

    /**
    DEFINED
    * Sirve para identificar si un elemento está definido o no.
    **/

    bool defined(const vector<Letra>);

    unsigned max_length();

private:

    struct Node {
        bool is_end;
        vector<Node*> next_nodes;
        Node() : is_end(false), next_nodes(TAMANIO_ALFABETO, NULL) {}
    };


    vector<Node*> _root;
    unsigned _max_length;
    void delete_nodes(Node*);
    Node* copy_nodes(Node*);
    bool defined_nodes(vector<Letra>, Node*);
    void insert_val(vector<Letra>, Node*);
};

#endif

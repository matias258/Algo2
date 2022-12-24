#include "trie_set.h"

trie_set::trie_set() : _root(TAMANIO_ALFABETO, NULL), _max_length(0) {}

trie_set::trie_set(trie_set &to_copy) : trie_set() { *this = to_copy; }

trie_set::Node* trie_set::copy_nodes(Node* src) {
    if (src == NULL) {
        return NULL;
    }

    Node* new_node = new Node();
    new_node->is_end = src->is_end;

    int i = 0;
    for (auto it: src->next_nodes) {
        new_node->next_nodes[i++] = copy_nodes(it);
    }

    return new_node;
}

trie_set& trie_set::operator=(trie_set &to_copy) {
    for (auto it: _root) {
        delete_nodes(it);
    }

    int i = 0;
    for (auto it: to_copy._root) {
        _root[i++] = copy_nodes(it);
    }
    _max_length = to_copy._max_length;
    return *this;
}

void trie_set::delete_nodes(Node* r) {
    if (r == NULL) {
        return;
    }

    for (auto it: r->next_nodes) {
        delete_nodes(it);
    }

    delete(r);
}

trie_set::~trie_set(){
    for (auto it: _root) {
        delete_nodes(it);
    }
}

bool trie_set::defined_nodes(vector<Letra> key_word, Node* r) {
    if (key_word.size() == 0) {
        return r->is_end;
    }

    Letra head = key_word[0];
    if (r->next_nodes[ord(head)] == NULL) {
        return false;
    } else {
        key_word.erase(key_word.begin());
        return defined_nodes(key_word, r->next_nodes[ord(head)]);
    }
}

bool trie_set::defined(const vector<Letra> key_word) {
    if (key_word.size() == 0) {
        return false;
    }

    Letra head = key_word[0];
    if (_root[ord(head)] == NULL) {
        return false;
    } else {
        //key_word.erase(key_word.begin());
        return defined_nodes(vector<Letra>(key_word.begin() + 1, key_word.end()), _root[ord(head)]);
    }
}

void trie_set::insert_val(vector<Letra> key_word, Node* r) {
    if (key_word.size() == 0) {
        r->is_end = true;
        return;
    }

    Letra head = key_word[0];
    if (r->next_nodes[ord(head)] == NULL) {
        Node* new_node = new Node();
        r->next_nodes[ord(head)] = new_node;
    }

    key_word.erase(key_word.begin());
    insert_val(key_word, r->next_nodes[ord(head)]);
}

void trie_set::insert(const vector<Letra> key_word) {
    if (key_word.size() == 0 || defined(key_word)) {
        return;
    }

    if (key_word.size() > _max_length) {
        _max_length = key_word.size();
    }

    Letra head = key_word[0];
    if (_root[ord(head)] == NULL) {
        Node* new_node = new Node();
        _root[ord(head)] = new_node;
    }

    //key_word.erase(key_word.begin());
    insert_val(vector<Letra>(key_word.begin() + 1, key_word.end()), _root[ord(head)]);
}

unsigned trie_set::max_length() {
    return _max_length;
}

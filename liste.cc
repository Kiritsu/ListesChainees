#include "liste.h"

using namespace std;

template <typename T> class Element {
public:
   // constructeur
   Element<T>(const string& s);

private:
   T valeur;

   // pointeurs vers les voisins
   Element<T>* precedent;
   Element<T>* suivant;

friend class Liste<T>;
friend class Iterateur<T>;
};


template <typename T> Element<T>::Element(const string& s) {
   valeur = s;
   precedent = suivant = NULL;
}


template <typename T> Iterateur<T>::Iterateur() {
   position = dernier = NULL;
}

template <typename T> Iterateur<T> &Iterateur<T>::operator++() {
    position = position->suivant;
    return *this;
}

template <typename T> Iterateur<T> Iterateur<T>::operator++(int) {
    Iterateur temp = *this;

    this->operator++();

    return temp;
}

template <typename T> Iterateur<T> &Iterateur<T>::operator--() {
    if (position == NULL) // fin de la liste
        position = dernier;
    else
        position = position->precedent;
    return *this;
}

template <typename T> Iterateur<T> Iterateur<T>::operator--(int) {
    Iterateur<T> temp = *this;

    this->operator--();

    return temp;
}

template <typename T> bool Iterateur<T>::operator==(const Iterateur<T> &b) const {
    return position == b.position;
}

template <typename T> bool Iterateur<T>::operator!=(const Iterateur<T> &b) const {
    return !(*this == b);
}

template <typename T> T &Iterateur<T>::operator*() const {
    return position->valeur;
}


template <typename T> Liste<T>::Liste() {
   premier = dernier = NULL;
}


template <typename T> Iterateur<T> Liste<T>::debut() const {
   Iterateur<T> it;
   it.position = premier;
   it.dernier = dernier;
   return it;
}


template <typename T> Iterateur<T> Liste<T>::fin() const {
   Iterateur<T> it;
   it.position = NULL;
   it.dernier = dernier;
   return it;
}

template <typename T> void Liste<T>::ajouter(const T &s) {
    Element<T>* element = new Element<T>(s);

    if (this->dernier == nullptr)
    {
        this->premier = element;
        this->dernier = element;
    }
    else
    {
        element->precedent = this->dernier;
        this->dernier->suivant = element;
        this->dernier = element;
    }
}

template <typename T> void Liste<T>::inserer(Iterateur<T> &pos, const T &s) {
    Element<T>* element = new Element<T>(s);

    if (pos.position->precedent == nullptr)
    {
        pos.position->precedent = element;
        element->suivant = pos.position;
        this->premier = element;
    }
    else
    {
        element->precedent = pos.position->precedent;
        element->suivant = pos.position;

        pos.position->precedent->suivant = element;
        pos.position->precedent = element;
    }
}

template <typename T> void Liste<T>::supprimer(Iterateur<T> &pos) {
    if (pos.position->suivant == nullptr)
    {
        this->dernier = pos.position->precedent;
        this->dernier->suivant = nullptr;
    }
    else if (pos.position->precedent = nullptr)
    {
        this->premier = pos.position->suivant;
        this->premier->precedent = nullptr;
    }
    else
    {
        pos.position->suivant->precedent = pos.position->precedent;
        pos.position->precedent->suivant = pos.position->suivant;
    }
}

template <typename T> Liste<T>::Liste(const Liste<T> &liste) {
    Iterateur<T> iterateur = liste.debut();
    while (iterateur.position != nullptr)
    {
        this->ajouter(*iterateur);
        iterateur++;
    }
}

template <typename T> Liste<T>::~Liste() {
    Iterateur<T> iterateur = this->debut();
    while (iterateur.position != nullptr)
    {
        delete iterateur.position;
        iterateur++;
    }
}

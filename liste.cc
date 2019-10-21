#include "liste.h"

using namespace std;

class Element {
public:
   // constructeur
   Element(const string& s);

private:
   string valeur;

   // pointeurs vers les voisins
   Element* precedent;
   Element* suivant;

friend class Liste;
friend class Iterateur;
};


Element::Element(const string& s) {
   valeur = s;
   precedent = suivant = NULL;
}


Iterateur::Iterateur() {
   position = dernier = NULL;
}


string& Iterateur::get() const {
   return position->valeur;
}


void Iterateur::suivant() {
   position = position->suivant;
}


void Iterateur::precedent() {
   if (position == NULL) // fin de la liste
      position = dernier;
   else
      position = position->precedent;
}


bool Iterateur::egal(const Iterateur& b) const {
   return position == b.position;
}


Liste::Liste() {
   premier = dernier = NULL;
}


Iterateur Liste::debut() const {
   Iterateur it;
   it.position = premier;
   it.dernier = dernier;
   return it;
}


Iterateur Liste::fin() const {
   Iterateur it;
   it.position = NULL;
   it.dernier = dernier;
   return it;
}

void Liste::ajouter(const std::string &s) {
    Element* element = new Element(s);

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

void Liste::inserer(Iterateur &pos, const std::string &s) {
    Element* element = new Element(s);

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

void Liste::supprimer(Iterateur &pos) {
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

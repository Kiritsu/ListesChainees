#ifndef LISTE_H

#define LISTE_H

#include <string>

class Element;
class Iterateur;

class Liste {
public:
   // constructeur
   Liste();

   // ajouter s a la fin de la liste
   void ajouter(const std::string& s);

   // ajouter s avant la position pos
   void inserer(Iterateur& pos, const std::string& s);

   // supprimer l'element a la position pos
   void supprimer(Iterateur& pos);

   // la premiere position
   Iterateur debut() const;

   // la fin de la liste (apres la derniere position)
   Iterateur fin() const;

private:
   // pointeurs vers le premier et le dernier element
   Element* premier;
   Element* dernier;
};


class Iterateur {
public:
   // constructeur
   Iterateur();

   // retourne la valeur dans cette position
   std::string& get() const;

   // avance a la position suivante
   void suivant();

   // recule a la position precedente
   void precedent();

   // compare deux iterateurs
   bool egal(const Iterateur& b) const;

private:
   // pointeur vers l'element courant
   Element* position;

   // pointeur vers le dernier element de la liste
   Element* dernier;

friend class Liste;
};

#endif

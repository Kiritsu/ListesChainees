#include <iostream>
#include "liste.h"

int main() {
    Liste liste;

    liste.ajouter("abc");
    liste.ajouter("xyz");

    Iterateur pos;
    pos = liste.debut();

    liste.inserer(pos, "test");
    pos++;
    liste.inserer(pos, "test2");
    liste.supprimer(pos);

    for (pos = liste.debut(); pos != liste.fin(); pos++)
    {
        std::cout << *pos << std::endl;
    }
}

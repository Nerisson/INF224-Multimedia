#include "groupe.h"

string Groupe::getNom() const{
    return name;
}


void Groupe::affiche(ostream& ostream) const{
    ostream << "I am a Groupe, my name is " << name << endl;
    for(auto lit = begin(); lit!=end(); ++lit){
        (*lit)->affiche(ostream);
    }
}

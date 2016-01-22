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

void removeMultimedia(string _nom){
    for(auto lit = begin(); lit!=end(); ++lit){
        sp_Multimedia objet = (*lit);
        if(objet->getNom().compare(_nom))
            erase(lit);
    }
}
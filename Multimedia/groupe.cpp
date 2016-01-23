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

void Groupe::removeMultimedia(string _nom){
    auto it = std::remove_if (begin(), end(), [_nom](sp_Multimedia i){
        if (_nom.compare(i->getNom())) {
            return false;
        }
        return true;
    });
    erase(it, end());
}
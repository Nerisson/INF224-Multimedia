#include "multimedia.h"


string Multimedia::getNom() const{
    return nom;
}

string Multimedia::getPathname() const{
    return pathname;
}

void Multimedia::setNom(string _nom){
    nom = _nom;
}

void Multimedia::setPathname(string _pathname){
    pathname = _pathname;
}

void Multimedia::affiche(ostream& ostream) const{
    ostream << "Nom:      " <<   nom    << endl;
    ostream << "Pathname: " << pathname << endl;
}

#include "photo.h"

void Photo::affiche(ostream& ostream) const{
    ostream << "I'm a photo, I was shot at (" << latitude << ";" << longitude << ")" << endl;
    Multimedia::affiche(ostream);
}

void Photo::executer() const{
    string s = "imagej "+getPathname()+" &";
    system(s.c_str());
}

#include "photo.h"

void Photo::affiche(ostream& ostream) const {
    ostream << "I'm a photo, I was shot at (" << latitude << ";" << longitude << ")" << "#";
    Multimedia::affiche(ostream);
}

void Photo::executer() const {
    string s = "imagej -p 1 "+getPathname()+" &";
    system(s.c_str());
}

string Photo::getClassName() const {
    return "Photo";
}

#include "video.h"

unsigned int Video::getDuree() const {
    return duree;
}

void Video::setDuree(const unsigned int _duree) {
    duree = _duree;
}

void Video::affiche(ostream& ostream) const {
    ostream << "I'm a video, my length is " << duree << "#";
    Multimedia::affiche(ostream);
}

void Video::executer() const {
    string s = "mpv "+getPathname()+" &";
    system(s.c_str());
}

string Video::getClassName() const {
    return "Video";
}
#include "film.h"

Film::~Film(){
    delete[] chapters;
}

void Film::setChapters(const unsigned int *_chapters, const unsigned int _length){
    for(unsigned int i=0; i<_length && i<MAX_LENGTH; ++i){
        chapters[i] = _chapters[i];
    }
    nbChapitres = min(MAX_LENGTH, _length);
}

unsigned int *Film::getChapters() const{
    return chapters;
}

void Film::affiche(ostream& ostream) const{
    ostream << "I'm a film!" << endl;
    Video::affiche(ostream);
    ostream << " # Chapters: " << nbChapitres << endl;
    for(unsigned int i=0; i<nbChapitres; ++i)
        ostream << "     Chapter " << i << ": " << chapters[i] << endl;
}

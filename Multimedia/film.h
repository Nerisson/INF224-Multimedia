#ifndef FILM_H
#define FILM_H

#include "video.h"

class Film:public Video{

    private:
        const unsigned int MAX_LENGTH = 30;
        unsigned int nbChapitres = 0;
        unsigned int* chapters = new unsigned int[MAX_LENGTH];


    public:
        Film(){}
        Film(string _nom, string _pathname, int _duree) : Video(_nom, _pathname, _duree), nbChapitres(0){}
        virtual ~Film();

        virtual void setChapters(const unsigned int* _chapters, const unsigned int length);
        virtual unsigned int* getChapters() const;

        virtual void affiche(ostream& ostream) const override;
};

#endif // FILM_H

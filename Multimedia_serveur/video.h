#ifndef VIDEO_H
#define VIDEO_H

#include <string>

#include "multimedia.h"

class Video:public Multimedia{

    private:
        unsigned int duree;


    public:
        Video():duree(0){}
        Video(string _nom, string _pathname, int _duree) : Multimedia(_nom, _pathname), duree(_duree){}
        virtual ~Video(){}

        virtual unsigned int getDuree() const;
        virtual void setDuree(const unsigned int _duree);

        virtual void affiche(ostream& ostream) const override;

        virtual void executer() const override;
};

#endif // VIDEO_H

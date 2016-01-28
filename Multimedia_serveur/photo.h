#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

class Photo:public Multimedia {

    private:
        double latitude;
        double longitude;


    public:
        Photo();
        Photo(string _nom, string _pathname) : Multimedia(_nom, _pathname), latitude(0), longitude(0){}
        Photo(string _nom, string _pathname, double _lat, double _long) : Multimedia(_nom, _pathname), latitude(_lat), longitude(_long){}
        virtual ~Photo(){}

        virtual void affiche(ostream& ostream) const override;

        virtual void executer() const override;
        virtual string getClassName() const override;
};

#endif // PHOTO_H

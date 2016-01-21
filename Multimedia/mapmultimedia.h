#ifndef MAPMULTIMEDIA_H
#define MAPMULTIMEDIA_H

#include <map>
#include <memory>
#include <string>

#include "multimedia.h"
#include "groupe.h"
#include "photo.h"
#include "video.h"
using namespace std;

typedef std::shared_ptr<Multimedia> sp_Multimedia;
typedef std::shared_ptr<Groupe> sp_Groupe;

class MapMultimedia {

    private:
        map<string, sp_Multimedia> list_ojb;
        map<string, sp_Groupe> list_groupes;
    public:
        MapMultimedia(){}
        ~MapMultimedia(){}

        Photo* createPhoto(string _nom, string _pathname, double _lat, double _lon);
        Video* createVideo(string _nom, string _pathname, int _duree);
        Film* createFilm(string _nom, string _pathname, int _duree);

};

#endif // MAPMULTIMEDIA_H


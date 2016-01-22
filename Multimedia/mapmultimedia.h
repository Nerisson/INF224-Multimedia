#ifndef MAPMULTIMEDIA_H
#define MAPMULTIMEDIA_H

#include <map>
#include <memory>
#include <string>
#include <algorithm>

#include "multimedia.h"
#include "groupe.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "groupe.h"


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
        
        
/*          Création                                                                       */
        sp_Multimedia createPhoto(string _nom, string _pathname, double _lat, double _lon);
        Video* createVideo(string _nom, string _pathname, int _duree);
        Film* createFilm(string _nom, string _pathname, int _duree);
        sp_Groupe createGroupe(string _nom);
        
/*          Suppression                                                                    */
        void deleteMultimedia(string _nom);

/*          Recherche                                                                      */
        const void findMultimedia(string _nom);
        

};

#endif // MAPMULTIMEDIA_H


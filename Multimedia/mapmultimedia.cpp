#include "mapmultimedia.h"

Photo* MapMultimedia::createPhoto(string _nom, string _pathname, double _lat, double _lon){
    Photo* p = new Photo(_nom, _pathname, _lat, _lon);
    sp_Multimedia photo(p);
    list_ojb[_nom] = photo;
    return p;
}

Video* MapMultimedia::createVideo(string _nom, string _pathname, int _duree){
    Video* v = new Video(_nom, _pathname, _duree);
    sp_Multimedia video(v);
    list_ojb[_nom] = video;
    return v;
}

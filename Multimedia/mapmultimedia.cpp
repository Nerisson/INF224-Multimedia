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

Film* MapMultimedia::createFilm(string _nom, string _pathname, int _duree){
    Film* f = new Film(_nom, _pathname, _duree);
    sp_Multimedia film(f);
    list_ojb[_nom] = film;
    return f;
}

Groupe* MapMultimedia::createGroupe(string _nom){
    Groupe* g = new Groupe(_nom);
    sp_Groupe groupe(g);
    list_groupes[_nom] = groupe;
    return g;
}

void MapMultimedia::deleteMultimedia(string _nom){
    auto iterator = list_ojb.find(_nom);
    
    
    
    
    for(auto it=list_groupes.begin() ; it!=list_groupes.end() ; ++it){
        cout << it->first << endl;
    }
    
    
    
    
    
    if (iterator != list_ojb.end())
        list_ojb.erase(iterator);
}

const void MapMultimedia::findMultimedia(string _nom){
    auto iterator = list_ojb.find(_nom);
    if (iterator != list_ojb.end())
        iterator->second->affiche(cout);
    else
        cout << "Not found" << endl;
}
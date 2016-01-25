#include "mapmultimedia.h"

sp_Multimedia MapMultimedia::createPhoto(string _nom, string _pathname, double _lat, double _lon){
    Photo* p = new Photo(_nom, _pathname, _lat, _lon);
    sp_Multimedia photo(p);
    list_ojb[_nom] = photo;
    return photo;
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

sp_Groupe MapMultimedia::createGroupe(string _nom){
    Groupe* g = new Groupe(_nom);
    sp_Groupe groupe(g);
    list_groupes[_nom] = groupe;
    return groupe;
}

void MapMultimedia::deleteMultimedia(string _nom){
    for(auto it=list_groupes.begin() ; it!=list_groupes.end() ; ++it){
        it->second->removeMultimedia(_nom);
    }
    auto iterator = list_ojb.find(_nom);
    if (iterator != list_ojb.end())
        list_ojb.erase(iterator);
}

void MapMultimedia::deleteGroupe(string _nom){
    auto iterator = list_groupes.find(_nom);
    if (iterator != list_groupes.end())
        list_groupes.erase(iterator);
}

sp_Multimedia MapMultimedia::findMultimedia(string _nom) const{
    auto iterator = list_ojb.find(_nom);
    if (iterator != list_ojb.end())
        return iterator->second;
    else
        return NULL;
}

sp_Groupe MapMultimedia::findGroupe(string _nom) const{
    auto iterator = list_groupes.find(_nom);
    if (iterator != list_groupes.end())
        return iterator->second;
    else
        return NULL;
}

void MapMultimedia::printMultimedia(string _nom, ostream& ostream) const{
    sp_Multimedia multi = findMultimedia(_nom);
    if (multi != NULL)
        multi->affiche(ostream);
    else
        ostream << "Not found: " << _nom << endl;
}

void MapMultimedia::printGroupe(string _nom, ostream& ostream) const{
    sp_Groupe groupe = findGroupe(_nom);
    if (groupe != NULL)
        groupe->affiche(ostream);
    else
        ostream << "Not found:"  << _nom << endl;
}

void MapMultimedia::playMultimedia(string _nom) const{
    sp_Multimedia multi = findMultimedia(_nom);
    if (multi != NULL)
        multi->executer(); 
}

void MapMultimedia::playGroupe(string _nom) const{
    sp_Groupe groupe = findGroupe(_nom);
    if (groupe != NULL)
        groupe->executerGroupe(); 
}


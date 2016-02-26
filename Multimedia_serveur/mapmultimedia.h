#ifndef MAPMULTIMEDIA_H
#define MAPMULTIMEDIA_H

/*!
 * \file mapmultimedia.h
 * \author Fabry Simon
 * \version 0.1
 */

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



/*! \class MapMultimedia
 * \brief Gestion coherente des donnees
 *  La classe aggrege les objets multimedia ainsi que les groupes
 */
class MapMultimedia {

    private:
        map<string, sp_Multimedia> list_ojb; /*!<  La liste des objets*/
        map<string, sp_Groupe> list_groupes; /*!< La liste des groupes*/
        
    public:
        /*!
         * \brief Constructeur
         * Constructeur de la classe MapMultimedia
         */
        MapMultimedia(){}
        
        /*!
         * \brief Destructeur
         */
        ~MapMultimedia(){}
        
        /*!
         * Cree une photo et l'ajoute à la liste d'objet
         * \param _nom: nom de l'objet
         * \param _pathname: chemain d'acces a la ressource multimedia
         * \param _lat: latitude de la photo a ajouter
         * \param _lon: longitude de la photo
         * \return un smart pointer pointant vers la photo cree
         */
        sp_Multimedia createPhoto(string _nom, string _pathname, double _lat, double _lon);
        
        /*!
         * Cree une video et l'ajoute a la liste d'objet
         * \param _nom: nom de l'objet
         * \param _pathname: chemain d'acces a la ressource multimedia
         * \param _duree: duree de la video a ajouter
         * \return un smart pointer pointant vers la photo cree
         */
        Video* createVideo(string _nom, string _pathname, int _duree);
        
        /*!
         * Cree un film et l'ajoute a la liste d'objet
         * \param _nom: nom de l'objet
         * \param _pathname: chemain d'acces a la ressource multimedia
         * \param _duree: duree du film a ajouter
         * \return un smart pointer pointant vers le film cree
         */
        Film* createFilm(string _nom, string _pathname, int _duree);
        
        /*!
         * Cree un groupe et l'ajoute a la liste de groupe
         * \param _nom: nom du groupe
         * \return un smart pointer pointant vers le groupe cree
         */
        sp_Groupe createGroupe(string _nom);
        
        /*!
         * Supprime un objet multimedia de la liste et des groupes auxquels il appartient
         * \param _nom: nom de l'objet a supprimer
         */
        void deleteMultimedia(string _nom);
        
        /*!
         * Supprime un groupe
         * \param _nom: nom du groupe a supprimer
         */
        void deleteGroupe(string _nom);

        /*!
         * Retourne un objet multimedia en fonction de son nom
         * \param _nom: nom de l'objet a retourner
         * \return un smart pointer vers l'objet recherche
         */
        sp_Multimedia findMultimedia(string _nom) const;
        
        /*!
         * Retourne un groupe en fonction de son nom
         * \param _nom: nom du groupe a retourner
         * \return un smart pointer vers le groupe recherche
         */
        sp_Groupe findGroupe(string _nom) const;
    
        /*!
         * Affiche l'objet multimedia designe par le nom passe en parametre
         *   dans l'output stream passe en parametre
         * \param _nom: le nom de l'objet a imprimer
         * \param ostream: le stream ou imprimer l'objet
         */
        void printMultimedia(string _nom, ostream& ostream) const;
        
        /*!
         * Affiche le groupe designe par le nom passe en parametre
         *   dans l'output stream passe en parametre
         * \param _nom: le nom du groupe a imprimer
         * \param ostream: le stream ou imprimer l'objet
         */
        void printGroupe(string _nom, ostream& ostream) const;

        /*!
         * Affiche la liste des objets multimedia contenu dans la liste dans
         * le stream passe en parametre
         * \param ostream: le stream ou imprimer l'objet
         */
        void printListMultimedia(ostream& osteam) const;

        /*!
         * Affiche la liste des groupes contenu dans la liste dans
         * le stream passe en parametre
         * \param ostream: le stream ou imprimer l'objet
         */
        void printListeGroupe(ostream& osteam) const;
        
        /*!
         * Execute l'objet multimedia passe en parametre
         * \param _nom: le nom de l'objet a executer
         */
        void playMultimedia(string _nom) const;
        
        /*!
         * Execute l'ensemble des objets du groupe dont le nom est passe en parametre
         * \param _nom: le nom du groupe a executer
         */
        void playGroupe(string _nom) const;
        
        

};

#endif // MAPMULTIMEDIA_H


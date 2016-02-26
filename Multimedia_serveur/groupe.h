#ifndef GROUPE_H
#define GROUPE_H

/*!
 * \file goupe.h
 * \author Fabry Simon
 * \version 0.1
 */

#include <list>
#include <string>
#include <memory>
#include <algorithm>

#include "multimedia.h"

using namespace std;

typedef std::shared_ptr<Multimedia> sp_Multimedia;

/*!
 * \class Groupe
 * Classe representant un groupe d'objet multimedia
 */
class Groupe:public list<sp_Multimedia> {

    private:
        string name; /*!<  Nom du groupe*/

    public:
    
        /*!
         *  \brief Constructeur
         *  Constructeur de la classe Groupe
         */
        Groupe(){}
        
        /*!
         *  \brief Constructeur
         *  Constructeur de la classe Groupe
         *  \param nom: nom du groupe
         */
        Groupe(string nom) : name(nom){}
        
        /*!
         * \return le nom du groupe
         */
        virtual string getNom() const;
        
        /*!
         *  Imprime dans le stream en parametre une representation de l'instance
         *  \param _ostream: le stream ou afficher la representation
         */
        virtual void affiche(ostream& ostream) const;
        
        /*!
         *  \brief Destructeur
         *  Destructeur de la classe Film
         */
        virtual ~Groupe(){}
        
        /*!
         * Retire le multimedia dont le nom est passe en parametre du groupe
         * \param _nom: le nom du multimedia
         */
        void removeMultimedia(string _nom);
        
        /*!
         * Appelle la fonction executer sur tous les objets du groupe
         */
        void executerGroupe() const;
};

#endif // GROUPE_H

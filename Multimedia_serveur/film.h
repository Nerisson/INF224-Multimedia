#ifndef FILM_H
#define FILM_H

/*!
 * \file film.h
 * \author Fabry Simon
 * \version 0.1
 */

#include "video.h"


/*! \class Film
 * \brief classe representant un film
 *  La classe ajoute a la classe Video la notion de chapitre
 */
class Film:public Video{

    private:
        const unsigned int MAX_LENGTH = 30; 
        unsigned int nbChapitres = 0; /*!<  Nombre de chapitre*/
        unsigned int* chapters = new unsigned int[MAX_LENGTH]; /*!< Tableau avec les duree de chapitre */


    public:
        /*!
         *  \brief Constructeur
         *  Constructeur de la classe Film
         */
        Film(){}
        
         /*!
         *  \brief Constructeur
         *  Constructeur de la classe Film
         *  \param _nom : nom du film
         *  \param _pathnom : chemin d'acces du film
         *  \param _duree : duree du film
         */
        Film(string _nom, string _pathname, int _duree) : Video(_nom, _pathname, _duree), nbChapitres(0){}
        
        /*!
         *  \brief Destructeur
         *  Destructeur de la classe Film
         */
        virtual ~Film();
        
        /*!
         *  \brief Assigne le tableau des chapitres
         *  Methode qui permet de recopier le tableau d'entier dans l'instance
         *  \param _chapters: le tableau a recopier
         *  \param length: longueur du tableau
         */
        virtual void setChapters(const unsigned int* _chapters, const unsigned int length);
        
        /*!
         *  \brief Retourne le tableau des chapitres
         *  Methode qui permet de retourner le tableau de chapitre de l'instance
         *  \return le tableau de chapitres
         */
        virtual unsigned int* getChapters() const;

        /*!
         *  Imprime dans le stream en parametre une representation de l'instance
         *  \param _ostream: le stream ou afficher la representation
         */
        virtual void affiche(ostream& ostream) const override;
        
        /*!
         *  \return le nom de la classe sous forme de string 
         */
        virtual string getClassName() const override;
};

#endif // FILM_H

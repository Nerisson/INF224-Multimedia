#ifndef PHOTO_H
#define PHOTO_H

/*!
 * \file photo.h
 * \author Fabry Simon
 * \version 0.1
 */

#include "multimedia.h"

/*!
 * \class Photo
 * Classe representant une photo
 */
class Photo:public Multimedia {

    private:
        double latitude; /*!< latitude de la photo */
        double longitude; /*<longitude de la photo */


    public:

        /*!
         * \brief Constructeur
         */
        Photo();

        /*!
         * \brief Constructeur
         * \param _nom: nom de la photo
         * \param _pathname: chemin d'acces de la photo
         */
        Photo(string _nom, string _pathname) : Multimedia(_nom, _pathname), latitude(0), longitude(0){}
        
        /*!
         * \brief Constructeur
         * \param _nom: nom de la photo
         * \param _pathname: chemin d'acces de la photo
         * \param _lat: latitude de la photo
         * \param _long: longitude de la photo
         */
        Photo(string _nom, string _pathname, double _lat, double _long) : Multimedia(_nom, _pathname), latitude(_lat), longitude(_long){}
        
        /*!
         * \brief Destructeur
         */
        virtual ~Photo(){}

        /*!
         * Imprime une representation de l'objet dans l'output stream passe en parametre
         * \param ostream: l'output stream
         */
        virtual void affiche(ostream& ostream) const override;

        /*!
         * Affiche l'objet en utilisant imagej
         */
        virtual void executer() const override;
        
        /*!
         * Methode qui retourne le nom de la classe
         * \return le nom de la classe
         */
        virtual string getClassName() const override;
};

#endif // PHOTO_H

#ifndef VIDEO_H
#define VIDEO_H

/*!
 * \file video.h
 * \author Fabry Simon
 * \version 0.1
 */

#include <string>

#include "multimedia.h"

/*!
 * \class Video
 * Classe representant une video
 */

class Video:public Multimedia{

    private:
        unsigned int duree; /*! duree de la video*/

    public:
        
        /*!
         * \brief Constructeur
         */
        Video():duree(0){}
        
        /*!
         * \brief Constructeur
         * \param _nom: nom de la video
         * \param _pathname: chemin d'acces de la video
         * \param _duree: duree de la video
         */
        Video(string _nom, string _pathname, int _duree) : Multimedia(_nom, _pathname), duree(_duree){}
        
        /*!
         * \brief Destructeur
         */
        virtual ~Video(){}
        
        /*!
         * \brief getter
         * \return la duree de la video
         */
        virtual unsigned int getDuree() const;
        
        /*!
         * \brief setter
         * Met a jour la valeur de la duree
         * \param _duree: la nouvelle duree de la video
         */
        virtual void setDuree(const unsigned int _duree);
        
        /*!
         * Imprime une representation de l'objet dans l'output stream passe en parametre
         * \param ostream: l'output stream
         */
        virtual void affiche(ostream& ostream) const override;

        /*!
         * Affiche l'objet en utilisant mpv
         */
        virtual void executer() const override;
        
        /*!
         * Methode virtuelle qui retourn le nom de la classe
         * \return le nom de la classe
         */
        virtual string getClassName() const override;
};

#endif // VIDEO_H

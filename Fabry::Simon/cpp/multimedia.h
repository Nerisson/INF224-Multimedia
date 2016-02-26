#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

using namespace std;

/*!
 * \class Multimedia
 * Classe abstraite representant un objet multimedia
 */
class Multimedia{

    private:
        string nom; /*!< Nom de l'objet*/
        string pathname; /*!< Chemin d'acces de l'objet*/

    public:
    
        /*!
         * \brief Constructeur
         */
        Multimedia(){}
        
        /*!
         * \brief Constructeur
         * \param _nom: nom de l'objet multimedia
         * \param _pathname: chemin d'acces a l'objet multimedia
         */
        Multimedia(string _nom, string _pathname) : nom(_nom), pathname(_pathname){}
        
        /*!
         * \brief Destructeur
         */
        virtual ~Multimedia(){}

        /*!
         * \brief getter
         * \return le nom de l'objet multimedia
         */
        virtual string getNom() const;

        /*!
         * \brief getter
         * \return le chemin d'acces de l'objet multimedia
         */
        virtual string getPathname() const;

        /*!
         * \brief setter
         * \param _nom: le nouveau nom de l'objet multimedia
         */
        virtual void setNom(string _nom);

        /*!
         * \brief setter
         * \param _pathname: le nouveau chemin d'acces de l'objet multimedia
         */
        virtual void setPathname(string _pathname);
        
        /*!
         * Methode virtuelle d'affichage de l'instance dans un output stream
         */
        virtual void affiche(ostream& ostream) const;

        /*!
         * Methode virtuelle d'execution d'un objet multimedia
         */
        virtual void executer() const = 0;
        
        /*!
         * Methode virtuelle qui retourn le nom de la classe
         * \return le nom de la classe
         */
        virtual string getClassName() const = 0;
};

#endif // MULTIMEDIA_H

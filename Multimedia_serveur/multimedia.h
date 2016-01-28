#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

using namespace std;

class Multimedia{

    private:
        string nom;
        string pathname;

    public:
        Multimedia(){}
        Multimedia(string _nom, string _pathname) : nom(_nom), pathname(_pathname){}
        virtual ~Multimedia(){}

        virtual string getNom() const;
        virtual string getPathname() const;
        virtual void setNom(string _nom);
        virtual void setPathname(string _pathname);

        virtual void affiche(ostream& ostream) const;

        virtual void executer() const = 0;
        virtual string getClassName() const = 0;
};

#endif // MULTIMEDIA_H

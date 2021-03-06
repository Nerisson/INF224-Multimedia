
#include<memory>


#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "groupe.h"
#include "mapmultimedia.h"

typedef std::shared_ptr<Multimedia> sp_Multimedia;

int main(int argc, char *argv[]){

    cout << endl;

    Video* v = new Video("Joe", "./VIDE0011.webm", 87);
    v->affiche(cout);

    cout << endl;

    Photo* p = new Photo("Bill", "./IMGP5539.JPG", 48.85, 2.34);
    p->affiche(cout);

    //v->executer();

    cout << endl;



    Film* f = new Film("Joe", "./VIDE0011.webm", 87);
    f->affiche(cout);
    cout << endl;
    unsigned int* d = new unsigned int[4]{1, 2, 3, 4};

    f->setChapters(d, 4);
    f->affiche(cout);

    cout << endl;

//    Multimedia* fm = f;
//    Multimedia* pm = p;

    sp_Multimedia fm(f);
    sp_Multimedia pm(p);

    Groupe* g = new Groupe("Hey!");
    g->push_back(fm);
    g->push_back(pm);
    g->affiche(cout);
    Groupe* g2 = new Groupe("Ho!");
    g2->push_back(fm);
    g2->affiche(cout);


    delete v;
//    delete p;
//    delete f;
    delete[] d;
    delete g2;
    delete g;

    cout << endl;
    cout << "##################################" << endl;
    cout << "#            Map Multimedia      #" << endl;
    cout << "##################################" << endl;
    
    
    MapMultimedia* m = new MapMultimedia();

    sp_Multimedia p2 = m->createPhoto("Photo1", "PathPhoto1", 20, 20);
    m->createVideo("Video1", "PathVideo1", 800);
    m->createVideo("Film1", "PathFilm1", 1800);
    
    sp_Groupe g21 = m->createGroupe("Group1");
    sp_Groupe g22 = m->createGroupe("Group2");
    sp_Groupe g23 = m->createGroupe("Group3");
    sp_Groupe g24 = m->createGroupe("Group4");
    
    g21->push_back(p2);
    g22->push_back(p2);
    g23->push_back(p2);
    g24->push_back(p2);
    
    
    m->printMultimedia("Photo1", cout);

    g21->affiche(cout);
    g22->affiche(cout);
    g23->affiche(cout);
    m->deleteMultimedia("Photo1");
    g21->affiche(cout);
    g22->affiche(cout);
    g23->affiche(cout);
    
    m->printMultimedia("Photo1", cout);
    
    cout << endl;
    cout << "##################################" << endl;
    cout << "             Delete Groupe" << endl;
    
    m->printGroupe("Group4", cout);
    
    m->deleteGroupe("Group4");
    
    m->printGroupe("Group4", cout);
    
    
    cout << endl;
    cout << "##################################" << endl;
    cout << "             Playing Image" << endl;
    
    
    sp_Multimedia p22 = m->createPhoto("Sample Image", "./Ressources/IMGP5539.JPG", 20, 20);
    sp_Multimedia p23 = m->createPhoto("Sample Image1", "./Ressources/IMGP5550.JPG", 20, 20);
    sp_Multimedia p24 = m->createPhoto("Sample Image2", "./Ressources/IMGP5552.JPG", 20, 20);
    
    //m->playMultimedia("Sample Image");
    g21->push_back(p22);
    g21->push_back(p23);
    g21->push_back(p24);
    
    m->playGroupe("Group1");
    
    delete m;
    
    return 0;
}


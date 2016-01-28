//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2015.
//

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "TCPServer.h"

#include "mapmultimedia.h"
using namespace std;

typedef std::shared_ptr<MapMultimedia> sp_MapMultimedia;

const int DEFAULT_PORT = 3331;

class MyApp {
  
  private:
  
    sp_MapMultimedia m;
  
  public:
    
    MyApp(){
      cout << "Hello Server" << endl;
      m = sp_MapMultimedia(new MapMultimedia());
    }
    
    sp_MapMultimedia getMap() const { return m; };
    
    /// Cette fonction est appelée chaque fois qu'il y a une requête à traiter.
    /// - 'request' contient la requête
    /// - 'response' sert à indiquer la réponse qui sera renvoyée au client
    /// - si la fonction renvoie false la connexion est close.
    //
    // Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
    // un thread par client).
    // Si le verrou 'lock' est bloqué en mode WRITE, les autres appels sont bloqués
    // jusqu'à la fin l'appel qui a bloqué le verrou.
    //
    bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response)
    {
      // mettre cette variable à true si la commande modifie les donnees du programme
      bool changeData = false;
      if (request == "delMedia" || request == "delGroups" || request == "crePhoto" ) changeData = true;
      
      // suivant le cas on bloque le verrou en mode WRITE ou en mode READ
      TCPServer::Lock lock(cnx, changeData);
      
      //cerr << "request: '" << request << "'" << endl;
      stringstream line;
      line << request;
      string command;
      string params;
      getline(line, command, ' ');
      cerr << command.size() << " " << request.size() << endl;
      
      cerr << "Commande is: " << command << endl;
      
      if(command.size() != request.size()){
        params = request.substr(command.size()+1);
        cerr << "Params are:  " << params << endl;
      } else
        cerr << "No Params provided" << endl;
      
      
      
      if(command == "listeMedia") {
        stringstream resp;
        m->printListMultimedia(resp);
        response = resp.str();
      } else if(command == "findMedia") {
        stringstream resp;
        m->findMultimedia(params)->affiche(resp);
        response = resp.str();
      } else if(command == "playMedia") {
        m->playMultimedia(params);
      } else if(command == "delMedia"){
        m->deleteMultimedia(params);
      } else {
        response = "Command not found";
      }
      
      // simule un traitement long (décommenter pour tester le verrou)
      // if (changeData) sleep(10); else sleep(5);
      
      
      // renvoyer false pour clore la connexion avec le client
      return true;
    }
};


int main(int argc, char* argv[])
{
  TCPServer * server = new TCPServer();
  MyApp * app = new MyApp();
  
  app->getMap()->createPhoto("Photo Saintelyon 1", "./Ressources/IMGP5539.JPG", 10, 10);
  app->getMap()->createPhoto("Photo Saintelyon 2", "./Ressources/IMGP5550.JPG", 20, 20);
  app->getMap()->createPhoto("Photo Saintelyon 3", "./Ressources/IMGP5552.JPG", 30, 30);
  app->getMap()->createPhoto("toto", "./Ressources/IMGP5552.JPG", 30, 30);
  
  
  
  
  server->setCallback(app, &MyApp::processRequest);
  
  int port = (argc >= 2) ? atoi(argv[1]) : DEFAULT_PORT;
  cout << "Starting Server on port " << port << endl;
  int status = server->run(port);
  
  if (status < 0) {
    cerr << "Could not start Server on port " << port << endl;
    return 1;
  }
  else return 0;
}


#ifndef H__TNOEUDLISTE__
#define H__TNOEUDLISTE__


template <class CONTENU> class TNoeudListe{
      
      public: //private:  //pr private revoir dans TListe.h pr que seul les methodes soient utilisées.  

      CONTENU *contenu; 
      
      TNoeudListe *suivant;
      TNoeudListe *precedent; 
                 
      public:
      TNoeudListe();
      ~TNoeudListe();
      TNoeudListe(CONTENU *c,TNoeudListe *prec, TNoeudListe *suiv);
      
      
      /// NOEUD LISTE
      
      //noeud
      TNoeudListe* getSuivant();
      TNoeudListe* getPrecedent();
      TNoeudListe* setSuivant(TNoeudListe *suiv);
      TNoeudListe* setPrecedent(TNoeudListe *prec);
      
      //special
      CONTENU* getElement(int i, bool b);
      bool isIn(CONTENU *element);
      
      /// REFERENCE - NOEUD
      
      //contenu
      CONTENU* getContenu();
      bool isEgal(CONTENU* c);
      
      CONTENU* getElement();
      CONTENU* setElement(CONTENU *e);
      
      /// GENERAL
      /*void run();
      void drop();
      void print();*/
      
      
      /// TYPE of CLASSE
      static char* getType(){
             return "TNoeudListe";
             }
             
             
      };   

#include "TNoeudListe.cpp"  //.tpp
#endif



      
      
      

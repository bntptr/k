#ifndef H__TNOEUDMAP__
#define H__TNOEUDMAP__


template <class KEY, class CONTENU>   //KEY <=> int/float/double
class TNoeudMap{

      private:

      CONTENU *contenu;
      KEY     key;

      TNoeudMap *suivant;
      TNoeudMap *precedent;

      public:
      TNoeudMap();
      ~TNoeudMap();
      TNoeudMap(KEY k, CONTENU *e,TNoeudMap *prec, TNoeudMap *suiv);


      /// NOEUD MAP

      //clef
      KEY     getKey(){
               return key;
               }

      KEY setKey(KEY ky){
          return key=ky;
          }

      //noeud
      TNoeudMap* getSuivant();
      TNoeudMap* getPrecedent();
      TNoeudMap* setSuivant(TNoeudMap *suiv);
      TNoeudMap* setPrecedent(TNoeudMap *prec);

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
             return "TNoeudMap";
             }


      };

#include "TNoeudMap.cpp" //.tpp

#endif







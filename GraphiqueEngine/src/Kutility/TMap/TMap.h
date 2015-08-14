#ifndef H__TMAP__
#define H__TMAP__

#include "../IReferenceStructure.h"
#include "TNoeudMap.h"

template <class KEY, class ELEMENT>
class TMap : public IReferenceStructure{

      private:

      TNoeudMap<KEY, ELEMENT> *first;
      TNoeudMap<KEY, ELEMENT> *dernier;

    // pointeur pouvant permetre de parcourir la liste depuis l'extérieur (voir methode top)
      TNoeudMap<KEY, ELEMENT> *top    ;

      public:
      TMap();
      ~TMap();


      /// TMAP

      // ajout reprise 2014

      ELEMENT* addElement(KEY clef, ELEMENT e); // pour String
      ELEMENT* addElement(KEY clef, ELEMENT *e);// pour autres objets.

      ELEMENT* get(KEY clef); // accesseur qui étrangement n'existait pas.

      //key
      KEY getKey(ELEMENT* e);

      //mode de recherche par clef
      ELEMENT* getElementFromClef(int clef);
      ELEMENT* addElementFromClef(int clef, ELEMENT *e);
      ELEMENT* subElementFromClef(int clef);


      TNoeudMap<KEY, ELEMENT>* getFirst();
      TNoeudMap<KEY, ELEMENT>* getDernier();

      TNoeudMap<KEY, ELEMENT>* setFirst(TNoeudMap<KEY, ELEMENT>* n);
      TNoeudMap<KEY, ELEMENT>* setDernier(TNoeudMap<KEY, ELEMENT>* n);

      //top [bonus]
      TNoeudMap<KEY, ELEMENT>* getTop();
      TNoeudMap<KEY, ELEMENT>* setTop(int num);         //place top a un endroit
      TNoeudMap<KEY, ELEMENT>* resetTop();              //remet top = first;
      TNoeudMap<KEY, ELEMENT>* getTopAndNext();         //renvoie le top et top = top->suivant;


      /// REFERENCE - STRUCTURE

      //element
      ELEMENT* begin();
      ELEMENT* end();

      ELEMENT* getElement(int place);
      bool isIn(ELEMENT *element);

      ELEMENT* addElement(ELEMENT *e);
      ELEMENT* subElement(ELEMENT *e);
      ELEMENT* subElement(int place);
      ELEMENT* subElementFromId(int id);
      ELEMENT* subElementFromName(std::string name);


      /// GENERAL - PARCOUR
      /*void run();
      void print();
      void vider();
      void reset();
      void drop();*/

      /// TYPE of CLASSE
      static char* getType(){
             return "TMap";
             }

      };

#include "TMap.cpp" //.tpp

#endif

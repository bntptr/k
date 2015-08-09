/**
 * http://stackoverflow.com/questions/2754650/getting-value-of-stdlistiterator-to-pointer
 */
#ifndef H__TLIST__
#define H__TLIST__

#include "../IReferenceStructure.h"
#include "TNoeudListe.h"

template <class ELEMENT> class TList : public IReferenceStructure{

      private:

      TNoeudListe<ELEMENT> *first  ;
      TNoeudListe<ELEMENT> *dernier;

      TNoeudListe<ELEMENT> *top    ;  //pointeur pouvant permetre de parcourir la liste depuis l'extérieur (voir methode top)

      public:
      TList();
      ~TList();

      /// TLISTE

      TNoeudListe<ELEMENT>* getFirst();
      TNoeudListe<ELEMENT>* getDernier();

      TNoeudListe<ELEMENT>* setFirst(TNoeudListe<ELEMENT>* n);
      TNoeudListe<ELEMENT>* setDernier(TNoeudListe<ELEMENT>* n);

      //top [bonus]
      TNoeudListe<ELEMENT>* getTop();
      TNoeudListe<ELEMENT>* setTop(int num);         //place top a un endroit
      TNoeudListe<ELEMENT>* resetTop();              //remet top = first;
      TNoeudListe<ELEMENT>* getTopAndNext();         //renvoie le top et top = top->suivant;

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
      void print();*/
      void vider();
      void reset();
      /*void drop();
      */

      /// TYPE of CLASSE
      static char* getType(){
             return "TListe";
             }


      };

#include "TListe.cpp" //.tpp

#endif



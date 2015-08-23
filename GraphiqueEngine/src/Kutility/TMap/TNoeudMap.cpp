#ifndef TPP__TNOEUDMAP__
#define TPP__TNOEUDMAP__
#include <iostream>
#include "TNoeudMap.h"


template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>::TNoeudMap(){
               suivant=NULL;
               precedent=NULL;
               contenu=NULL;
               }

template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>::~TNoeudMap(){

               }

template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>::TNoeudMap(KEY k, CONTENU *e,TNoeudMap *prec, TNoeudMap *suiv){
                this->key = k;
               suivant=suiv;
               precedent=prec;
               contenu=e;
               }

////////////////////////////////////////////////////////////////////////////////
///                           NOEUD - MAP
////////////////////////////////////////////////////////////////////////////////

// noeud
template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>* TNoeudMap<KEY, CONTENU>::getSuivant(){
             return suivant;
}

template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>* TNoeudMap<KEY, CONTENU>::getPrecedent(){
             return precedent;
}

template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>* TNoeudMap<KEY, CONTENU>::setSuivant(TNoeudMap<KEY, CONTENU> *suiv){
             return suivant = suiv ;
}

template <class KEY, class CONTENU>
TNoeudMap<KEY, CONTENU>* TNoeudMap<KEY, CONTENU>::setPrecedent(TNoeudMap<KEY, CONTENU> *prec){
             return precedent = prec ;
}


// special
template <class KEY, class CONTENU>
CONTENU* TNoeudMap<KEY, CONTENU>::getElement(int i, bool b){

         if( i == 0 ){
                   return getElement();
                   }

         if (b == true){
            return suivant->getElement(--i, b);
         }else{
               return precedent->getElement(--i, b);
         }
}

template <class KEY, class CONTENU>
bool TNoeudMap<KEY, CONTENU>::isIn(CONTENU *element){
     if( contenu->isEgal(element) ){
         return true;
         }

     if( suivant != NULL ){
         return suivant->isIn(element);
         }

     return false;
     }

////////////////////////////////////////////////////////////////////////////////
///                          REFERENCE - NOEUD
////////////////////////////////////////////////////////////////////////////////


template <class KEY, class CONTENU>
CONTENU* TNoeudMap<KEY, CONTENU>::getContenu(){
         return contenu;
         }

template <class KEY, class CONTENU>
bool TNoeudMap<KEY, CONTENU>::isEgal(CONTENU* e){
     if(contenu!=NULL)
        return contenu->isEgal(e);
     return false;
}

template <class KEY, class CONTENU>
CONTENU* TNoeudMap<KEY, CONTENU>::getElement(){
             return contenu;
}

template <class KEY, class CONTENU>
CONTENU* TNoeudMap<KEY, CONTENU>::setElement(CONTENU *e){
             return contenu = e ;
}

////////////////////////////////////////////////////////////////////////////////
///                           GENERAL - PARCOUR
////////////////////////////////////////////////////////////////////////////////


 /*
template <class KEY, class CONTENU>
void TNoeudMap<KEY, CONTENU>::run(){
     if(contenu!=NULL)
        contenu->run();
}


template <class KEY, class CONTENU>
void TNoeudMap<KEY, CONTENU>::drop(){
     //drop
}


template <class KEY, class CONTENU>
void TNoeudMap<KEY, CONTENU>::print(){
     //print
}
     */

#endif




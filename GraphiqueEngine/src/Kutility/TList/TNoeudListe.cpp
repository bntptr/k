#ifndef TPP__TNOEUDLISTE__
#define TPP__TNOEUDLISTE__
#include <iostream>
#include "TNoeudListe.h"


template <class CONTENU> TNoeudListe<CONTENU>::TNoeudListe(){
               suivant=NULL;
               precedent=NULL;
               contenu=NULL;
               }

template <class CONTENU> TNoeudListe<CONTENU>::~TNoeudListe(){

               }

template <class CONTENU> TNoeudListe<CONTENU>::TNoeudListe(CONTENU *ng,TNoeudListe *prec, TNoeudListe *suiv){
               suivant=suiv;
               precedent=prec;
               contenu=ng;
               }
               

////////////////////////////////////////////////////////////////////////////////
///                           NOEUD - LISTE
////////////////////////////////////////////////////////////////////////////////

// noeud
template <class CONTENU>
TNoeudListe<CONTENU>* TNoeudListe<CONTENU>::getSuivant(){
             return suivant;
}

template <class CONTENU>
TNoeudListe<CONTENU>* TNoeudListe<CONTENU>::getPrecedent(){
             return precedent;
}

template <class CONTENU>
TNoeudListe<CONTENU>* TNoeudListe<CONTENU>::setSuivant(TNoeudListe *suiv){
             return suivant = suiv ;
}

template <class CONTENU>
TNoeudListe<CONTENU>* TNoeudListe<CONTENU>::setPrecedent(TNoeudListe *prec){
             return precedent = prec ;
}
         

// special
template <class CONTENU>
CONTENU* TNoeudListe<CONTENU>::getElement(int i, bool b){
         
         if( i == 0 ){
                   return getElement();
                   }
                   
         if (b == true){
            return suivant->getElement(--i, b);
         }else{
               return precedent->getElement(--i, b);
         }
}

template <class CONTENU> 
bool TNoeudListe<CONTENU>::isIn(CONTENU *element){
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

template <class CONTENU> 
CONTENU* TNoeudListe<CONTENU>::getContenu(){
             return contenu;
}
             
template <class CONTENU> 
bool TNoeudListe<CONTENU>::isEgal(CONTENU* c){
     if(contenu!=NULL)
     return contenu->isEgal(c);
     return false;
}

template <class CONTENU> 
CONTENU* TNoeudListe<CONTENU>::getElement(){
             return contenu;
}

template <class CONTENU> 
CONTENU* TNoeudListe<CONTENU>::setElement(CONTENU *e){
             return contenu = e ;
}


////////////////////////////////////////////////////////////////////////////////
///                           GENERAL - PARCOUR
////////////////////////////////////////////////////////////////////////////////

    /* 
template <class CONTENU> 
void TNoeudListe<CONTENU>::run(){
     if(contenu!=NULL)
     contenu->run();
}
     
     
template <class CONTENU> 
void TNoeudListe<CONTENU>::drop(){
     //drop
}
     
     
template <class CONTENU> 
void TNoeudListe<CONTENU>::print(){
             
             std::cout<<"["<<contenu<<"]";  //l'adresse mémoire
             if( contenu != NULL){
                 contenu->print();
                 }else{
                       std::cout<<"[VIDE]\n";
                       }
             if( suivant != NULL ){
                 suivant->print();
                 }else{
                       std::cout<<"[end]\n";
                       }
             
}*/


     
#endif




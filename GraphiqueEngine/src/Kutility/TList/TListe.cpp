/**Pour une utilisation en liste, file, et pile*/
#ifndef TPP__TLISTE__
#define TPP__TLISTE__
#include <iostream>
#include <string>
//#include "TString.h"
#include "TListe.h"
#include "TNoeudListe.h"


template <class ELEMENT>
TListe<ELEMENT>::TListe(){
               first=NULL;
               resetSize();
               std::cout<<"\nensd> TListe> Constructeur ";
               }

template <class ELEMENT>
TListe<ELEMENT>::~TListe(){

               }



////////////////////////////////////////////////////////////////////////////////
///                          PERSONNALISE - LISTE
////////////////////////////////////////////////////////////////////////////////


template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::getFirst(){
                      return first ;
}


template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::getDernier(){
                      return dernier ;
}


template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::setFirst(TNoeudListe<ELEMENT>* n){
                      return first = n ;
}


template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::setDernier(TNoeudListe<ELEMENT>* n){
                      return dernier = n ;
}


//top [bonus]
template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::getTop(){

         return NULL;
}

template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::setTop(int num){

         return NULL;
}

template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::resetTop(){

         return NULL;
}

template <class ELEMENT>
TNoeudListe<ELEMENT>* TListe<ELEMENT>::getTopAndNext(){

         return NULL;
}


////////////////////////////////////////////////////////////////////////////////
///                          REFERENCE - STRUCTURE
////////////////////////////////////////////////////////////////////////////////

template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::begin(){
         if(first == NULL)
                  return NULL;
         else
             return first->getElement();
             }

template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::end(){
         if(dernier == NULL)
                  return NULL;
         else
             return dernier->getElement();
             }


template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::getElement(int i){
       if(( i >= getSize() )||(first == NULL)){
           return NULL;
           }

       if( i < getSize()/2 ){
           return first->getElement(i, true);
           }else{
                 return dernier->getElement(getSize()-(i+1), false);
                 }

}

template <class ELEMENT>
bool TListe<ELEMENT>::isIn(ELEMENT *element){
         return first->isIn(element);
         }



template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::addElement(ELEMENT *newu){

         if( newu == NULL ){
           return NULL;
           }

          if( first == NULL ){
              first = new TNoeudListe<ELEMENT>(newu,NULL,NULL);
              setSize(1);
              dernier = first ;
              return dernier->getElement();
              }

          //ajoute en fin de liste
          TNoeudListe<ELEMENT> *nl = new TNoeudListe<ELEMENT>(newu,dernier,NULL);
          addSize(1);
          dernier->setSuivant(nl);
          dernier = nl ;

          return dernier->getElement();
}


template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::subElement(ELEMENT *ancu){

          if( ancu == NULL ){
              return NULL;
              }

          if( first == NULL ){
              return NULL;
              }

          if( ancu->isEgal(first->getElement())){
              TNoeudListe<ELEMENT> *nl = first->getSuivant();
              ELEMENT* e = first->getElement();
              delete first; //? juste le noeud pas l'élément
              addSize(-1);
              first = nl;
              if( getSize() == 0 ){
                  dernier = NULL;
                  }
              return e;
              }

          if( ancu->isEgal(dernier->getElement())){
              TNoeudListe<ELEMENT> *nl = dernier->getPrecedent();
              ELEMENT* e = dernier->getElement();
              delete dernier; //? juste le noeud pas l'élément
              addSize(-1);
              dernier = nl;
              return e;
              }


          TNoeudListe<ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          if( nl->isEgal(ancu) == true ){
                              TNoeudListe<ELEMENT> *prec=nl->getPrecedent();
                              TNoeudListe<ELEMENT> *suiv=nl->getSuivant();
                              if(prec!=NULL)
                                            prec->setSuivant(suiv);
                              if(suiv!=NULL)
                                            suiv->setPrecedent(prec);
                              ELEMENT* e = nl->getElement();
                              delete nl; //?
                              addSize(-1);
                              return e;
                              }
                          nl=nl->suivant;
                          }
          setSize(j);

    return NULL;
}

template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::subElement(int place){

          if( (getSize() >= place)||( 0 > place ) ){
              return NULL;
              }

          if( first == NULL ){
              return NULL;
              }


          TNoeudListe<ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          if( j == place ){
                              TNoeudListe<ELEMENT> *prec=nl->getPrecedent();
                              TNoeudListe<ELEMENT> *suiv=nl->getSuivant();
                              if(prec!=NULL)
                                            prec->setSuivant(suiv);
                              if(suiv!=NULL)
                                            suiv->setPrecedent(prec);
                              ELEMENT* e = nl->getElement();
                              delete nl; //?
                              addSize(-1);
                              return e;
                              }
                          nl=nl->suivant;
                          }
          setSize(j);

    return NULL;
}

template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::subElementFromId(int id){


          if( first == NULL ){
              return NULL;
              }


          TNoeudListe<ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          if( nl->getElement()->getId() == id ){
                              TNoeudListe<ELEMENT> *prec=nl->getPrecedent();
                              TNoeudListe<ELEMENT> *suiv=nl->getSuivant();
                              if(prec!=NULL)
                                            prec->setSuivant(suiv);
                              if(suiv!=NULL)
                                            suiv->setPrecedent(prec);
                              ELEMENT* e = nl->getElement();
                              delete nl; //?
                              addSize(-1);
                              return e;
                              }
                          nl=nl->suivant;
                          }
          setSize(j);

    return NULL;
}

template <class ELEMENT>
ELEMENT* TListe<ELEMENT>::subElementFromName(std::string nom){

          /*if( nom == NULL ){
              return NULL;
              }

          if( first == NULL ){
              return NULL;
              }


          TNoeudListe<ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          /// ATTENTION ICI STRING <=> char*   donc a mettre au clair
                          //if( nom.isEgal( nl->getElement().getName() ) == true ){
                                if(true){//provisoire mais veut rien dire
                              TNoeudListe<ELEMENT> *prec=nl->getPrecedent();
                              TNoeudListe<ELEMENT> *suiv=nl->getSuivant();
                              if(prec!=NULL)
                                            prec->setSuivant(suiv);
                              if(suiv!=NULL)
                                            suiv->setPrecedent(prec);
                              ELEMENT* e = nl->getElement();
                              delete nl; //?
                              addSize(-1);
                              return e;
                              }
                          nl=nl->suivant;
                          }
          setSize(j);*/

    return NULL;
}

////////////////////////////////////////////////////////////////////////////////
///                           GENERAL - PARCOUR
////////////////////////////////////////////////////////////////////////////////
/*

template <class ELEMENT>
void TListe<ELEMENT>::run(){
    //parcour la liste et run chaque Element
    TNoeudListe<ELEMENT> *noeud=first;
    while(noeud!=NULL)
    {
                        noeud->run();
                        noeud=noeud->getSuivant();
    }
}

template <class ELEMENT>
void TListe<ELEMENT>::print(){
     std::cout<<"\n>print [TListe<"<<ELEMENT::getType()<<">]["<<getSize()<<"]";
     if( first != NULL ){
         std::cout<<"[debut]\n";
         first->print();
     }else{
           std::cout<<"[liste vide]\n";
           }

     }

*/
template <class ELEMENT>
void TListe<ELEMENT>::vider(){
    while(first!=NULL){
                       subElement(1); //1 parce que 0<=> vide
                       std::cout<<"\nBoucleWhile in TListe::vider()";
                       }
    resetSize();
    first=NULL;
}


template <class ELEMENT>
void TListe<ELEMENT>::reset(){
     //delete this->suivant;              //inutil si je ne veux pas le détruire
     this->first=NULL;
     this->resetSize();
     }
/*
template <class ELEMENT>
void TListe<ELEMENT>::drop(){
     std::cout<<">drop";
}

*/

#endif











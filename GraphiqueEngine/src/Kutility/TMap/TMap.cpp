#ifndef TPP__TMAP__
#define TPP__TMAP__
#include <iostream>
#include "TMap.h"  //si pas compilateur signal une erreur
#include "TNoeudMap.h"

template <class KEY, class ELEMENT>
TMap<KEY, ELEMENT>::TMap(){
               first=NULL;
               resetSize();
               }

template <class KEY, class ELEMENT>
TMap<KEY, ELEMENT>::~TMap(){

               }



////////////////////////////////////////////////////////////////////////////////
///                          PERSONNALISE - MAP
////////////////////////////////////////////////////////////////////////////////

//key
template <class KEY, class ELEMENT>
KEY TMap<KEY, ELEMENT>::getKey(ELEMENT* e){

    if( e == NULL)
        return NULL;

    TNoeudMap<KEY, ELEMENT> *noeud=first;
    while(noeud != NULL)
    {
                        ELEMENT *ne = noeud->getElement();
                        if(ne != NULL){
                              if( ne->isEgal(e) == true){
                                  return noeud->getClef();
                                  }
                        }
                        noeud=noeud->getSuivant();
    }

    return NULL;
}


//top [bonus]
template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::getTop(){

         return NULL;
}

template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::setTop(int num){

         return NULL;
}

template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::resetTop(){

         return NULL;
}

template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::getTopAndNext(){

         return NULL;
}



template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::getFirst(){
                      return first ;
}


template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::getDernier(){
                      return dernier ;
}


template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::setFirst(TNoeudMap<KEY, ELEMENT>* n){
                      return first = n ;
}


template <class KEY, class ELEMENT>
TNoeudMap<KEY, ELEMENT>* TMap<KEY, ELEMENT>::setDernier(TNoeudMap<KEY, ELEMENT>* n){
                      return dernier = n ;
}


////////////////////////////////////////////////////////////////////////////////
///                          REFERENCE - STRUCTURE
////////////////////////////////////////////////////////////////////////////////

template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::begin(){
         if(first == NULL)
                  return NULL;
         else
             return first->getElement();
             }

template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::end(){
         if(dernier == NULL)
                  return NULL;
         else
             return dernier->getElement();
             }


template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::getElement(int i){
         if( i >= getSize() ){
           return NULL;
           }

       if( i < getSize()/2 ){
           return first->getElement(i, true);
           }else{
                 return dernier->getElement(getSize()-(i+1), false);
                 }
}

template <class KEY, class ELEMENT>
bool TMap<KEY, ELEMENT>::isIn(ELEMENT *element){
         return first->isIn(element);
         }


template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::addElement(ELEMENT *newu){

         if( newu == NULL ){
           return NULL;
           }

          if( first == NULL ){
              first = new TNoeudMap<KEY, ELEMENT>(newu,NULL,NULL);
              setSize(1);
              dernier = first ;
              return dernier->getElement();
              }

          //ajoute en fin de liste
          TNoeudMap<KEY, ELEMENT> *nl = new TNoeudMap<KEY, ELEMENT>(newu,dernier,NULL);
          addSize(1);
          dernier->setSuivant(nl);
          dernier = nl ;

          return dernier->getElement();
}


template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::subElement(ELEMENT *ancu){

          if( ancu == NULL ){
              return NULL;
              }

          if( first == NULL ){
              return NULL;
              }

          if( ancu->isEgal(first->getElement())){
              TNoeudMap<KEY, ELEMENT> *nl = first->getSuivant();
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
              TNoeudMap<KEY, ELEMENT> *nl = dernier->getPrecedent();
              ELEMENT* e = dernier->getElement();
              delete dernier; //? juste le noeud pas l'élément
              addSize(-1);
              dernier = nl;
              return e;
              }


          TNoeudMap<KEY, ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          if( nl->isEgal(ancu) == true ){
                              TNoeudMap<KEY, ELEMENT> *prec=nl->getPrecedent();
                              TNoeudMap<KEY, ELEMENT> *suiv=nl->getSuivant();
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

template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::subElement(int place){

          if( (getSize() >= place)||( 0 > place ) ){
              return NULL;
              }

          if( first == NULL ){
              return NULL;
              }


          TNoeudMap<KEY, ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          if( j == place ){
                              TNoeudMap<KEY, ELEMENT> *prec=nl->getPrecedent();
                              TNoeudMap<KEY, ELEMENT> *suiv=nl->getSuivant();
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


template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::subElementFromId(int id){


          if( first == NULL ){
              return NULL;
              }


          TNoeudMap<KEY, ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          if( nl->getElement()->getId() == id ){
                              TNoeudMap<KEY, ELEMENT> *prec=nl->getPrecedent();
                              TNoeudMap<KEY, ELEMENT> *suiv=nl->getSuivant();
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

template <class KEY, class ELEMENT>
ELEMENT* TMap<KEY, ELEMENT>::subElementFromName(std::string nom){

          /*if( nom == NULL ){
              return NULL;
              }

          if( first == NULL ){
              return NULL;
              }


          TNoeudMap<KEY, ELEMENT> *nl=first;
          int j=0;

          while(nl!=NULL){
                          j++;
                          //if( nom.isEgal(nl->getElement().getName()) ){
                                if( true ){  //provisoire mais sans aucun sens hormis compiler
                              TNoeudMap<KEY, ELEMENT> *prec=nl->getPrecedent();
                              TNoeudMap<KEY, ELEMENT> *suiv=nl->getSuivant();
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
///                          GENERAL - PARCOUR
////////////////////////////////////////////////////////////////////////////////
/*

template <class KEY, class ELEMENT>
void TMap<KEY, ELEMENT>::run(){
    //parcour la liste et run chaque Element
    TNoeudMap<KEY, ELEMENT> *noeud=first;
    while(noeud!=NULL)
    {
                        noeud->run();
                        noeud=noeud->getSuivant();
    }
}

template <class KEY, class ELEMENT>
void TMap<KEY, ELEMENT>::print(){
    //parcour la map et affiche chaque element et sa clef
    std::cout<<"\n>print [TMap<KEY,"<<ELEMENT::getType()<<">]["<<getSize()<<"]";
     if( first != NULL ){
         std::cout<<"[debut]\n";
         first->print();
     }else{
           std::cout<<"[liste vide]\n";
           }

}

template <class KEY, class ELEMENT>
void TMap<KEY, ELEMENT>::vider(){
    while(first!=NULL){
                       subElement(1); //1 parce que 0<=> vide
                       std::cout<<"\nBoucleWhile in TMap::vider()";
                       }
    resetSize();
    first=NULL;
}

template <class KEY, class ELEMENT>
void TMap<KEY, ELEMENT>::reset(){
     //delete this->suivant;              //inutil si je ne veux pas le détruire
     this->first=NULL;
     this->resetSize();
     }


template <class KEY, class ELEMENT>
void TMap<KEY, ELEMENT>::drop(){
     std::cout<<">drop";
}*/


#endif











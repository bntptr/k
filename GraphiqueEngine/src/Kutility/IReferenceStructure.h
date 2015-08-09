#ifndef H__IREFERENCESTRUCTURE__
#define H__IREFERENCESTRUCTURE__

class IReferenceStructure {
      private:
             int _size ;

          public:
          IReferenceStructure(){};
          ~IReferenceStructure(){};

          //size
          int size(){
              return _size;
          }

          int getSize(){
              return _size;
          }

          int setSize(int a){
              return _size = a ;
          }

          int addSize(int a){
              return _size += a ;
          }

          int resetSize(){
              return _size = 0 ;
          }


          /// REFERENCE - STRUCTURE
          /** METHODES RETROUVE CHEZ TOUTES MAIS PAS ECRITE CAR != CHEZ CHACUNE
          //element
          ELEMENT* begin();
          ELEMENT* end();

          ELEMENT* getElement(int place);
          bool isIn(ELEMENT *element);

          ELEMENT* addElement(ELEMENT *e);
          ELEMENT* subElement(ELEMENT *e);
          ELEMENT* subElement(int place);
          ELEMENT* subElementFromId(int id);
          ELEMENT* subElementFromeName(String name);
          */

      };

#endif


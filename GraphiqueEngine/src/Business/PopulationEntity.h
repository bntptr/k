#ifndef POPULATIONENTITY_H
#define POPULATIONENTITY_H

#include "IPopulationEntity.h"

namespace graphique
{
    class PopulationEntity : public IPopulationEntity
    {
        protected:
            std::list<ICharacterEntity*>* characterList;

        public:
            PopulationEntity(){
                this->characterList = new std::list<ICharacterEntity*>();
            };
            ~PopulationEntity(){};

            std::list<ICharacterEntity*>* getCharacterList() {
                return this->characterList;
            }
            /*L.push_back(0);              // Insert a new element at the end
            L.push_front(0);             // Insert a new element at the beginning
            L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place before second argument)
            L.push_back(5);
            L.push_back(6);

            list<int>::iterator i;

            for(i=L.begin(); i != L.end(); ++i) cout << *i << " ";
                cout << endl;*/
            };
} // business

#endif

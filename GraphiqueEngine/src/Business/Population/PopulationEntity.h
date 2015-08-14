#ifndef POPULATIONENTITY_H
#define POPULATIONENTITY_H

#include "IPopulationEntity.h"
#include "Character/CharacterFactory.h"

namespace business
{
    class PopulationEntity : public IPopulationEntity
    {
        protected:
            IPopulationEntity *thisInstance;
            //std::list<ICharacterEntity*>* characterList;
            TList<ICharacterEntity>* characterList;

        public:
            PopulationEntity(){
                this->thisInstance = this;
                //this->characterList = new std::list<ICharacterEntity*>();
                this->characterList = new TList<ICharacterEntity>();
            };
            ~PopulationEntity(){};

            //std::list<ICharacterEntity*>* getCharacterList() {
            TList<ICharacterEntity>* getCharacterList() {
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

            IPopulationEntity* addCharacter(
                const Vector3d & position,
                Vector3d rotation,
                Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                ICharacterEntity *entity = business::CharacterFactory::createEntity(
                    position,
                    rotation,
                    scale,
                    texture,
                    mesh
                );
                //this->characterList->push_back(entity);
                this->characterList->addElement(entity);
                return this->thisInstance;
            }
    };
} // business

#endif

#ifndef BUSINESSSERVICE_H
#define BUSINESSSERVICE_H

#include "BusinessInterface.h"
#include "BusinessFactory.h"

namespace business
{
    class BusinessService : public BusinessInterface
    {
        protected:
            IBusinessEntity* entity;
        public:
            BusinessService(){
                this->entity = BusinessFactory::createEntity();
            };
            ~BusinessService(){};

            IBusinessEntity* loadBusinessEntity(){
                return this->entity;
            }
            bool loadSceneScreen();
            bool loadObjectFromSceneScreen();
            bool loadTerrainFromSceneScreen();
    };
} // business

#endif

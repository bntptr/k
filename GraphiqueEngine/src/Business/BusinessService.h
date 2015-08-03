#ifndef BUSINESSSERVICE_H
#define BUSINESSSERVICE_H

#include "BusinessInterface.h"

namespace graphique
{
    class BusinessService : public BusinessInterface
    {
        public:
            BusinessService(){};
            ~BusinessService(){};

            BusinessEntity* loadBusinessEntity(){
                BusinessEntity *entity = new BusinessEntity();
                return entity;
            }
            bool loadSceneScreen();
            bool loadObjectFromSceneScreen();
            bool loadTerrainFromSceneScreen();
    };
} // business

#endif

#ifndef ACCESSORYVIEW_H
#define ACCESSORYVIEW_H

#include "IAccessory.h"

namespace graphique
{
    class Accessory : public IAccessory
    {
        protected:
            irr::IrrlichtDevice *device;
            IAccessoryEntity *entity;

        public:
            Accessory(irr::IrrlichtDevice *device, IAccessoryEntity *entity){
                this->device = device;
                this->entity = entity;
            };
            ~Accessory(){};

            bool draw() {
            }
    };
} // graphique

#endif


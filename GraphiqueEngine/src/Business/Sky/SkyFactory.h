#ifndef SKY_FACTORY_H
#define SKY_FACTORY_H

#include "SkyEntity.h"

namespace business
{
    class SkyFactory
    {
        public:
            static ISkyEntity* createEntity() {
                return new SkyEntity();
            }

            static ISkyEntity* createEntity(
                int id,
                ETEXTURE textureDome,
                ETEXTURE textureBoxUp,
                ETEXTURE textureBoxDn,
                ETEXTURE textureBoxLf,
                ETEXTURE textureBoxRt,
                ETEXTURE textureBoxFt,
                ETEXTURE textureBoxBk
            ) {
                return new SkyEntity(
                    id,
                    textureDome,
                    textureBoxUp,
                    textureBoxDn,
                    textureBoxLf,
                    textureBoxRt,
                    textureBoxFt,
                    textureBoxBk
                );
            }
    };
} // business

#endif

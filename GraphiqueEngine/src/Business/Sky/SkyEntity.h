#ifndef SKYENTITY_H
#define SKYENTITY_H

#include "ISkyEntity.h"

namespace business
{
    class SkyEntity : public ISkyEntity
    {
        protected:
            ISkyEntity *thisInstance;
            int id;
            ETEXTURE textureDome;
            ETEXTURE textureBoxUp;
            ETEXTURE textureBoxDn;
            ETEXTURE textureBoxLf;
            ETEXTURE textureBoxRt;
            ETEXTURE textureBoxFt;
            ETEXTURE textureBoxBk;

        public:
            SkyEntity(
                int id,
                ETEXTURE textureDome,
                ETEXTURE textureBoxUp,
                ETEXTURE textureBoxDn,
                ETEXTURE textureBoxLf,
                ETEXTURE textureBoxRt,
                ETEXTURE textureBoxFt,
                ETEXTURE textureBoxBk
            ){
                this->thisInstance = this;
                this->id = id;
                this->textureDome = textureDome;
                this->textureBoxUp = textureBoxUp;
                this->textureBoxDn = textureBoxDn;
                this->textureBoxLf = textureBoxLf;
                this->textureBoxRt = textureBoxRt;
                this->textureBoxFt = textureBoxFt;
                this->textureBoxBk = textureBoxBk;
            };
            ~SkyEntity(){};

            ETEXTURE getTextureSkyDome() {
                return this->textureDome;
            }

            ETEXTURE getTextureSkyBoxUp() {
                return this->textureBoxUp;
            }

            ETEXTURE getTextureSkyBoxDn() {
                return this->textureBoxDn;
            }

            ETEXTURE getTextureSkyBoxLf() {
                return this->textureBoxLf;
            }

            ETEXTURE getTextureSkyBoxRt() {
                return this->textureBoxRt;
            }

            ETEXTURE getTextureSkyBoxFt() {
                return this->textureBoxFt;
            }

            ETEXTURE getTextureSkyBoxBk() {
                return this->textureBoxBk;
            }
    };
} // business

#endif

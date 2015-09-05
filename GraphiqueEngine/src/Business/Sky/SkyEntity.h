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
                ETEXTURE textureBoxBk,
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

            ETEXTURE getTextureSkyDome()=0;
            ETEXTURE getTextureSkyBoxUp()=0;
            ETEXTURE getTextureSkyBoxDn()=0;
            ETEXTURE getTextureSkyBoxLf()=0;
            ETEXTURE getTextureSkyBoxRt()=0;
            ETEXTURE getTextureSkyBoxFt()=0;
            ETEXTURE getTextureSkyBoxBk()=0;
    };
} // business

#endif

#ifndef ISKYENTITY_H
#define ISKYENTITY_H

namespace business
{
    class ISkyEntity
    {
        public:
            ISkyEntity(){};
            virtual ~ISkyEntity(){};

            virtual ETEXTURE getTextureSkyDome()=0;
            virtual ETEXTURE getTextureSkyBoxUp()=0;
            virtual ETEXTURE getTextureSkyBoxDn()=0;
            virtual ETEXTURE getTextureSkyBoxLf()=0;
            virtual ETEXTURE getTextureSkyBoxRt()=0;
            virtual ETEXTURE getTextureSkyBoxFt()=0;
            virtual ETEXTURE getTextureSkyBoxBk()=0;
    };
} // business

#endif

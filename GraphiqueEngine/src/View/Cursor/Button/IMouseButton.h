#ifndef IMOUSE_BUTTON_H
#define IMOUSE_BUTTON_H

namespace graphique
{
    class IMouseButton
    {
        public:
            IMouseButton(){};
            virtual ~IMouseButton(){};

            virtual void down()=0;
            virtual void up()=0;
            virtual bool isDown()=0;
    };
} // graphique

#endif



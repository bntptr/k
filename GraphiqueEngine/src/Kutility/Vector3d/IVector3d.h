#ifndef IVECTOR3D_H
#define IVECTOR3D_H

namespace business
{
    class IVector3d
    {
        public:
            IVector3d(){};
            virtual ~IVector3d(){};

            virtual float getX()=0;
            virtual IVector3d* setX(float x)=0;
            virtual float getY()=0;
            virtual IVector3d* setY(float y)=0;
            virtual float getZ()=0;
            virtual IVector3d* setZ(float z)=0;
    };
} // business

#endif


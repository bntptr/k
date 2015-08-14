#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "IVector3d.h"

namespace business
{
    class Vector3d : public IVector3d
    {
        protected:
            float x;
            float y;
            float z;
        public:
            Vector3d(){
                this->x = 0;
                this->y = 0;
                this->z = 0;
            };
            Vector3d(float x, float y, float z){
                this->x = x;
                this->y = y;
                this->z = z;
            };
            ~Vector3d(){};

            float getX() {
                return this->x;
            }

            IVector3d* setX(float x) {
                this->x = x;
                IVector3d *thisInstance = this;
                return thisInstance;
            }

            float getY() {
                return this->y;
            }

            IVector3d* setY(float y) {
                this->y = y;
                IVector3d *thisInstance = this;
                return thisInstance;
            }

            float getZ() {
                return this->z;
            }

            IVector3d* setZ(float z) {
                this->z = z;
                IVector3d *thisInstance = this;
                return thisInstance;
            }
    };
} // business

#endif


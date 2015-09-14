#ifndef VIEW3D_EDITOR_CAMERA_H
#define VIEW3D_EDITOR_CAMERA_H

#include "../Camera.h"

namespace graphique
{
    class CameraEditor : public Camera
    {
        public:
            CameraEditor(irr::IrrlichtDevice *device, ICursorService *cursor) : Camera(device, cursor){
            };
            ~CameraEditor(){};
    };
} // graphique

#endif


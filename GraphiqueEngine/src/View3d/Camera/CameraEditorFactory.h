#ifndef VIEW3D_EDITOR_CAMERA_FACTORY_H
#define VIEW3D_EDITOR_CAMERA_FACTORY_H

#include "Editor.h"
#include "../../Cursor/ICursorService.h"

namespace graphique
{
    class CameraEditorFactory
    {
        public:
            static ICamera* createEntity(irr::IrrlichtDevice *device, ICursorService *cursor) {
                return new CameraEditor(device, cursor);
            }
    };
} // graphique

#endif


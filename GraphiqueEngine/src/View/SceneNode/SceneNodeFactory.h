#ifndef VIEW_SCENE_NODE_FACTORY_H
#define VIEW_SCENE_NODE_FACTORY_H

#include "SceneNode.h"
#include "CubeSceneNode.h"
#include "SphereSceneNode.h"
#include "OctTreeSceneNode.h"
#include "CharacterSceneNode.h"
#include "SkySceneNode.h"
#include "TerrainSceneNode.h"

namespace graphique
{
    class SceneNodeFactory
    {
        public:
            static ISceneNode* createEntity(irr::IrrlichtDevice *device) {
                ISceneNode *node = new SceneNode();
                node->setDevice(device);
                return node;
            }

            static ISceneNode* createCubeSceneNode(
                irr::IrrlichtDevice *device,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture
            ) {
                return new CubeSceneNode(device);
            }

            static ISceneNode* createSphereSceneNode(
                irr::IrrlichtDevice *device,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture
            ) {
                return new SphereSceneNode(device);
            }

            static ISceneNode* createOctTreeSceneNode(
                irr::IrrlichtDevice *device,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale
            ) {
                ISceneNode *node = new OctTreeSceneNode(device);
                node->setPosition(position);
                node->setRotation(rotation);
                node->setScale(scale);
                return node;
            }

            static ISceneNode* createCharacterSceneNode(
                irr::IrrlichtDevice *device,
                int id,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                ISceneNode *node = new CharacterSceneNode(
                    device,
                    id,
                    position,
                    rotation,
                    scale,
                    texture,
                    mesh
                );
                return node;
            }

            static ISceneNode* createSkySceneNode(irr::IrrlichtDevice *device) {
                return new SkySceneNode(device);
            }

            static ISceneNode* createTerrainSceneNode(
                irr::IrrlichtDevice *device,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) {
                return new TerrainSceneNode(device);
            }
    };
} // graphique

#endif


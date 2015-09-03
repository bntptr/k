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
                return new SceneNode(device);
            }

            static ISceneNode* createCubeSceneNode(irr::IrrlichtDevice *device) {
                return new CubeSceneNode(device);
            }

            static ISceneNode* createSphereSceneNode(irr::IrrlichtDevice *device) {
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

            static ISceneNode* createCharacterSceneNode(irr::IrrlichtDevice *device) {
                return new CharacterSceneNode(device);
            }

            static ISceneNode* createSkySceneNode(irr::IrrlichtDevice *device) {
                return new SkySceneNode(device);
            }

            static ISceneNode* createTerrainSceneNode(irr::IrrlichtDevice *device) {
                return new TerrainSceneNode(device);
            }
    };
} // graphique

#endif


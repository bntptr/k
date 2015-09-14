#ifndef VIEW_TERRAIN_SCENE_NODE_H
#define VIEW_TERRAIN_SCENE_NODE_H

#include "SceneNode.h"

namespace graphique
{
    class TerrainSceneNode : public SceneNode
    {
        public:
            TerrainSceneNode(
                irr::IrrlichtDevice *device,
                business::Vector3d position,
                business::Vector3d rotation,
                business::Vector3d scale,
                ETEXTURE texture,
                EMESH mesh
            ) : SceneNode() {
                this->device = device;
                this->position = position;
                this->rotation = rotation;
                this->scale = scale;
                this->texture = texture;
                this->mesh = mesh;
            };
            ~TerrainSceneNode(){};

            bool build(ICameraService* camera) {
                std::cout <<"Build Terrain!" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add terrain scene node
                business::Vector3d position = this->getPosition();
                business::Vector3d rotation = this->getRotation();
                business::Vector3d scale = this->getScale();

                EMESH code_mesh = this->mesh;
                scene::ITerrainSceneNode* terrain = smgr->addTerrainSceneNode(
                    MEDIA + MESHInfoNames[code_mesh],
                    0,					// parent node
                    -1,					// node id
                    core::vector3df(
                        position.getX(),
                        position.getY(),
                        position.getZ()
                    ),		// position
                    core::vector3df(
                        rotation.getX(),
                        rotation.getY(),
                        rotation.getZ()
                    ),		// rotation
                    core::vector3df(
                        scale.getX(),
                        scale.getY(),
                        scale.getZ()
                    ),	// scale
                    video::SColor ( 255, 255, 255, 255 ),	// vertexColor
                    5,					// maxLOD
                    scene::ETPS_17,				// patchSize
                    4					// smoothFactor
                );

                terrain->setMaterialFlag(video::EMF_LIGHTING, false);

                ETEXTURE code_texture = this->texture;
                terrain->setMaterialTexture(0,
                        driver->getTexture(MEDIA + TEXTUREInfoNames[code_texture]));
                terrain->setMaterialTexture(1,
                        driver->getTexture(MEDIA + "detailmap3.jpg"));

                terrain->setMaterialType(video::EMT_DETAIL_MAP);

                terrain->scaleTexture(1.0f, 20.0f);
                //terrain->setDebugDataVisible ( true );

                // create triangle selector for the terrain
                scene::ITriangleSelector* selector
                    = smgr->createTerrainTriangleSelector(terrain, 0);
                terrain->setTriangleSelector(selector);

                // create collision response animator and attach it to the camera
                scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
                    selector,
                    camera->getCameraSceneNode(),
                    core::vector3df(60,100,60),
                    core::vector3df(0,-10.0f,0),
                    core::vector3df(0,0,0) // ici y valait 50
                );
                selector->drop();
                camera->getCameraSceneNode()->addAnimator(anim);
                anim->drop();

                scene::CDynamicMeshBuffer* buffer = new scene::CDynamicMeshBuffer(
                    video::EVT_2TCOORDS,
                    video::EIT_16BIT
                );
                terrain->getMeshBufferForLOD(*buffer, 0);
                video::S3DVertex2TCoords* data = (video::S3DVertex2TCoords*)buffer
                    ->getVertexBuffer().getData();

                // Work on data or get the IndexBuffer with a similar call.
                buffer->drop(); // When done drop the buffer again.
                this->node = terrain;
                return true;
            }

            bool draw(business::Vector3d cameraPosition, business::Vector3d cameraScale) {
                //std::cout <<"draw Terrain!" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add terrain scene node
                business::Vector3d position = this->getPosition();
                business::Vector3d rotation = this->getRotation();
                business::Vector3d scale = this->getScale();

                ETEXTURE code_texture = this->texture;
                std::cout << TEXTURE2DInfoNames[code_texture] << std::endl;
                //terrain->setMaterialTexture(0,
                //    driver->getTexture(MEDIA + TEXTURE2DInfoNames[code_texture])
                //);

                driver->draw2DImage(
                    driver->getTexture(MEDIA + TEXTURE2DInfoNames[code_texture]),
                    core::position2d<s32>(0,40), //<<là début del'affichage
                    //core::rect<s32>(0,0,512,384), 0,
                    core::rect<s32>(
                        cameraPosition.getX(),
                        cameraPosition.getZ(),
                        cameraPosition.getX() + cameraScale.getX(),
                        cameraPosition.getZ() + cameraScale.getZ()
                    ),
                    0,   //+512 +384//Attention: rect sur images
                    video::SColor(255,255,255,255),
                    true
                );

                return true;
            }

            bool onEvent(const irr::SEvent& event) {

                return true;
            }
    };
} // graphique

#endif

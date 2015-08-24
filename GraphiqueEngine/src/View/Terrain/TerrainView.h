#ifndef TERRAINVIEW_H
#define TERRAINVIEW_H

#include "ITerrainView.h"
#include "Action/IAction.h"
#include "Action/MapDetail.h"
#include "Action/MapTriangle.h"
#include "Action/MapPoint.h"

namespace graphique
{
    class TerrainView : public ITerrainView
    {
        protected:
            irr::IrrlichtDevice *device;
            business::IGroundEntity *ground;
            scene::ITerrainSceneNode* terrain;

            TMap<EACTIONEVENT, terrain::IAction>* keyMap;

        public:
            TerrainView(
                irr::IrrlichtDevice *device,
                business::IGroundEntity *ground,
                TMap<EACTIONEVENT, terrain::IAction>* keyMap
            ){
                this->device = device;
                this->ground = ground;
                this->keyMap = keyMap;
            };
            ~TerrainView(){};


            scene::ITerrainSceneNode* getTerrain(){
                return this->terrain;
            }

            bool draw(ICamera* camera) {
                std::cout <<"Draw Terrain!" << std::endl;
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();

                // add terrain scene node
                business::Vector3d position = this->ground->getPosition();
                business::Vector3d rotation = this->ground->getRotation();
                business::Vector3d scale = this->ground->getScale();

                EMESH code_mesh = this->ground->getMesh();
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

                this->terrain = terrain;
                terrain->setMaterialFlag(video::EMF_LIGHTING, false);

                ETEXTURE code_texture = this->ground->getTexture();
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
                    camera->getCamera(),
                    core::vector3df(60,100,60),
                    core::vector3df(0,0,0),
                    core::vector3df(0,0,0) // ici y valait 50
                );
                selector->drop();
                camera->getCamera()->addAnimator(anim);
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
            }

            bool oneEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                terrain::IAction *action  = this->keyMap->get(event);

                if (action) {
                    action->execute(this);
                }
                return true;
            }
    };
} // graphique

#endif

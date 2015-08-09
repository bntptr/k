#ifndef TERRAINVIEW_H
#define TERRAINVIEW_H

#include "ITerrainView.h"

namespace graphique
{
    class TerrainView : public ITerrainView
    {
        protected:
            irr::IrrlichtDevice *device;
            IGroundEntity *ground;
            scene::ITerrainSceneNode* terrain;

        public:
            TerrainView(irr::IrrlichtDevice *device, IGroundEntity *ground){
                this->device = device;
                this->ground = ground;
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
                scene::ITerrainSceneNode* terrain = smgr->addTerrainSceneNode(
                    MEDIA + "terrain-heightmap-plat-bas.bmp",
                    0,					// parent node
                    -1,					// node id
                    core::vector3df(0.f, 0.f, 0.f),		// position
                    core::vector3df(0.f, 0.f, 0.f),		// rotation
                    core::vector3df(40.f, 4.4f, 40.f),	// scale
                    video::SColor ( 255, 255, 255, 255 ),	// vertexColor
                    5,					// maxLOD
                    scene::ETPS_17,				// patchSize
                    4					// smoothFactor
                );

                this->terrain = terrain;
                terrain->setMaterialFlag(video::EMF_LIGHTING, false);

                terrain->setMaterialTexture(0,
                        driver->getTexture(MEDIA + "terrain-texture-plat-riviere.jpg"));
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
                    selector, camera->getCamera(), core::vector3df(60,100,60),
                    core::vector3df(0,0,0),
                    core::vector3df(0,50,0));
                selector->drop();
                camera->getCamera()->addAnimator(anim);
                anim->drop();

                scene::CDynamicMeshBuffer* buffer = new scene::CDynamicMeshBuffer(video::EVT_2TCOORDS, video::EIT_16BIT);
                terrain->getMeshBufferForLOD(*buffer, 0);
                video::S3DVertex2TCoords* data = (video::S3DVertex2TCoords*)buffer->getVertexBuffer().getData();
                // Work on data or get the IndexBuffer with a similar call.
                buffer->drop(); // When done drop the buffer again.
            }
    };
} // graphique

#endif


#ifndef POPULATIONVIEW_H
#define POPULATIONVIEW_H

#include "IPopulationView.h"
#include "Characters/CharacterFactory.h"

#include "../../Kutility/kutility.h"
#include "../ViewConfig.h"

namespace graphique
{
    class PopulationView : public IPopulationView
    {
        protected:
            IPopulationView *thisInstance;
            irr::IrrlichtDevice *device;
            business::IPopulationEntity *populationEntity;
            TList<ICharacter>* characterList;

        public:
            PopulationView(irr::IrrlichtDevice *device, business::IPopulationEntity *populationEntity){
                this->thisInstance = this;
                this->device = device;
                this->populationEntity = populationEntity;
                this->characterList = new TList<ICharacter>();
            };
            ~PopulationView(){};

            IObjectView* getObjectViewFromId(int id) {
                TList<ICharacter>* L = this->characterList;
                for(int i = 0; i < L->size(); i++) {
                    if (id == L->getElement(i)->getId()) {
                        IObjectView* obj = L->getElement(i);
                        return obj;
                    }
                }
                return NULL;
            }

            bool build() {
                TList<business::ICharacterEntity>* L = this->populationEntity->getCharacterList();
                for(int i = 0; i < L->size(); i++) {
                    this->addCharacter(this->device, L->getElement(i));
                }
                return true;
            }

            bool draw() {
                this->build();
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();
                // create POPULATION
                this->drawAll();

                // create ESSAI
                scene::IAnimatedMesh* mesh = smgr->getMesh(MEDIA + "sydney.md2");
                if (!mesh)
                {
                    device->drop();
                    return 1;
                }
                scene::IAnimatedMeshSceneNode* node2 = smgr->addAnimatedMeshSceneNode( mesh );
                node2->setPosition(core::vector3df(2700*2,255*2,2600*2));

                if (node2)
                {
                    node2->setMaterialFlag(video::EMF_LIGHTING, false);
                    node2->setMD2Animation(scene::EMAT_STAND);
                    node2->setMaterialTexture( 0, driver->getTexture(MEDIA + "sydney.bmp") );
                }

                // SPHERE
                scene::ISceneNode * node3 = smgr->addSphereSceneNode();
                if (node3)
                {
                    node3->setPosition(core::vector3df(0,0,30));
                    node3->setMaterialTexture(0, driver->getTexture(MEDIA + "wall.bmp"));
                    node3->setMaterialFlag(video::EMF_LIGHTING, false);
                }

                //CUBE
                scene::ISceneNode* n = smgr->addCubeSceneNode();

                if (n)
                {
                    n->setMaterialTexture(0, driver->getTexture(MEDIA + "t351sml.jpg"));
                    n->setMaterialFlag(video::EMF_LIGHTING, false);
                    scene::ISceneNodeAnimator* anim =
                        smgr->createFlyCircleAnimator(core::vector3df(0,0,30), 20.0f);
                    if (anim)
                    {
                        n->addAnimator(anim);
                        anim->drop();
                    }
                }


                //==========================================================================
                //                           NINJA
                // And this B3D file uses skinned skeletal animation.

                scene::ITriangleSelector* selector = 0;
                scene::IAnimatedMeshSceneNode* node = 0;
                node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("../../../media/ninja.b3d"),
                                    0, 75/*IDFlag_IsPickable | IDFlag_IsHighlightable*/);
                //node->setMaterialTexture(0, driver->getTexture("../../../../../../media/nskinrd.jpg") );
                node->setScale(core::vector3df(10, 10, 10));
                node->setPosition(core::vector3df(-70,-66,-60));
                node->setRotation(core::vector3df(0,90,0));
                node->setAnimationSpeed(10.f);
                node->getMaterial(0).NormalizeNormals = true;
                // Just do the same as we did above.
                selector = smgr->createTriangleSelector(node);
                node->setTriangleSelector(selector);
                selector->drop();


                // NINJA
                scene::IAnimatedMeshSceneNode* anms =
                    smgr->addAnimatedMeshSceneNode(smgr->getMesh(MEDIA + "ninja.b3d"));
                //anms->setMaterialTexture( 0, driver->getTexture(MEDIA + "sydney.bmp") );
                anms->setMaterialTexture( 0, driver->getTexture(MEDIA + "nskinrd.jpg") );

                if (anms)
                {
                    scene::ISceneNodeAnimator* anim =
                        smgr->createFlyStraightAnimator(core::vector3df(100,0,60),
                        core::vector3df(-100,0,60), 3500, true);
                    if (anim)
                    {
                        anms->addAnimator(anim);
                        anim->drop();
                    }

                    anms->setMaterialFlag(video::EMF_LIGHTING, false);

                    anms->setFrameLoop(0, 13);
                    anms->setAnimationSpeed(15);
            		//anms->setMD2Animation(scene::EMAT_RUN);

                    anms->setScale(core::vector3df(2.f,2.f,2.f));
                    anms->setRotation(core::vector3df(0,-90,0));
                    anms->setPosition(core::vector3df(2700*2,255*2,2600*2));
            //		anms->setMaterialTexture(0, driver->getTexture(MEDIA + "sydney.bmp"));
                }
            }

            bool addCharacter(
                irr::IrrlichtDevice *device,
                business::ICharacterEntity *characterEntity
            ){
                ICharacter *entity = graphique::CharacterFactory::createEntity(device, characterEntity);
                this->characterList->addElement(entity);
            }

            bool drawAll() {
                TList<ICharacter>* L = this->characterList;
                for(int i = 0; i < L->size(); i++) {
                    L->getElement(i)->draw();
                }
                return true;
            }

            IObjectView* getCharacterFromPlayer(){
                IObjectView *objectView = this->characterList->begin();
                return objectView;
            }
    };
} // graphique

#endif

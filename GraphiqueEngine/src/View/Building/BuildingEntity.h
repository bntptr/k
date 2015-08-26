#ifndef VIEW_BUILDING_ENTITY_H
#define VIEW_BUILDING_ENTITY_H

#include "IBuildingEntity.h"
//#include "Action/IAction.h"

namespace graphique
{
    class BuildingEntity : public IBuildingEntity
    {
        protected:
            irr::IrrlichtDevice *device;
            scene::IMeshSceneNode* node;
            business::IBuildingEntity *buildingEntity;

        public:
            BuildingEntity(irr::IrrlichtDevice *device, business::IBuildingEntity *entity){
                this->device = device;
                this->buildingEntity = entity;
            };
            ~BuildingEntity(){};

            bool draw() {
                ViewConfig *config = ViewConfig::getInstance();
                using namespace irr;

                config->load();
                const io::path MEDIA = config->getMediaPath();

                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* env = device->getGUIEnvironment();
                device->getFileSystem()->addZipFileArchive("../../../media/map-20kdm2.pk3");

                scene::IAnimatedMesh* q3levelmesh = smgr->getMesh("20kdm2.bsp");
                scene::IMeshSceneNode* q3node = 0;

                // The Quake mesh is pickable, but doesn't get highlighted.
                if (q3levelmesh)
                    q3node = smgr->addOctTreeSceneNode(q3levelmesh->getMesh(0), 0, IDFlag_IsPickable);


                scene::ITriangleSelector* selector = 0;

                if (q3node)
                {
                    q3node->setPosition(core::vector3df(1350,-130,1400));
                    //q3node->setPosition(core::vector3df(0,0,2600*2));

                    selector = smgr->createOctTreeTriangleSelector(
                            q3node->getMesh(), q3node, 128);
                    q3node->setTriangleSelector(selector);
                    // We're not done with this selector yet, so don't drop it.
                }
            }

            bool onEvent(EACTIONEVENT event) {
                std::cout << ACTIONEVENTInfoNames[event] << std::endl;
                //sky::IAction *action;
                switch(event)
                {
                    case EACTIONEVENT_CHANGE_SKY:
                        //action = new building::Build();
                        //action->execute(this);
                        break;
                    default:
                    break;
                }
                return true;
            }
    };
} // graphique

#endif


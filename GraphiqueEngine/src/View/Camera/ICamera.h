/**
source :
https://openclassrooms.com/courses/3d-temps-reel-avec-irrlicht/scene-nodes-et-cameras

ISceneManager::addCameraSceneNodeFPS (
 ISceneNode * parent,       // le noeud parent de la caméra
 f32 rotateSpeed,           // la vitesse de rotation de la caméra
 f32 moveSpeed,             // la vitesse de déplacement
 s32 id,                    // numéro d'identification du noeud
 SKeyMap * keyMapArray,     // une map permettant de re-affecter les touches
 s32 keyMapSize,            // taille de la keyMap
 bool noVerticalMovement,   // autorise ou non les mouvements sur l'axe vertical
 f32 jumpSpeed,             // vitesse de déplacement lors d'un saut
 bool invertMouse,          // inverse ou non la rotation de la caméra
 bool makeActive)           // indique si la caméra doit être active ou non

Action de base
Touche
Description
EKA_MOVE_FORWARD
KEY_UP
flèche du haut pour déplacement en avant
EKA_MOVE_BACKWARD
KEY_DOWN
flèche du bas pour déplacement en arrière
EKA_STRAFE_LEFT
KEY_LEFT
flèche de gauche pour déplacement à gauche
EKA_STRAFE_RIGHT
KEY_RIGHT
flèche de droite pour déplacement à droite
EKA_JUMP_UP
KEY_KEY_J
touche j pour un saut
**/
#ifndef VIEW_ICAMERA_H
#define VIEW_ICAMERA_H

#include <irrlicht.h>

//#include "../Terrain/ITerrainService.h"
//#include "../Population/IPopulationService.h"

namespace graphique
{
    class ITerrainService;
    class IPopulationService;
    class ICamera
    {
        public:
            ICamera(){};
            virtual ~ICamera(){};

            virtual irr::scene::ICameraSceneNode* getCameraSceneNode()=0;
            virtual bool build()=0;
            //virtual bool draw(ITerrainService *terrain, IPopulationService *population)=0;

            virtual business::Vector3d getPosition()=0;
            virtual ICamera* setPosition(business::Vector3d position)=0;
            virtual business::Vector3d getScale()=0;
            virtual ICamera* setScale(business::Vector3d scale)=0;
    };
} // graphique

#endif

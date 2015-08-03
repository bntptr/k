#ifndef BUSINESSVIEW_H
#define BUSINESSVIEW_H
#include "BusinessInterface.h"

namespace graphique
{
    class BusinessView : public BusinessInterface
    {
        public:
            IGroundEntity* getGround();
            ISkyEntity* getSky();
            IPopulationEntity* getPopulation();
            IPlayerEntity* getPlayer();

            BusinessView* setGround(IGroundEntity *ground);
            BusinessView* setSky(ISkyEntity *sky);
            BusinessView* setPopulation(IPopulationEntity *population);
            BusinessView* setPlayer(IPlayerEntity *player);

        protected:
            IGroundEntity *ground;
            ISkyEntity *sky;
            IPopulationEntity *population;
            IPlayerEntity *player;
    };

    IGround* BusinessView::getGround()
    {
        return this->ground;
    }

    ISky* BusinessView::getSky()
    {
        return this->sky;
    }

    IPopulation* BusinessView::getPopulation()
    {
        return this->population;
    }

    IPlayer* BusinessView::getPlayer()
    {
        return this->player;
    }

    BusinessView* BusinessView::setGround(IGroundEntity *ground)
    {
        this->ground = ground;
        return this;
    }

    BusinessView* BusinessView::setSky(ISkyEntity *sky)
    {
        this->sky = sky;
        return this;
    }

    BusinessView* BusinessView::setPopulation(IPopulationEntity *population)
    {
        this->population = population;
        return this;
    }

    BusinessView* BusinessView::setPlayer(IPlayerEntity *player)
    {
        this->player = player;
        return this;
    }
} // graphique

#endif

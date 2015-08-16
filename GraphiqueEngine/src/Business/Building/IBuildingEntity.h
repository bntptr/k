#ifndef IBUILDING_ENTITY_H
#define IBUILDING_ENTITY_H

namespace business
{
    class IBuildingEntity
    {
        public:
            IBuildingEntity(){};
            virtual ~IBuildingEntity(){};

            virtual char* getMeshName()=0;
            virtual IBuildingEntity* setMesh(char* meshName)=0;
    };
} // business

#endif

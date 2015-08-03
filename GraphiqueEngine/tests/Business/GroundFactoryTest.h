#ifndef GROUNDFACTORYTEST_H
#define GROUNDFACTORYTEST_H

// Dans businessEngine.a | mainEngine.a
// le fichier est donc dans le repertoire include du projet
#include "GroundFactoryInterface.h"

#include "GroundEntityTest.h"

namespace tests
{
    namespace business
    {
        class GroundFactoryTest : public GroundFactoryInterface
        {
            public:
                static IGroundEntity* createEntity();
        }

        public static IGroundEntity* GroundFactoryTest::createEntity()
        {
            return new GroundEntityTest();
        }
    }
}

#endif

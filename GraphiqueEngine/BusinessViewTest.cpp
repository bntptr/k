#include <cppunit/extensions/HelperMacros.h>
#include "BusinessView.h"
#include "BusinessViewTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(BusinessViewTest);

void BusinessViewTest::TestGround(void)
{
	BusinessView business;
    IGroundEntity *ground;
    IGroundEntity *ground2;

	business.setGround(ground);
	CPPUNIT_ASSERT(business.getGround() == ground);

	business.setGround(ground2);
	CPPUNIT_ASSERT(business.getGround() == ground2);
	CPPUNIT_ASSERT_ASSERTION_FAIL(CPPUNIT_ASSERT(business.getGround() == ground));
	CPPUNIT_ASSERT_MESSAGE( "Test Ground [OK]", retour == 0 );
}

void BusinessViewTest::TestSkyvoid)
{
    CPPUNIT_FAIL( "not implemented" );
	BusinessView business;
    ISkyEntity *sky;
    ISkyEntity *sky2;

	business.setSky(sky);
	CPPUNIT_ASSERT(business.getSky() == sky);

	business.setSky(sky2);
	CPPUNIT_ASSERT(business.getSky() == sky2);
	CPPUNIT_ASSERT_ASSERTION_FAIL(CPPUNIT_ASSERT(business.getSky() == sky));
}


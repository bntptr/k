#ifndef BUSINESSVIEWTEST_H
#define BUSINESSVIEWTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class BusinessViewTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(BusinessViewTest);
	CPPUNIT_TEST(TestGround);
	CPPUNIT_TEST(TestSky);
	CPPUNIT_TEST_SUITE_END();

	public:
		//~ Call before tests
		void setUp(void) {}

		//~ Call after tests
		void tearDown(void) {}

		void TestGround(void);
		void TestSky(void);
};

#endif

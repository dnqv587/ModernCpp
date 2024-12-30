#include "gtest/gtest.h"
#include "CRTP.h"

TEST(CRTP_test,CRTP)
{
	Dog d;
	Cat c;

	EXPECT_STREQ("汪汪",doBark(d).c_str());
	EXPECT_STREQ("喵喵",doBark(c).c_str());
}

int main(int argc,char * argv[])
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
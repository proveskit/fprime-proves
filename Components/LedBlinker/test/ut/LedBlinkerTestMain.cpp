// ======================================================================
// \title  LedBlinkerTestMain.cpp
// \author nate
// \brief  cpp file for LedBlinker component test main function
// ======================================================================

#include "LedBlinkerTester.hpp"

TEST(Nominal, TestBlinking) {
    Components::LedBlinkerTester tester;
    tester.testBlinking();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

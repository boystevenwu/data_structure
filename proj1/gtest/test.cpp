#include "gtest/gtest.h"
#include "proj1.hpp"
#include "ver.hpp" 
#include <map>
#include <string>


/*
 
Note that this IS NOT a comprehensive set of test cases.
You should still write additional test cases.

This is to get you started and serve as a sanity check.

 */


namespace{

TEST(SimpleCases, PotPanBib){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("POT", "PAN", "BIB", puzzle) ) ;
}

TEST(SimpleCases, NeatFind){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("UCI", "ALEX", "MIKE", puzzle) );
}


TEST(SimpleCases, FirstNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, Easy){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("ABC", "DEF", "HIJ", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("ABC", "DEF", "HIJ", puzzle) );
}

TEST(SimpleCases, EasyNo){

    std::map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("ABC", "DEF", "HJ", puzzle);
    EXPECT_FALSE( p1 &&  gradeYesAnswer("ABC", "DEF", "HJ", puzzle) );
}

} // end namespace

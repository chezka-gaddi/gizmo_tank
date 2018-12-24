#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "helpers.h"

#define CATCH_CONFIG_MAIN

TEST_CASE("Test getCoordinatesInRange")
{
    vector <vector <int>> Map = {{0,0,0},{0,0,0},{0,0,0}};
    vector<Coordinate> correct = {Coordinate(0,0), Coordinate(1,0), Coordinate(2,1), Coordinate(2,2), Coordinate(0,2), Coordinate(1,1)};
    vector<Coordinate> test = getCoordinatesInRange(2, 2, 0, Map);
    REQUIRE(test == correct);
}


TEST_CASE("Test getCoordinatesInRange, take 2")
{
    vector <vector <int>> Map = {{TREE,TREE,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    for( int r = 0; r < Map.size(); r++ )
    {
        for( int c = 0; c < Map[0].size(); c++ )
            cout << setw(3) << Map[c][r];
        cout << endl;
    }
    vector<Coordinate> correct = {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), 
        Coordinate(1,1), Coordinate(2,2), Coordinate(3,3)};

    vector<Coordinate> test = getCoordinatesInRange(4, 0, 0, Map);

    REQUIRE(test == correct);
}

/*
  Stream_t.cpp

  Test program for class Stream
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stream.hpp"

TEST_CASE( "NOP", "[Stream]" ) {

}

TEST_CASE( "INITIALIZE", "[Stream]" ){
  // TODO: Perhaps a better option would be to have
  //       a single data structure that holds this information
  VideoParams vp;
  vp.title   = "Test Pilot";
  vp.type    = Video::MOVIE;
  vp.hours   = 1;
  vp.minutes = 58;

  Video v(vp);
  Stream s(v, 0);
}

TEST_CASE( "Stream Parameters", "[Stream]" ) {
    VideoParams vp;
    vp.title   = "Test Pilot";
    vp.type    = Video::MOVIE;
    vp.hours   = 1;
    vp.minutes = 58;

    Video v(vp);
    Stream s(v, 0);
 
    REQUIRE(s.getOccurrences() == 0);
    REQUIRE(s.getVideo().getTitle() == "Test Pilot");
    REQUIRE(s.getVideo().getType() == Video::MOVIE);
    REQUIRE(s.getVideo().getHours() == 1);
    REQUIRE(s.getVideo().getMinutes() == 58);
}

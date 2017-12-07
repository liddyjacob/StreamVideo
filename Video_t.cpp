/*
  Video_t.cpp

  Test program for class Video
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Video.hpp"

TEST_CASE( "NOP", "[Video]" ) {

}

TEST_CASE("Video Initialization", "[Video]"){
  VideoParams vp;
  Video v(vp);

}

TEST_CASE("Video Parameters -- MOVIE", "[Video]"){
  VideoParams vp;
  vp.title = "Fargo";
  vp.type  = Video::MOVIE;
  vp.hours = 1;
  vp.minutes = 38;
  
  Video v(vp);

  REQUIRE(v.getTitle() == "Fargo");
  REQUIRE(v.getType() == 0);//Video::MOVIE);
  REQUIRE(v.getHours() == 1);
  REQUIRE(v.getMinutes() == 38);
  REQUIRE(v.getEpisodes() == 0); // as Fargo is a movie.
}

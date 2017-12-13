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


TEST_CASE("Video Parameters -- TV series", "[Video]"){
  VideoParams vp;

  //Fargo the TV series.
  vp.title = "Fargo, Season Two";
  vp.type  = Video::TVSHOW;
  vp.hours = 0;
  vp.minutes = 50;
  vp.episodes = 10;  

  Video v(vp);

  REQUIRE(v.getTitle() == "Fargo, Season Two");
  REQUIRE(v.getType() == 1);//Video::TVSHOW);
  REQUIRE(v.getHours() == 0);
  REQUIRE(v.getMinutes() == 50);
  REQUIRE(v.getEpisodes() == 10);
}

TEST_CASE("Video Parameters -- Original", "[Video]"){
  VideoParams vp;

  //Fargo the TV series.
  vp.title = "Original Production";
  vp.type  = Video::ORIGINAL;
  vp.hours = 1;
  vp.minutes = 0;
  vp.episodes = 5;  

  Video v(vp);

  REQUIRE(v.getTitle() == "Original Production");
  REQUIRE(v.getType() == 2);//Video::ORIGINAL);
  REQUIRE(v.getHours() == 1);
  REQUIRE(v.getMinutes() == 0);
  REQUIRE(v.getEpisodes() == 5);
}

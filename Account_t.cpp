/*
  Account_t.cpp

  Test program for class Account
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Account.hpp"

TEST_CASE( "No streaming", "[Account]" ) {

    Account customer("Fred");

    REQUIRE(customer.getName() == "Fred");
    REQUIRE(customer.data() == "");
}

TEST_CASE( "Single Stream", "[Account]" ) {
    Account customer("Fred");

    // Create Video to create stream
    VideoParams vp;
    vp.title = "Star Wars Episode I";
    vp.type = Video::MOVIE;
    vp.hours = 2;
    vp.minutes = 16;

    Video v(vp);

    REQUIRE(customer.getName() == "Fred");
    REQUIRE(customer.data() == "");
}

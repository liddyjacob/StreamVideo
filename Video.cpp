/*
  Video.cpp

  Definition file for Video class
*/

#include "Video.hpp"

// constructor
Video::Video(const std::string& title, int hours, int minutes, int episodes)
    : title(title), hours(hours), minutes(minutes), episodes(episodes)
{ }

Video::Video(const VideoParams& vp)
  : title(vp.title), type(vp.type)
    ,hours(vp.hours), minutes(vp.minutes)
    ,episodes(vp.episodes)
{ }


// video title
const std::string& Video::getTitle() const {

    return title;
}

// video type
int Video::getType() const {

    return type;
}

// video length in hours
int Video::getHours() const {

    return hours;
}

// video length in minutes
int Video::getMinutes() const {

    return minutes;
}

// set video length
void Video::setLength(int hours, int minutes) {

    this->hours = hours;
    this->minutes = minutes;
}

// Return the number of episodes for the TV Show
int TvShow::getEpisodes() const {
    return episodes;
}

// Return the number of episodes of an Original (if applicable)
int Original::getEpisodes() const {
    return episodes;
}

TvShow::TvShow(const std::string& title, int hours, int minutes, int episodes) {
}

/*
  Video.hpp

  Include file for Video class
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>

struct VideoParams
{
  VideoParams()
      : title(""), type(-1), hours(0), minutes(0), episodes(0)
  {
  }

  std::string title;
  int type;
  int hours;
  int minutes;
  int episodes;
};

class Video
{
public:
  static const int MOVIE = 0;
  static const int TVSHOW = 1;
  static const int ORIGINAL = 2;

  // TODO: We should definately change this primative obsession
  //         code smell.
  // constructor
  Video(const std::string &title, int type, int hours, int minutes, int episodes);
  Video(const VideoParams &vp);

  // video title
  const std::string &getTitle() const;

  // video type
  int getType() const;

  // length in hours
  int getHours() const;

  // length in minutes
  int getMinutes() const;

  // number of episodes
  int getEpisodes() const;

  // set video length
  void setLength(int hours, int minutes);

private:
  std::string title;
  int type;
  int hours;
  int minutes;
  int episodes;
};

class MOVIE : public Video
{
};

class TVSHOW : public Video
{
};

class ORIGINAL : public Video
{
};

#endif

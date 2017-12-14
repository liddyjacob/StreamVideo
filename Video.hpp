/*
  Video.hpp

  Include file for Video class
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>

class VideoParams;

class Video {
public:
    Video(const std::string& title, int hours, int minutes, int episodes);
    Video(const VideoParams& vp);

    // video title
    const std::string& getTitle() const;

    // length in hours
    int getHours() const;

    // length in minutes
    int getMinutes() const;

    // set video length
    void setLength(int hours, int minutes);

private:
    std::string title;
    int hours;
    int minutes;
};

struct VideoParams{
  VideoParams()
    : title(""), type(-1), hours(0),minutes(0)
  { }

  std::string title;
  int type;
  int hours;
  int minutes;
};

class Movie : Video {};

class TvShow : Video {
    // Build upon the base of video and give TvShow the property of
    // having an episode count
    private:
        int episodes;

    public:
        TvShow(const std::string&, int, int, int);
        int getEpisodes() const;
};

class Original : Video {
    private:
        int episodes;

    public:
        Original();
        int getEpisodes() const;
};

#endif

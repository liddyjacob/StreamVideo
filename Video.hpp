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

    static const int MOVIE      = 0;
    static const int TVSHOW     = 1;
    static const int ORIGINAL   = 2;

    // TODO: We should definately change this primative obsession
    //         code smell.
    // constructor
    Video(const std::string& title, int type, int hours, int minutes, int episodes);
    Video(const VideoParams& vp);

    // video title
    const std::string& getTitle() const;

    // video type
    int getType() const;

    // length in hours
    int getHours() const;

    // length in minutes
    int getMinutes() const;

    // set video length
    void setLength(int hours, int minutes);

private:
    std::string title;
    int type;
    int hours;
    int minutes;
};

struct VideoParams{
  VideoParams()
    : title(""), type(-1), hours(0),minutes(0),episodes(0)
  { }

  std::string title;
  int type;
  int hours;
  int minutes;
  int episodes;
};

class Movie : Video {};

class TvShow : Video {
    // Build upon the base of video and give TvShow the property of
    // having an episode count
    private:
        int episodes;

    public:
        int getEpisodes() const;
};

class Original : Video {
    private:
        int episodes;

    public:
        int getEpisodes() const;
};

#endif

/*
  Account.cpp

  Definition file for Account class
*/

#include "Account.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Account::Account(const std::string &name)
    : name(name)
{
}

// account name
std::string Account::getName() const
{

    return name;
}

// add a stream to this account
void Account::addStream(const Stream &stream)
{

    streams.push_back(stream);
}

// account streaming report
std::string Account::report() const
{

    // stringstream to convert data
    std::ostringstream output;

    // print customer name
    output << "Stream Report for Account: " << getName() << '\n';

    // print list of streams
    output << "Streams:" << '\n';
    int totalStreams = 0;
    int totalOriginals = 0;
    int totalHours = 0;
    int totalMinutes = 0;
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it)
    {

        // title of stream
        output << '\t' << it->getVideo().getTitle();

        // current total hours and minutes
        totalHours += it->getVideo().getHours() * it->getOccurrences();
        totalMinutes += it->getVideo().getMinutes() * it->getOccurrences();

        // stream counts and originals
        int streamCount = 0;
        int hourCount = 0;
        int originals = 0;
        switch (it->getVideo().getType())
        {

        // for movies, the stream count is the number of hours, with a minimum of 1
        case Video::MOVIE:
            streamCount += it->getOccurrences();
            hourCount += it->getOccurrences() * (it->getVideo().getHours() ? it->getVideo().getHours() : 1);
            break;

        // for TV shows, the stream count is just the number of streams
        case Video::TVSHOW:
            streamCount += it->getOccurrences();
            break;

        // for Originals, the stream count is just the number of streams
        case Video::ORIGINAL:
            originals += it->getOccurrences();
            streamCount += it->getOccurrences();
            break;
        }

        // print stream counts for this video
        std::ostringstream out_str_stream;
        output << "\n\t" << "Number of times watched: " << streamCount;

        if(it->getVideo().getType() == 0)
        {
            output << "\n\tNumber of hours watched over " << streamCount << " sessions: " << hourCount;
        }

        output << "\n\n";

        totalStreams += streamCount;
        totalOriginals += originals;
    }

    // print total stream counts
    output << "Total Stream Events: " << totalStreams << '\n';

    // print total non-original stream counts
    output << "Non-Original Stream Events: " << (totalStreams - totalOriginals) << '\n';

    // print total time
    int minutes = totalMinutes % 60;
    int hours = totalHours + totalMinutes / 60;
    output << "Total Time: " << hours << ":" << minutes << '\n';

    return output.str();
}

// account data in CSV and Account name
std::string Account::data() const
{

    // stringstream to convert data
    std::ostringstream output;

    // customer name
    std::string name = getName();

    // print list of streams
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it)
    {
        if(it == streams.begin())
        output << "List of all Streams:";

        // print customer name
        output << "\n\tAccount: " << name;

        // stream type
        switch (it->getVideo().getType())
        {

        // if type is MOVIE print MOVIE
        case Video::MOVIE:
            output << "\n\tType: Movie";
            break;

        // if type is TVSHOW print TVSHOW
        case Video::TVSHOW:
            output << "\n\tType: TV Show";
            break;

        // if type is ORIGINAL print ORIGINAL
        case Video::ORIGINAL:
            output << "\n\tType: Original";
            break;
        }

        // print stream title
        output << "\n\tTitle: " << it->getVideo().getTitle();


        // print Total stream hours and minutes
        output << "\n\tTotal view time: " << (it->getVideo().getHours() * it->getOccurrences()) << " Hours ";
        output << (it->getVideo().getMinutes() * it->getOccurrences()) << " Minutes";

        // print stream counts
        switch (it->getVideo().getType())
        {
        // print stream count for movies, the stream count is the number of hours, with a minimum of 1
        case Video::MOVIE:
            output<< "\n\tNumber of times watched: " << it->getOccurrences();
            output << "\n\tNumber of hours watched over " << it->getOccurrences() << " sessions: " << (it->getOccurrences() * (it->getVideo().getHours() ? it->getVideo().getHours() : 1));
            break;

        // all others just print the number of occurrences
        default:
            output<< "\n\tNumber of times watched: " << it->getOccurrences();
            break;
        }
        output << '\n';
    }
    return output.str();
}

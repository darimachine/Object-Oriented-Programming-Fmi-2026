#include <iostream>
#include"Playlist.h"

int main()
{
    Duration d1{ 3, 45 };
    Duration d2{ 4, 10 };
    Duration d3{ 5, 5 };

    Song s1("Love", d1, "Rock");
    Song s2("Happy", d2, Genre::POP);
    Song s3("Hop", d3, Genre::CLASSICAL);

    Playlist p("My Playlist",2);

    p.addSong(s1);
    p.addSong(s2);
    p.addSong(s3);

    p.printPlaylistInfo();

    p.addSong(s1);

    if (p.removeSong("Happy"))
    {
        std::println("Removed successfully!");
    }
    else
    {
        std::println("Song not found!");
    }

    std::println("\nFinal playlist:");
    p.printPlaylistInfo();

    return 0;
}

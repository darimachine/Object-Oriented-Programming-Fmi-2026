#include "Playlist.h"
#include <iostream>
#include <print>

int main()
{
    Duration d1(3, 45);
    Duration d2(2, 30);
    Duration d3(4, 10);

    Song s1("Song1", d1, Genre::ROCK);
    Song s2("Song2", d2, Genre::POP);
    Song s3("Song3", d3, Genre::JAZZ);

    Playlist p("My Playlist", 2);

    p.addSong(s1);
    p.addSong(s2);
    p.addSong(s3); 

    p.printPlaylistInfo();

    std::print("\nRemoving Song2\n");
    p.removeSong("Song2");

    p.printPlaylistInfo();

    std::println("\nIndex of Song3: {}", p.getSongIndex("Song3"));

    return 0;
}



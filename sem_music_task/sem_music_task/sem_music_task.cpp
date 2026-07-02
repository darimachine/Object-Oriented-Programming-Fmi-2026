#include <iostream>
#include "Duration.h"
#include "Song.h"
#include "Playlist.h"

int main()
{
    Song s1("Arctic Monkeys - Arabella", Duration(3, 27), "CathyMusic");
    Song s2("Artemas - myself", Duration(4, 10), "CathyMusic");
    Song s3("Arctic Monkeys - Knee Socks", Duration(4, 15), "CathyMusic");
    Song s4("The Neighbourhood - A Little Death", Duration(3, 45), "CathyMusic");
    std::cout << "Songs" << std::endl;
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    std::cout << std::endl;
    Playlist myPlaylist("My Favorite Tracks");
    myPlaylist.addSong(s1);
    myPlaylist.addSong(s2);
    myPlaylist.addSong(s3);
    myPlaylist.addSong(s4);

    myPlaylist.addSong(s1);
    std::cout << std::endl;

    std::cout << "Playlist Info" << std::endl;
    myPlaylist.printPlaylistInfo();
    std::cout << std::endl;
    int index1 = myPlaylist.getSongIndex("Artemas - myself (official lyric video)");
    std::cout << "Index of " << s2.getName() <<": " << index1 << std::endl;
    int index2 = myPlaylist.getSongIndex("Non existent Song");
    std::cout << "Index of that song: " << index2 << std::endl;
    std::cout << std::endl;
    bool removed1 = myPlaylist.removeSong("Arctic Monkeys - Knee Socks");
    std::cout << "Removed: " << s3.getName() << ": ";
    if (removed1)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << std::endl;
    bool removed2 = myPlaylist.removeSong("Song That Is Not In Playlist");
    std::cout << "Removed: ";
    if (removed2)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << "Updated Playlist" << std::endl;
    myPlaylist.printPlaylistInfo();
    Playlist copiedPlaylist = myPlaylist;
    copiedPlaylist.setName("Copied Playlist");
    copiedPlaylist.addSong(Song("Extra Song", Duration(3, 30), "CathyMusic"));
    std::cout << std::endl;
    std::cout << "Copied Playlist" << std::endl;
    copiedPlaylist.printPlaylistInfo();
}
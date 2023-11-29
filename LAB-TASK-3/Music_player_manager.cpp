#include <iostream>
#include <string>
#include "Music_player_manager.h"
using namespace std;
int get_Length(Music_player_manager &n1);
int main()
{
    Music_player_manager n1;
    cout << "Welcome the Music playlist Manager" << endl;
    while (1)
    {
        int choice;
        cout << "Choose from the following options" << endl;
        cout << "1) Add song" << endl;
        cout << "2) Delete a song" << endl;
        cout << "3) Print Playlist" << endl;
        cout << "4) Search a song" << endl;
        cout << "5) Start Playlist" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int len;
            len = get_Length(n1);
            cout << "We have " << len << " no of songs where do you want to insert it" << endl;
            int pos;
            cout << "Enter the position at which you want to enter the song" << endl;
            cin >> pos;
            cout << "Enter name of the song" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            n1.add_song(pos, name);
        }
        else if (choice == 2)
        {
            int pos;
           cout<<"Enter the position you want to delete"<<endl;
           cin>>pos;
           n1.remove_song(pos);
        }
        else if (choice == 3)
        {
            n1.print_playlist();
        }
        else if (choice == 4)
        {
            cout << "Enter name of song you want to search" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            n1.search(name);
        }
        else 
        {
            break;
        }
    }
}
int get_Length(Music_player_manager &n1)
{
    return n1.lengthh();
}

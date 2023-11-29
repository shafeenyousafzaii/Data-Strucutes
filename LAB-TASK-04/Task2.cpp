#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string song_name;
    Node *next;
    Node(string song_name)
    {
        this->song_name = song_name;
        next = NULL;
    }
};
class Music_player_manager
{
public:
    int length;
    Node *head;
    Music_player_manager()
    {
        length = 0;
        head = NULL;
    }
    void add_song(int pos, string name)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Postion" << endl;
            return;
        }
        Node *n = new Node(name);
        Node *curr = head;
        if (head == NULL)
        {
            head = n;
            head->next = head;
        }
        else if (pos == 1)
        {
            n->next = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
            head = n;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
    void print_playlist()
    {
        Node *curr = NULL;
        while (curr != head)
        {
            if (curr == NULL)
            {
                curr = head;
            }
            cout << curr->song_name << endl;
            curr = curr->next;
        }
        cout << endl;
    }
    void remove_song(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid" << endl;
            return;
        }
        Node *curr = head;
        Node *tail = head;
        if (pos == 1)
        {
            while (tail->next != head)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            if (head == head->next)
            {
                head = NULL;
            }
            delete curr;
        }
        else
        {
            Node *less_than_curr = NULL;
            for (int i = 1; i < pos; i++)
            {
                less_than_curr = curr;
                curr = curr->next;
            }
            less_than_curr->next = curr->next;
            delete curr;
        }
        length--;
    }
    int lengthh()
    {
        return length;
    }
    void search(string name)
    {
        bool found = false;
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->song_name == name)
            {
                cout << "Song exist" << endl;
                found = true;
                return;
            }
            curr = curr->next;
        }
        if (found == false)
        {
            cout << "Song do not found" << endl;
            return;
        }
    }
    void start_playlist()
    {
        int yes;
        Node *curr = head;
        while(1)
        {
            cout<<"Do you want to play the next song? {press 1 : press any other button to exit}"<<endl;
            // cin.ignore();
            cin>>yes;
            if(yes==1)
            {
                cout<<curr->song_name<<endl;
                curr=curr->next;
            }
            else
            {
                cout<<"Close"<<endl;
                break;
            }
        }
    }
};
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
            cout << "Enter the position you want to delete" << endl;
            cin >> pos;
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
        else if (choice == 5)
        {
            string yes;
            cout << "Do you want to start the playlist?" << endl;
            cout << "Do you want to play the  song? {yes or Yes}" << endl;
            cin >> yes;
            if (yes == "Yes" || yes == "yes")
            {
                n1.start_playlist();
            }
            else
            {
                continue;
            }
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

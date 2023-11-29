#include<iostream>
#include<string>
using namespace std;
class Music_list
{
public:
    string song_name;
    Music_list *next;
    Music_list(string song_name)
    {
        this->song_name = song_name;
        next = NULL;
    }
    // ~Music_list(){};
};
class Music_player_manager
{
public:
    int length;
    Music_list *head;
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
        else if (pos == 1)
        {
            Music_list *temp = new Music_list(name);
            temp->next = head;
            head = temp;
        }
        else
        {
            Music_list *node = head;
            for (int i = 1; i < (pos - 1); i++)
            {
                node = node->next;
            }
            Music_list *temp = new Music_list(name);
            temp->next = node->next;
            node->next = temp;
        }
        length++;
    }
    void print_playlist()
    {
        Music_list *curr = head;
        while (curr != NULL)
        {
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
        Music_list *curr = head;
        if (pos == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            Music_list *n2 = NULL;
            for (int i = 1; i < pos; i++)
            {
                n2 = curr;
                curr = curr->next;
            }
            n2->next = curr->next;
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
        Music_list *curr = head;
        while (curr != NULL)
        {
            if (curr->song_name == name)
            {
                cout << "Song exist" << endl;
                found = true;
            }
            curr = curr->next;
        }
        if (found == false)
        {
            cout << "Song do not found" << endl;
        }
    }
};

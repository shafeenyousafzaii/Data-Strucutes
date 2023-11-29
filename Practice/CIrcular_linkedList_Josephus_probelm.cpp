#include <iostream>
#include <string>
// #include <stdlib>
// #include <time.h>
class Node
{
public:
    Node *next;
    int data;
    Node(int data = 0)
    {
        this->data = data;
        next = NULL;
    };
    // ~Node();
};
class CIrcular_linkedList
{
public:
    Node *head;
    int length;
    CIrcular_linkedList()
    {
        head = NULL;
        length = 0;
    };
    void insert(int val, int pos)
    {
        Node *n = new Node(val);
        Node *curr = head;
        if (pos < 1 || pos > length + 1)
        {
            std::cout << "Invalid Position" << std::endl;
            return;
        }
        if (head == NULL)
        {
            head = n;
            head->next = head;
        }
        else if (pos == 1)
        {
            // Node *curr=head;
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
            for (int i = 1; i < pos - 1; i++)
            { // if you want to put condition i < pos then start the loop from second position
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }

    void remove(int pos)
    {
        if (length == 0)
        {
            std::cout << "Empty" << std::endl;
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
            tail = NULL;
            for (int i = 1; i < pos; i++)
            {
                tail = curr;
                curr = curr->next;
            }
            tail->next = curr->next;
            delete curr;
        }
        length--;
    }
    // void remove(Node *removeable)
    // {
    //     if (length == 0)
    //     {
    //         std::cout << "LIST IS EMPTY" << std::endl;
    //     }
    //     if (head == removeable)
    //     {
    //         Node *curr = head;
    //         while (curr->next != head)
    //         {
    //             curr = curr->next;
    //         }
    //         curr->next = head->next;
    //         head = head->next;
    //         delete removeable;
    //     }
    //     else
    //     {
    //         Node *curr = head;
    //         while (curr->next != head && curr->next != removeable)
    //         {
    //             curr = curr->next;
    //         }
    //         if (curr->next == removeable)
    //         {
    //             curr->next = removeable->next;
    //             delete removeable;
    //         }
    //     }
    // }
    void print_all()
    {
        Node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            std::cout << curr->data << " - > ";
            curr = curr->next;
        }
        std::cout << "END" << std::endl;
    }
    void Josephus_problem(int n, int m)
    {
        if(m<0)
        {
            std::cout<<"INVALID NUMBER OF STEPS"<<std::endl;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            // int val=srand(time(NULL));
            insert(i, i); // giving number wise data with number wise slot
            
        }
        Node *curr = head;
        Node *slow = NULL;
        while(length != 1)
        {
            int count = 0;
            for (int i = 1; i <= m; i++)
            {
                slow = curr;
                curr = curr->next;
                count++;
            }
            // slow->next = curr->next;
            int val=curr->data;
            int pos=find(val);
            curr=curr->next;
            remove(pos);
            // delete curr;
            // int value = 0;
            // std::cout << curr->data << std::endl;
            // // remove(count);
            // length--;
        }
        std::cout << "Final value" << std::endl;
        std::cout << curr->data << std::endl;
        // return curr->data;   
    }
    int find(int val)
    {
        if(head==NULL)
        {
            std::cout<<"EMPTYY LIST"<<std::endl;
            return 1;
        }
        Node *curr=head;
        for(int i = 1;i<=length;i++)
        {
            if(curr->data==val)
            {
                return i; 
            }
            curr=curr->next;
        }
        return -1;

    }
};
int main()
{
    CIrcular_linkedList l1;
    // l1.insert(5,1);
    // l1.insert(3,1);
    // l1.insert(6,1);
    // l1.remove(1);
    // l1.remove(2);
    // // l1.insert(5,3);?
    // l1.insert(1,1);
    // l1.insert(5,1);
    // l1.insert(6,1);
    // l1.print_all();
    // l1.remove(3);
    // l1.print_all();
    // WHEN YOU TEST THESE TESTCASES TEST THEM ONE BY ONE , NOT ALL AT ONCE , IT WILL GIVE ERROR BECASUE OF OBVIOUS REASONS
    // l1.Josephus_problem(5, 3); //PASSED TEST CASE
    // l1.Josephus_problem(5, 2); //PASSED TEST CASE
    // l1.Josephus_problem(5, 2); //PASSED TEST CASE
    // l1.Josephus_problem(4, 3); //PASSED TEST CASE
    //    l1.Josephus_problem(1,1);  //PASSED TEST CASE
    // l1.Josephus_problem(2,4); //PASSED TEST CASE
    // l1.Josephus_problem(10,5); //PASSED TEST CASE
    int number_of_people;
    int number_of_Stepsize;
    std::cout<<"Josephus Probelem !!"<<std::endl;
    std::cout<<"Enter the number of people"<<std::endl;
    std::cin>>number_of_people;
    std::cout<<"Enter the number of skippings"<<std::endl;
    std::cin>>number_of_Stepsize;
    l1.Josephus_problem(number_of_people,number_of_Stepsize);
    std::cout<<"ThankYou for testing!"<<std::endl;
    return 1;
}

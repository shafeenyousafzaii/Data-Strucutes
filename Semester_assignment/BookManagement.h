#include <iostream>
#include <string>
#include <tuple>
using namespace std;

class DateClass
{
private:
    tuple<int, int, int> DateofBookPublication;

public:
    DateClass(int x = 0, int y = 0, int z = 0)
    {
        DateofBookPublication = make_tuple(x, y, z);
    };
    tuple<int, int, int> getpublicationDate()
    {
        // if()
        return DateofBookPublication;
    }
    void setpublicationDate(int day, int month, int year)
    {
        DateofBookPublication = make_tuple(day, month, year);
    }
    int getYear()
    {
        return get<2>(DateofBookPublication);
    }

    int getMonth()
    {
        return get<1>(DateofBookPublication);
    }

    int getDay()
    {
        // tuple<int, int, int> date;
        return get<0>(DateofBookPublication);
    }
};
class Book
{
private:
    int ISBN_number;
    string AUthorName;
    string Book_Title;
    string Book_genre;
    DateClass publicationDate;

public:
    Book *next;
    Book *prev;
    Book(int isbn = 0, string AuthorName = "", string booktitle = "", string Book_genre = "", int day = 0, int month = 0, int year = 0) : publicationDate(day, month, year)
    {
        AUthorName = AuthorName;
        ISBN_number = isbn;
        Book_Title = booktitle;
        this->Book_genre = Book_genre;
        next = NULL;
        prev = NULL;
    }
    void Setter(int isbn, string AuthorName, string booktitle, string Book_genre, int day, int month, int year)
    {
        AUthorName = AuthorName;
        ISBN_number = isbn;
        Book_Title = booktitle;
        this->Book_genre = Book_genre;
        publicationDate.setpublicationDate(day, month, year);
    }
    tuple<int, int, int> getDate()
    {
        return publicationDate.getpublicationDate();
    }
    int getYear()
    {
        return publicationDate.getYear();
    }

    int getMonth()
    {
        return publicationDate.getMonth();
    }

    int getDay()
    {
        // tuple<int, int, int> date;
        return publicationDate.getDay();
    }
    int getisbn()
    {
        return ISBN_number;
    }
    string getauthorname()
    {
        return AUthorName;
    }
    string gettitle()
    {
        return Book_Title;
    }
    string getgenre()
    {
        return Book_genre;
    }
    
    void getter()
    {
        cout << "Author Name: " << AUthorName << endl;
        cout << "Book Name  : " << Book_Title << endl;
        cout << "Book genre : " << Book_genre << endl;
        cout << "Book ISBN  : " << ISBN_number << endl;
    }
};
class BookManagement
{
private:
    Book *head;
    // DateClass p_d;
    int length;

public:
    BookManagement(int x = 0)
    {
        length = x;
        head = NULL;
    };
    // void insert(int day, int month, int year, int isbn, string AuthorName, string booktitle, string Book_genre)
    // {

    //     Book *curr = head;

    //     Book *n = new Book(isbn, AuthorName, booktitle, Book_genre, day, month, year);
    //     if (head == NULL)
    //     {
    //         head = n;
    //         length++;
    //         return;
    //     }
    //     else
    //     {
    //         cout << "HERE " << endl;
    //         while (curr != NULL)
    //         {
    //             // tuple<int, int, int> p_dateprev = curr->prev->getDate();
    //             tuple<int, int, int> p_date = n->getDate();
    //             cout<<"WORKING 1"<<endl;
    //             tuple<int, int, int> p_datecurr = curr->getDate();
    //             cout<<"WORKING 2"<<endl;
    //             tuple<int, int, int> p_datenext;
    //             cout<<"WORKING 3"<<endl;
    //             // tuple<int, int, int> p_datenext;
    //             try
    //             {
    //                 int val=0;
    //                 // Accessing an element from an empty tuple
    //                 // int value = std::get<0>(p_datenext); // This will lead to undefined behavior
    //                 // std::cout << "Value: " << value << std::endl;
    //                 if(curr->next!=NULL)
    //                     p_datenext = curr->next->getDate();
    //                 else
    //                     throw(val);
    //                 cout<<"WORKING 4"<<endl;
    //             }
    //             catch (int val)
    //             {
    //                 p_datenext = make_tuple(0, 0, 0);
    //                 // std::cerr << "Error: " << e.what() << std::endl;
    //             }
    //             int date_n = get<0>(p_datenext);
    //             int month_n = get<1>(p_datenext);
    //             int year_n = get<2>(p_datenext);
    //             int date_p = get<0>(p_date);
    //             int month_p = get<1>(p_date);
    //             int year_p = get<2>(p_date);
    //             int date_c = get<0>(p_datecurr);
    //             int month_c = get<1>(p_datecurr);
    //             int year_C = get<2>(p_datecurr);
    //             // try
    //             // {
    //             // int date_n = get<0>(p_datenext);
    //             // int month_n = get<1>(p_datenext);
    //             // int year_n = get<2>(p_datenext);
    //             // throw(true);
    //             // }
    //             // catch (bool no)
    //             // {
    //             // if (no == true)
    //             //     {
    //             //         date_n=0;
    //             //         month_n=0;
    //             // year_n=0;
    //             //     }
    //             // }
    //             // if (date_p >= date_c && month_p >= month_c && year_p >= year_C)
    //             // {
    //             //     n->next = curr->next;
    //             //     n->prev = curr;
    //             //     curr->next->prev = n;
    //             //     curr->next = n;
    //             //     break;
    //             // }
    //             // if(date_p <= date_c && month_p <= month_c && year_p <= year_C)
    //             // {

    //             // }
    //             if ((date_p >= date_c && month_p >= month_c && year_p >= year_C))
    //             {
    //                 if (curr->next == NULL)
    //                 {
    //                     curr->next = n;
    //                     curr->next->prev = curr;
    //                 }
    //                 if (curr->next != NULL)
    //                 {
    //                     n->next = curr->next;
    //                     n->prev = curr;
    //                     curr->next->prev = n;
    //                     curr->next = n;
    //                 }
    //                 cout << "HERE 2" << endl;
    //                 break;
    //             }
    //             else if ((date_p <= date_n && month_p <= month_n && year_p <= year_n))
    //             {
    //                 if (curr->next == NULL)
    //                 {
    //                     curr->next = n;
    //                     curr->next->prev = curr;
    //                 }
    //                 if (curr->next != NULL)
    //                 {
    //                     n->next = curr->next;
    //                     n->prev = curr;
    //                     curr->next->prev = n;
    //                     curr->next = n;
    //                 }
    //                 cout << "HERE 3" << endl;
    //                 break;
    //             }
    //             else if ((curr->next == NULL) && (date_p > date_c && month_p > month_c && year_p > year_C))
    //             {
    //                 if (curr->next == NULL)
    //                 {
    //                     curr->next = n;
    //                     curr->next->prev = curr;
    //                 }
    //                 if (curr->next != NULL)
    //                 {
    //                     n->next = curr->next;
    //                     n->prev = curr;
    //                     curr->next->prev = n;
    //                     curr->next = n;
    //                 }
    //                 cout << "HERE 4" << endl;
    //                 break;
    //             }
    //             else if ((date_p >= date_c && (month_p >= month_c || year_p >= year_C) || (date_p <= date_n || month_p <= month_n || year_p <= year_n)))
    //             {
    //                 if (curr->next == NULL)
    //                 {
    //                     curr->next = n;
    //                     curr->next->prev = curr;
    //                 }
    //                 if (curr->next != NULL)
    //                 {
    //                     n->next = curr->next;
    //                     n->prev = curr;
    //                     curr->next->prev = n;
    //                     curr->next = n;
    //                 }
    //                 cout << "HERE 5" << endl;
    //                 break;
    //             }
    //             else if ((date_p < date_n || month_p < month_n) && year_p == year_n)
    //             {
    //                 if (curr->next == NULL)
    //                 {
    //                     curr->next = n;
    //                     curr->next->prev = curr;
    //                 }
    //                 if (curr->next != NULL)
    //                 {
    //                     n->next = curr->next;
    //                     n->prev = curr;
    //                     curr->next->prev = n;
    //                     curr->next = n;
    //                 }
    //                 cout << "HERE 6" << endl;
    //                 break;
    //             }
    //             else if ((date_p <= date_n) && ((month_p >= month_n) || year_p >= year_n))
    //             {
    //                 if (curr->next == NULL)
    //                 {
    //                     curr->next = n;
    //                     curr->next->prev = curr;
    //                 }
    //                 if (curr->next != NULL)
    //                 {
    //                     n->next = curr->next;
    //                     n->prev = curr;
    //                     curr->next->prev = n;
    //                     curr->next = n;
    //                 }
    //                 cout << "HERE 7" << endl;
    //                 break;
    //             }
    //             curr = curr->next;
    //         }
    //     }
    //     length++;
    //     return;
    // }
    //-------
    // void remove(int pos)
    // {
    //     if (head == NULL)
    //     {
    //         cout << "List is empty" << endl;
    //     }
    //     if (pos < 1 || pos > length)
    //     {
    //         cout << "Invalid" << endl;
    //     }
    //     Book *curr = head;
    //     if (pos == 1)
    //     {
    //         head = head->next;
    //         if (head != NULL)
    //         {
    //             head->prev = NULL;
    //         }
    //         delete curr;
    //     }
    //     else
    //     {
    //         Book *slow = head;
    //         for (int i = 1; i < pos; i++)
    //         {
    //             slow = slow->next;
    //         }
    //         slow->next = curr->next;
    //         if (curr->next != NULL)
    //         {
    //             curr->next->prev = slow;
    //         }
    //         delete curr;
    //     }
    //     length--;
    // }
    void insert(int day, int month, int year, int isbn, string AuthorName, string booktitle, string Book_genre)
    {
        Book *newBook = new Book(isbn, AuthorName, booktitle, Book_genre, day, month, year);
        //newbook will contain all the essential information
        if (head == NULL)
        {
            head = newBook;
            length++;
            return;
        }
        //the above if statemnt is for when the list is empty

        Book *curr = head;
        /*the below loop is for finding the correct posiitons to insert the book
        according to the constraint provided in the questions....*/
        while (curr != NULL)
        {
            if (curr->getYear() > year || (curr->getYear() == year && curr->getMonth() > month) ||
                (curr->getYear() == year && curr->getMonth() == month && curr->getDay() > day))
            {
                //correct position to insert the new book : new book at position one
                if (curr == head)
                {
                    newBook->next = head;
                    head->prev = newBook;
                    head = newBook;
                }
                else //for insert between two nodes
                {
                    newBook->prev = curr->prev;
                    curr->prev->next = newBook;
                    newBook->next = curr;
                    curr->prev = newBook;
                }
                length++;
                return;
            }

            if (curr->next == NULL) //for last index
            {
                // and insert the new book at the end
                curr->next = newBook;
                newBook->prev = curr;
                length++;
                return;
            }

            curr = curr->next;
        }
    }
    void remove(int pos)
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            if(pos < 1 || pos > length)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            Book* curr = head;
            if(pos == 1)
            {
                head = head->next;
                if(head != NULL)
                {
                    head->prev = NULL;
                }
                delete curr;
            }
            else
            {
                for(int i = 1 ; i < pos ; i++)
                {
                    curr = curr->next;
                }
                curr->prev->next = curr->next;
                if(curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
                delete curr;
            }
            length--;
        }
    void printBooks()
    {
        Book *curr = head;
        tuple<int, int, int> tupple;
        while (curr != NULL)
        {
            tupple = curr->getDate();
            int day = get<0>(tupple);
            int month = get<1>(tupple);
            int year = get<2>(tupple);
            curr->getter();
            cout << "Book Date  :" << day << "/" << month << "/" << year << endl;
            curr = curr->next;
        }
    }
    bool find(int val)
        {
            Book* curr = head;
            for(int i = 1 ; i <= length ; i++)
             {
                    if(curr->getisbn() == val)
                    {
                        return  true;
                    }
                    curr = curr->next;


             }
                return false;
        }
        bool find(string val)
        {
            Book* curr = head;
            bool yes;
            for(int i = 1 ; i <= length ; i++)
             {
                    if(curr->getauthorname() == val)
                    {
                        cout<<"Book ISBN number     : "<<curr->getisbn()<<endl;
                        cout<<"Book Author Name     : "<<curr->getauthorname()<<endl;
                        cout<<"Book title           : "<<curr->gettitle()<<endl;
                        cout<<"Book Genre           : "<<curr->getgenre()<<endl;
                        cout<<"Publication Date     :"<<curr->getDay()<<"/"<<curr->getMonth()<<"/"<<curr->getYear()<<endl;
                        // return  true;
                        yes=true;
                    }
                    curr = curr->next;


             }
                return yes;
        }
        bool find(string val,int vall)
        {
            Book* curr = head;
            bool yes;
            int j=0;
            for(int i = 1 ; i <= length ; i++)
             {
                    if(curr->getgenre() == val)
                    {
                        j++;
                        cout<<"Recommending Book No : "<<j<<endl;    
                        cout<<"Book ISBN number     : "<<curr->getisbn()<<endl;
                        cout<<"Book Author Name     : "<<curr->getauthorname()<<endl;
                        cout<<"Book title           : "<<curr->gettitle()<<endl;
                        cout<<"Book Genre           : "<<curr->getgenre()<<endl;
                        cout<<"Publication Date     : "<<curr->getDay()<<"/"<<curr->getMonth()<<"/"<<curr->getYear()<<endl;
                        // return  true;
                        yes=true;
                    }
                    curr = curr->next;


             }
                return yes;
        }
};

//-------------------------------------

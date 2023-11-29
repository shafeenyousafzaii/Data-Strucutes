#include <iostream>
#include <cctype> //including for checking if an integer exist in the arugment or not
#include <math.h>
using namespace std;
class node
{
public:
    double data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    node *top;
    int length;

public:
    List()
    {
        top = NULL;
        length = 0;
    }
    ~List()
    {
        node *curr = NULL;
        while (top != NULL)
        {
            curr = top;
            top = top->next;
            delete curr;
        }
    }

    void push(int val)
    {
        node *n = new node(val);
        n->next = top;
        top = n;
        length++;
    }

    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        node *curr = top;
        char val = curr->data;
        top = top->next;
        delete curr;
        length--;
        return val;
    }
    int peak()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    void display()
    {
        node *curr = top;
        while (curr != NULL)
        {
            cout << curr->data << "";
            curr = curr->next;
        }
        cout << endl;
    }

    int Post_fix(string name)
    {
        int count = 0;
        int countt = 0;
        int resultt;
        // for (int i = 0; i < name.length(); i++)
        // {
        // }
        for (int i = 0; i < name.length(); i++)
        {
            char charr = name[i];
            char charr2 = name[i + 1];
            if (isdigit(charr) && isdigit(charr2))
            {
                string a = "";
                a = a + charr + charr2;
                // cout << "A :" << a << endl; // int num = stoi(a);
                // cout<<num;
                for (int j = i; j < name.length(); j++)
                {
                    if (isdigit(name[j]))
                    {
                        countt++;
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int j = 2; j <= countt; j++)
                {
                    a = a + name[j];
                    // i++;
                }
                int num = stoi(a);
                push(num);
            }
            else if (isdigit(charr))
            {
                string a = "";
                a = a + charr;
                // cout<<"A :"<<a<<endl;                // int num = stoi(a);
                // countt++;
                int num = stoi(a);
                // cout<<num;
                push(num);
            }
            else if (isspace(charr))
            {
                continue;
                // cout << charr;
                // cout<<"  space";
            }
            else if (charr == '+')
            {
                int num2 = pop();
                int num1 = pop();

                // cout << "Num 1 : " << num1 << " Num 2 : " << num2 << "  " << endl;

                int result = num1 + num2;
                push(result);
            }
            else if (charr == '-')
            {
                int num2 = pop();
                int num1 = pop();
                // cout << "Num 1 : " << num1 << " Num 2 : " << num2 << "  " << endl;

                int result = num1 - num2;

                // cout<<num1<<endl;
                // cout<<num2<<endl;
                // cout<<result<<endl;
                push(result);
            }
            else if (charr == '*')
            {
                int num2 = pop();
                int num1 = pop();
                // cout << "Num 1 : " << num1 << " Num 2 : " << num2 << "  " << endl;
                int result = num1 * num2;
                push(result);
            }
            else if (charr == '/')
            {
                int num2 = pop();
                if (num2 == 0)
                {
                    cout << "Undefined result of division with 0" << endl;
                    continue;
                }
                else
                {
                    int num1 = pop();
                    // cout << "Num 1 : " << num1 << " Num 2 : " << num2 << "  " << endl;

                    int result = num1 / num2;
                    push(result);
                }
            }
            else if (charr == '^')
            {
                int num2 = pop();
                int num1 = pop();
                // cout << "Num 1 : " << num1 << " Num 2 : " << num2 << "  " << endl;

                int result = pow(num1, num2);
                push(result);
            }
            if (i + 1 >= name.length())
            {
                int result = pop();
                cout << endl;
                // display();
                for (int i = 0; i < length; i++)
                {
                    int num = pop();
                    result += num;
                }
                push(result);
                // cout << result << endl;
                resultt=result;
                return result;
            }
            count++;
        }
        return resultt;
    }
};

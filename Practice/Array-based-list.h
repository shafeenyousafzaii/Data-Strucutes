#include<iostream>
using namespace std;
class arrayList{
    private:
    int *arr;
    int *curr;
    int capacity;
    int len;
    public:
    arrayList(int size );
    ~arrayList();
    void createArraylist();
    void copy();
    void clear();
    void insert(int x, int pos);
    void remove(int x);
    void get();
    void update(int x, int pos);
    void find(int x);
    void length();
    void start();
    void tail();
    void next();
    void back();
};

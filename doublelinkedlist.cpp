#include <iostream>
#include <string>
using namespace std;

class node 
{
    public:
        int noMhs;
        node *next;
        node *prev;
};

class doublelinkedlist
{
    private :
        node *START;
        
    public :
        doublelinkedlist()
        {
            START = NULL;
        }

    void addnote()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student";
        cin >> nim;
    }
}
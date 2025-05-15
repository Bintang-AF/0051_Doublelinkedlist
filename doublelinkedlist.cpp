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

        //step 1 : Allcate memory for new node
        node *newnode = new node ();

        //step 2 : assign value to the data fields
        newnode-> noMhs = nim;

        //step 3 insert at beginning 
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed  "<< endl;
                return ;

            }
            // step 4: newnode.next = START
            newnode-> next = START;

            // step 5 : start.prev = newnode (if start exist)
            if (START != NULL)
            START-> prev = NULL;
        }

    }

}
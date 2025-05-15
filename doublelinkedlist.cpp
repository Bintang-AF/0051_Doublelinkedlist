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

            newnode -> prev = NULL;

            START = newnode ;
            return;
        }

        node *current = START;
        while (current->next != NULL && current -> next->noMhs < nim)
        {
            current = current-> next;
        }

        if (current->next !=NULL && nim == current ->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed"<< endl;
            return;
        }

        newnode->next = current->next;
        newnode->prev = current;

        if (current -> next != NULL)
            current ->next -> prev = newnode; 



    }

    void hapus()
    {
        if (START == NULL){
            cout << "\nList is empty"<< endl;
            return ;

        }

        cout << "\nEnter the roll number of the student whose record is to be deleted : ";
        int rollNo;
        cin >> rollNo;

        node *current = START;

        while (current != NULL && current -> noMhs != rollNo)
            current = current->next;
        
        if (current == NULL)
        {
            cout << "Record not found " << endl;
            return;
        }

        if (current == START)
        {
            START = current ->next;
            if (START != NULL)
                START -> prev = NULL;
        }
        else
        {
            current ->prev->next = current-> next;

            if (current->next != NULL)
            current-> next ->prev = current ->prev;
        }
    }

}
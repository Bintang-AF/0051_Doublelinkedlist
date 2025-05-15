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

    void addnode()
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

            delete current ;
            cout << "Record with roll number "<< rollNo << "deleted " << endl;
        }


    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty"<< endl;
            return;
        }

        node *currentnode = START;

        cout << "\nRecord in ascending order of roll number are: \n";
        int i = 0;
        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode ->noMhs << " "<< endl;

            currentnode = currentnode ->next;
            i++;

        }
    }

    void retraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty"<< endl;
            return;
        }

        node *currentnode = START;
        int i = 0;
        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }

        cout << "\nRecord in descending order of roll number are:\n";
        while (currentnode != NULL)
        {
            cout << i + 1 << ". "<< currentnode -> noMhs << " "<< endl;

            currentnode = currentnode -> prev;
            i--;
        }
    }

    void searchdata()
    {
        if (START == NULL)
        {
            cout << "\nList is empty"<< endl;
            return ;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        node *current = START;

        while (current != NULL && current ->noMhs != rollNo )
        current = current -> next;

        if (current == NULL)
        {
            cout << "record not found\n";
        }
        else 
        {
            cout << "record found\n";
            cout << "roll number: "<< current->noMhs << endl; 
        }
    }

};

int main()
{
    doublelinkedlist list;
    char choice ;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Add record\n";
        cout << "2. delete record\n";
        cout << "3. view ascending\n";
        cout << "4. view descending\n";
        cout << "5. search record \n";
        cout << "6. exit \n";
        cout << "enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
                list.addnode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.retraverse();
                break;
            case '5':
                list.searchdata();
                break;
            case '6':
                return 0;
            default :
                cout << "invalid option\n";

        }
        cout << "\nPress enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    }while (choice != '6');
}
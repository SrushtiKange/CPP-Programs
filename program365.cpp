#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public :
       PNODE First;//this will point to first node of linked list
       int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    
};

SinglyLL::SinglyLL()
       {
        cout<<"Inside constructor\n";
        First=NULL;
        iCount=0;
       }

void SinglyLL::Display()
{

}

int SinglyLL::Count()
{
    return iCount;

}

void SinglyLL::InsertFirst(int No)
{
    PNODE newn=NULL;

    newn=new NODE;//allocate memory for new node jasa c madhe malloc use kelta

    newn->data=No;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;

    }
    else
    {
        newn->next=First;
        First=newn;
    }
    iCount++;
}

void SinglyLL::InsertLast(int No)
{

}

void SinglyLL::InsertAtPos(int No,int iPos)
{

}

void SinglyLL::DeleteFirst()
{

}

void SinglyLL::DeleteLast()
{

}

void SinglyLL::DeleteAtPos(int iPos)
{

}

int main()
{
    SinglyLL obj;

    int iRet=0;
    iRet=obj.Count();
    cout<<"Number of elements in linked list are : "<<iRet<<"\n";

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    iRet=obj.Count();
    cout<<"Number of elements in linked list are : "<<iRet<<"\n";



    return 0;
}
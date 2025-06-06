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
    PNODE temp=First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL";

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
    PNODE newn=NULL;
    PNODE temp=NULL;

    newn=new NODE;

    newn->data=No;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        temp=First;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;

}

void SinglyLL::InsertAtPos(int No,int iPos)
{

}

void SinglyLL::DeleteFirst()
{
    PNODE temp=First;
    if(First==NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        First=First->next;
        delete temp;
    }
    iCount--;
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

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet=obj.Count();
    cout<<"\nNumber of elements in linked list are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of elements in linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of elements in linked list are : "<<iRet<<"\n";


    return 0;
}
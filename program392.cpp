#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;

};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCL
{
    private:
        PNODE First;
        PNODE Last;
        int iCount;
    public:
        DoublyCL();
        
        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL::DoublyCL()
{
    First=NULL;
    Last=NULL;
    iCount=0;

}

void DoublyCL::Display()
{
    if((First==NULL) && (Last==NULL))
    {
        cout<<"Linked List is Empty\n";
        return;
    }
    cout<<"<=>";
    do
    {
        cout<<"|"<<First->data<<"|<=>";
        First=First->next;
    }while(First!=Last->next);
    cout<<"\n";
}

int DoublyCL::Count()
{
    return iCount;
}

void DoublyCL::InsertFirst(int No)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    if((First==NULL) && (Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
    }
    Last->next=First;
    First->prev=Last;

    iCount++;

}

void DoublyCL::InsertLast(int No)
{
    PNODE newn=NULL;
    newn=new NODE;

    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    if((First==NULL) && (Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        Last->next=newn;
        newn->prev=Last;
        Last=newn;
    }
    Last->next=First;
    First->prev=Last;

    iCount++;

}

void DoublyCL::InsertAtPos(int No,int iPos)
{

}

void DoublyCL::DeleteFirst()
{

}

void DoublyCL::DeleteLast()
{

}

void DoublyCL::DeleteAtPos(int iPos)
{

}


int main()
{
    int iRet=0;

    DoublyCL obj;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of elements in Linked List are : "<<iRet<<"\n";
    return 0;
}
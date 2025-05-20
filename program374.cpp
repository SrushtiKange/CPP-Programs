#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;

};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private:
        PNODE First;
        int iCount;
    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

DoublyLL::DoublyLL()
{
    cout<<"Inside constructor\n";
    First=NULL;
    iCount=0;
};

void DoublyLL::Display()
{
    PNODE temp=First;
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp=temp->next;
    }
    cout<<"NULL";
   
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int No)
{
    PNODE newn=NULL;

    newn = new NODE;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    if(First==NULL)
    {
         First=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;

    }
    iCount++;

}

void DoublyLL::InsertLast(int No)
{
    PNODE newn=NULL;
    PNODE temp=NULL;

    newn = new NODE;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

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
        newn->prev=temp;

    }
    iCount++;

}

void DoublyLL::InsertAtPos(int No,int iPos)
{

    int Length=iCount,i=0;
    PNODE newn=NULL;
    PNODE temp=First;

     if((iPos<1) || (iPos>Length+1))
    {
        cout<<"Out of range\n";
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);

    }
    else if(iPos==Length+1)
    {
        InsertLast(No);
    }
    else
    {
        newn=new NODE;
        newn->data=No;
        newn->prev=NULL;
        newn->next=NULL;

        for(i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

        iCount++;
    }

}

void DoublyLL::DeleteFirst()
{
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
        delete First->prev;
        First->prev=NULL;

    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
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
       PNODE temp=First;
       while(temp->next->next!=NULL)
       {
        temp=temp->next;

       }
       delete temp->next;
       temp->next=NULL;
    }
    iCount--;

}

void DoublyLL::DeleteAtPos(int iPos)
{
    int Length=iCount,i=0;
    PNODE temp=First;

     if((iPos<1) || (iPos>Length))
    {
        cout<<"Out of range\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();

    }
    else if(iPos==Length)
    {
        DeleteLast();
    }
    else
    {
       for(i=1;i<iPos-1;i++)
       {
        temp=temp->next;
       }
        
       temp->next=temp->next->next;
       delete temp->next->prev;
       temp->next->prev=temp;
       iCount--;
    }

}



int main()
{
    DoublyLL obj;
    int iRet=0;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);

    obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of nodes are:"<<iRet<<endl;

    obj.InsertLast(101);
    obj.InsertLast(102);
    obj.InsertLast(103);   
 
    obj.Display(); 

    iRet=obj.Count();
    cout<<"\nNumber of nodes are: "<<iRet<<endl;

    obj.DeleteFirst();
     obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of nodes are:"<<iRet<<endl;

    obj.DeleteLast();
     obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of nodes are:"<<iRet<<endl;

    obj.InsertAtPos(50,3);
    obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of nodes are:"<<iRet<<endl;

    obj.DeleteAtPos(2);
    obj.Display();
    iRet=obj.Count();
    cout<<"\nNumber of nodes are:"<<iRet<<endl;


    return 0;
}
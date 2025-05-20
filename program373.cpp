#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    private :
       PNODE First;//this will point to first node of linked list
       int iCount;

    public:
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
    PNODE newn=NULL;
    int i=0;
    PNODE temp;

    if((iPos<1) || (iPos>iCount+1))
    {
        cout<<"invalid pos\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp=First;
        newn=new NODE;
        newn->data=No;
        newn->next=NULL;

        for(i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;

        iCount++;

    }

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
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    iCount--;

}

void SinglyLL::DeleteAtPos(int iPos)
{
    
    int i=0;
    PNODE temp1;
    PNODE temp2;

    if((iPos<1) || (iPos>iCount))
    {
        cout<<"invalid pos\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1=First;
       
        for(i=1;i<iPos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
    
        iCount--;

    }

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

   obj.InsertAtPos(105,5);
   obj.Display();
   iRet=obj.Count();
   cout<<"\nNumber of elements in linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
   iRet=obj.Count();
   cout<<"\nNumber of elements in linked list are : "<<iRet<<"\n";


    return 0;
}
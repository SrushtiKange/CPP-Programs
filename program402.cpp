#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Queue
{
    private:
        PNODE First;
        int iCount;
    public:
        Queue();
        
        void Display();
        int Count();
        
        void Enqueue(int No);//InsertLast
        int Dequeue();//DeleteFirst
};

Queue::Queue()
{
    First=NULL;
    iCount=0;
}

void Queue::Display()
{
    cout<<"Queue Elements are: ";
    PNODE temp=First;

    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return iCount;
}

void Queue::Enqueue(int No)
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

int Queue::Dequeue()
{
    int iValue=0;
    PNODE temp=NULL;

    if(First==NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    else
    {
        temp=First;
        
       iValue=First->data;
       First=First->next;
       delete temp;

        iCount--;

    }
    return iValue;
}

int main()
{
    int iRet=0;
    Queue obj;

    obj.Enqueue(10);
    obj.Enqueue(20);
    obj.Enqueue(30);
    obj.Enqueue(40);

    obj.Display();

    iRet=obj.Count();
    cout<<"Number of Elements in que are:\n "<<iRet<<"\n";

    iRet=obj.Dequeue();
    cout<<"Element removed is: "<<iRet<<"\n";

    obj.Display();
     iRet=obj.Dequeue();
    cout<<"Element removed is: "<<iRet<<"\n";

    iRet=obj.Count();
    cout<<"Number of Elements in queue are:"<<iRet<<"\n";

    obj.Enqueue(50);
     obj.Display();
     iRet=obj.Count();
    cout<<"Number of Elements in queue are:"<<iRet<<"\n";



    return 0;
}
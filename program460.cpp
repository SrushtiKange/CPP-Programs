#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        int Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T No);
        bool Search(T No);
        int SearchFirstOccurance(T No);
        int SearchLastOccurance(T No);
        int SumDigits(); 
        int SumFactors();
        bool CheckPerfect();
        int MiddleElement();
        int Reverse();
        bool CheckLoop();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

template <class T>
int SinglyLL<T>::Addition()
{
    struct nodeSL<T> * temp = First;
    int iSum = 0;

    while(temp != NULL)
    {
        iSum = iSum + (temp->data);
        temp = temp -> next;
    }
    return iSum;
}

template <class T>
int SinglyLL<T>::EvenCount()
{
    struct nodeSL<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iCnt++;
        }
        temp = temp -> next;
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>::OddCount()
{
    struct nodeSL<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        if((temp->data) % 2 !=0)
        {
            iCnt++;
        }
        temp = temp -> next;
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>::Frequency(T No)
{
    struct nodeSL<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iCnt++;
        }
        temp = temp -> next;
    }
    return iCnt;
}

template <class T>
bool SinglyLL<T>::Search(T No)
{
    bool bFlag = false;
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            flag = true;
            break;
        }
        temp = temp -> next;
    }
    return bFlag;
}

template <class T>
int SinglyLL<T>::SearchFirstOccurance(T No)
{
    int iPos =-1;
    int iCnt=0;
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp -> next;
    }
   return iPos;
}

template <class T>
int SinglyLL<T>::SearchLastOccurance(T No)
{ 
    int iPos =-1;
    int iCnt=0;
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp -> next;
    }
   return iPos;
}

template <class T>
int SinglyLL<T>::SumDigits()
{
    struct nodeSL<T> * temp = First;
    int iSum = 0;
    int iNo = 0, iDigit = 0;

    while(temp != NULL)
    {
         iNo = temp -> data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        printf("%d\n",iSum);
        iSum = 0;

        temp = temp -> next;
    }
    return iSum;
}

template <class T>
int FactorsAddition(T No)
{
    int iSum = 0;
    int i = 0;

    for(i = 1; i <= No/2; i++)
    {
        if(No % i == 0)
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}
 
template <class T>
int SinglyLL<T>::SumFactors()
{
     struct nodeSL<T> * temp = First;
    while(temp != NULL)
    {
        printf("%d\n",FactorsAddition(temp->data));
        temp = temp -> next;
    } 
}

template <class T>
bool SinglyLL<T>::CheckPerfect()
{
    struct nodeSL<T> * temp = First;
    int iSum = 0;
    int iNo = 0, i = 0;

    while(temp != NULL)
    {
        iNo = temp -> data;

        for(i = 1; i <= iNo/2; i++)
        {
            if(iNo % i == 0)
            {
                iSum = iSum + i;
            }
        }
        if(iSum == iNo)
        {
            return true;
        }
        else
        {
            return false;
        }
        iSum = 0;
        temp = temp -> next;
    }
}

template <class T>
int SinglyLL<T>::MiddleElement()
{
    struct nodeSL<T> * temp = First;
    int iCnt = 0,iPos=0; 

    while(temp!=NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    iPos=iCnt/2;
    for(i=1;i<=iPos;i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
int SinglyLL<T>::Reverse()
{
    struct nodeSL<T> * temp = First;
    struct nodeSL<T> * prev = NULL;
    struct nodeSL<T> * Next = NULL;

    while(temp != NULL)
    {
        Next = temp -> next;
        temp -> next = prev;
        prev = temp;

        temp = Next;
    }
    First = prev;
}

template <class T>
bool SinglyLL<T>::CheckLoop()
{
    struct nodeSL<T> * teacher = First;
    struct nodeSL<T> * student = First;
    bool bFlag=false;

    while((teacher!=NULL) && (teacher->next!=NULL))
    {
        teacher=teacher->next->next;

        if(teacher==student)
        {
            bFlag=true;
            break;
        }
        student=student->next;

        if(teacher==student)
        {
            bFlag=true;
            break;
        }
    }  
    return bFlag;
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Liear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    int data;
    struct nodeDL<T> *next;
    struct nodeDL<T> *prev;

};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;
    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No); 
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside constructor\n";
    First=NULL;
    iCount=0;
};

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp=First;
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp=temp->next;
    }
    cout<<"NULL";
   
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn=NULL;

    newn = new nodeDL<T>;
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

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn=NULL;
    struct nodeDL<T> * temp=NULL;

    newn = new nodeDL<T>;
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

template <class T>
void DoublyLL<T>::InsertAtPos(T No,int iPos)
{

    int Length=iCount,i=0;
    struct nodeDL<T> * newn=NULL;
    struct nodeDL <T>* temp=First;

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
        newn=new nodeDL<T>;
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
template <class T>
void DoublyLL<T>::DeleteFirst()
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

template <class T>
void DoublyLL<T>::DeleteLast()
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
       struct nodeDL<T> * temp=First;
       while(temp->next->next!=NULL)
       {
        temp=temp->next;

       }
       delete temp->next;
       temp->next=NULL;
    }
    iCount--;

}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int Length=iCount,i=0;
    struct nodeDL<T>* temp=First;

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

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    int data;
    struct nodeSC<T> *next;
};

template <class T>
class SinglyCL
{
    private:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

template <class T>
SinglyCL<T>::SinglyCL()
{ 
    First=NULL;
    Last=NULL; 
    iCount=0; 

}

template <class T>
void SinglyCL<T>::Display()
{
    struct nodeSC<T> * temp=First;
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }while(temp!=Last->next);

}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{  
    struct nodeSC<T> * newn=NULL;
    newn=new nodeSC<T>;
    newn->data=No;
    newn->next=NULL;

     if(First==NULL && Last==NULL)
     {
        First=newn;
        Last=newn;
     }
     else
     {
        newn->next=First;
        First=newn;
     }
     Last->next=First; 
     iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn=NULL;
    newn=new nodeSC<T>;
    newn->data=No;
    newn->next=NULL;

     if(First==NULL && Last==NULL)
     {
        First=newn;
        Last=newn;
     }
     else
     {
        Last->next=newn;
         Last=newn;
       
     }
     Last->next=First;
     iCount++;

}

template <class T>
void SinglyCL<T>::InsertAtPos(T No,int iPos)
{
    int i=0,iLength=iCount;
    struct nodeSC<T> * temp=NULL;
    struct nodeSC<T> * newn=NULL;

    if((First==NULL) && (Last==NULL))
    {
        cout<<"LL is empty";
        return;
    }
   if(iPos==1)
   {
    InsertFirst(No);
   }
   else if(iPos==iLength+1)
   {
    InsertLast(No);
   }
   else
   {
    newn=new nodeSC<T>;
    newn->data=No;
    newn->next=NULL;
    temp=First;

   for(i=1;i<iPos-1;i++)
    {
        temp=temp->next;
    }
    newn->next=temp->next;
    temp->next=newn;

    iCount++;
   }

}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First==NULL) && (Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        First=First->next;
        delete Last->next;
        Last->next=First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast() 
{
     if((First==NULL) && (Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        struct nodeSC<T> * temp=First;    
        while(temp->next!=Last)
        {
            temp=temp->next;
        }
        delete temp->next;
        Last=temp;
        Last->next=First;
    }
    iCount--;

}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i=0,iLength=iCount;
    struct nodeSC<T> * temp1=NULL;
    struct nodeSC<T> * temp2=NULL;
   
    if((First==NULL) && (Last==NULL))
    {
        cout<<"LL is empty";
        return;
    }
   if(iPos==1)
   {
    DeleteFirst();
   }
   else if(iPos==iLength)
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

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    int data;
    struct nodeS<T> *next;

};

template <class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;
    public:
        Stack();
        
        void Display();
        int Count();
        
        void Push(T No);//InsertFirst
        int Pop();//DeleteFirst
};

template <class T>
Stack<T>::Stack()
{
    First=NULL;
    iCount=0;

}

template <class T>
void Stack<T>::Display()
{
    cout<<"Stack Elements are: \n";
    struct nodeS<T> * temp=First;

    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T> * newn=NULL;
    newn=new nodeS<T>;

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

template <class T>
int Stack<T>::Pop()
{
    int iValue=0;
    struct nodeS<T> * temp=NULL;

    if(First==NULL)
    {
        cout<<"Stack is Empty\n";
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


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    int data;
    struct nodeQ<T> *next;

};

template <class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;
    public:
        Queue();
        
        void Display();
        int Count();
        
        void Enqueue(T No);//InsertLast
        int Dequeue();//DeleteFirst
};

template <class T>
Queue<T>::Queue()
{
    First=NULL;
    iCount=0;

}

template <class T>
void Queue<T>::Display()
{
    cout<<"Queue Elements are: ";
    struct nodeQ<T> * temp=First;

    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::Enqueue(T No)
{
    struct nodeQ<T> * newn=NULL;
    struct nodeQ<T> * temp=NULL;
    newn=new nodeQ<T>;

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

template <class T>  
int Queue<T>::Dequeue()
{
    int iValue=0;
    struct nodeQ<T> * temp=NULL;

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

/////////////////////////////////////////////////////////////
//
// Code of Binary Search Tree
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeBST
{
    int data;
    struct nodeBST * lchild;
    struct nodeBST * rchild;
};

template <class T>
class BST
{
    public:
        struct nodeBST<T> * Root; 
 
        BST();
        void Insert(T No);

        void Inorder(struct nodeBST<T> * Root);
        void Preorder(struct nodeBST<T> * Root);
        void Postorder(struct nodeBST<T> * Root);

        bool Search(T No); 
        int CountLeaf(struct nodeBST<T> * Root);
        int CountParent(struct nodeBST<T> * Root);
        int CountAll(struct nodeBST<T> * Root); 
    
};

template <class T>
BST<T>::BST()
{
    //cout<<"Inside Constructor\n";
    Root = NULL;
}

template <class T>
void BST<T>::Insert(T No)
{
    struct nodeBST<T> * newn=NULL;
    struct nodeBST<T> * temp=NULL;

    newn=new struct nodeBST<T>;

    newn->data=No;
    newn->lchild=NULL;
    newn->rchild=NULL; 

    if(Root==NULL)
    {
        Root=newn;
    }
    else
    {
        temp=Root;

        while(1)
        {
            if(temp->data==No)
            {
                cout<<"Duplicate Element not allowed\n";
                delete newn;
                break;
            }
            else if(No>temp->data)
            {
               if(temp->rchild==NULL)
               {
                   temp->rchild=newn;
                   break;
               }
                temp=temp->rchild;
            }
            else if(No<temp->data)
            {
                if(temp->lchild==NULL)
                {
                    temp->lchild=newn;
                    break;
                }
                temp=temp->lchild;
            }
        }
    }
}

template <class T>
void BST<T>::Inorder(struct nodeBST<T> * Root)
{
    if(Root!=NULL)
    {
        Inorder((Root)->lchild);
        cout<<Root->data<<"\t";
        Inorder((Root)->rchild);
    }
}

template <class T>
void BST<T>::Preorder(struct nodeBST<T> * Root)
{
    if(Root!=NULL)
    {
        cout<<Root->data<<"\t";
        Preorder((Root)->lchild);
        Preorder((Root)->rchild);
    }
}

template <class T>
void BST<T>::Postorder(struct nodeBST<T> * Root)
{
    if(Root!=NULL)
    {
        Postorder((Root)->lchild);
        Postorder((Root)->rchild);
        cout<<Root->data<<"\t";
        
    }
}

template <class T>
bool BST<T>::Search(T No)
{
    bool flag=false;

    if(Root==NULL)
    {
        cout<<"Tree is empty\n";
        return flag;
    }

    while(Root!=NULL)
    {
        if(Root->data==No)
        {
            flag=true;
            break;
        }
        else if(No>Root->data)
        {
            Root=Root->rchild;
        }
        else if(No<Root->data)
        { 
            Root=Root->lchild;
        }
    }
    return flag;
}

template <class T>
int BST<T>::CountLeaf(struct nodeBST<T> * Root)
{
    static int iCnt=0;

    if(Root!=NULL)
    {
        if(Root->lchild==NULL && Root->rchild==NULL)
        {
            iCnt++;
        }
        CountLeaf((Root)->lchild);
        CountLeaf((Root)->rchild);
    }
    return iCnt;
}

template <class T>
int BST<T>::CountParent(struct nodeBST<T> * Root)
{
    static int iCnt=0;

    if(Root!=NULL)
    {
        if(Root->lchild!=NULL || Root->rchild!=NULL) 
        {
           iCnt++;
        }
        CountParent((Root)->lchild);
        CountParent((Root)->rchild);
    }
    return iCnt;
}

template <class T>
int BST<T>::CountAll(struct nodeBST<T> * Root)
{
    static int iCnt=0;

    if(Root!=NULL)
    {
        iCnt++;
        CountAll((Root)->lchild);
        CountAll((Root)->rchild);
    }
    return iCnt;
} 

/////////////////////////////////////////////////////////////
//
// Code of Searching and Sorting algorithms
//
/////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize; 

        ArrayX(int Value);
        ~ArrayX();

        void Accept();
        void Display();
        
        bool LinearSearch(T Value);
        bool BiDirectionalSearch(T Value);
        bool BinarySearch(T Value);

        void BubbleSort();
        void BubbleSortEfficient();

        void SelectionSort();

        void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
}

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    int iStart = 0, iEnd = 0;
    bool flag = false;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
                flag = true;
                break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if(Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(Value > Arr[iMid])
        {
            iEnd = iMid -1;
        }
    }

    return flag;
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    //     1        2      3  
    for(i = 0; i < iSize -1; i++)  // Outer
    {   //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}   

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; (i < iSize -1) && (flag == true) ; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
    
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize -1; i++)
    {
        min_index = i;

        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}  

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for(i =1 ; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}  


/////////////////////////////////////////////////////////////

// Entry point function

///////////////////////////////////////////////////////////////

int main()
{
    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertAtPos('W',5);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    SinglyLL<float> *fobj = new SinglyLL<float>();

    fobj->InsertFirst(90.78f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertAtPos(88.56,5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double

    cout<<"-------------- LinkdList of Doubles --------------\n";

    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertAtPos(88.56987,5);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    DoublyCL<int> *idobj = new DoublyCL<int>();

    idobj->InsertFirst(51);
    idobj->InsertFirst(21);
    idobj->InsertFirst(11);
    
    idobj->InsertLast(101);
    idobj->InsertLast(111);
    idobj->InsertLast(121);
    
    idobj->Display();
    iRet = idobj->Count();

    idobj->DeleteAtPos(5);
    
    idobj->Display();
    iRet = idobj->Count();
    return 0;
}
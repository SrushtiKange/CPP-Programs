#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE; 

class BST
{
    private:
        PNODE Root;
    public:
        BST();
        void Insert(PPNODE Root,int No);

        void Inorder(PNODE Root);
        void Preorder(PNODE Root);
        void Postorder(PNODE Root);

        bool Search(PNODE Root,int No); 
        int CountLeaf(PNODE Root);
        int CountParent(PNODE Root);
        int CountAll(PNODE Root); 
    
};

BST::BST()
{
    cout<<"Inside Constructor\n";
    Root = NULL;
}

void BST::Insert(PPNODE Root,int No)
{
    PNODE newn=NULL;
    PNODE temp=NULL;

    newn=new NODE;
    newn->data=No;
    newn->lchild=NULL;
    newn->rchild=NULL; 

    if(*Root==NULL)
    {
        *Root=newn;
    }
    else
    {
        temp=*Root;

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

void BST::Inorder(PNODE Root)
{
    if(Root!=NULL)
    {
        Inorder(Root->lchild);
        cout<<Root->data<<"\t";
        Inorder(Root->rchild);
    }
}

void BST::Preorder(PNODE Root)
{
    if(Root!=NULL)
    {
        cout<<Root->data<<"\t";
        Preorder(Root->lchild);
        Preorder(Root->rchild);
    }
}

void BST::Postorder(PNODE Root)
{
    if(Root!=NULL)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        cout<<Root->data<<"\t";
        
    }
}

bool BST::Search(PNODE Root,int No)
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

int BST::CountLeaf(PNODE Root)
{
    static int iCnt=0;

    if(Root!=NULL)
    {
        if(Root->lchild==NULL && Root->rchild==NULL)
        {
            iCnt++;
        }
        CountLeaf(Root->lchild);
        CountLeaf(Root->rchild);
    }
    return iCnt;
}

int BST::CountParent(PNODE Root)
{
    static int iCnt=0;

    if(Root!=NULL)
    {
        if(Root->lchild!=NULL || Root->rchild!=NULL) 
        {
           iCnt++;
        }
        CountParent(Root->lchild);
        CountParent(Root->rchild);
    }
    return iCnt;
}

int BST::CountAll(PNODE Root)
{
    static int iCnt=0;

    if(Root!=NULL)
    {
        iCnt++;
        CountAll(Root->lchild);
        CountAll(Root->rchild);
    }
    return iCnt;
} 


int main()
{
    BST obj;
    PNODE Head=NULL;
    bool bret=false;
    int iRet=0;

    obj.Insert(&Head,27);
    obj.Insert(&Head,51);
    obj.Insert(&Head,31);
    obj.Insert(&Head,10);
    obj.Insert(&Head,5);
    obj.Insert(&Head,38);
    obj.Insert(&Head,25);

    cout<<"Inorder Traversal\n"; 
    obj.Inorder(Head);

    cout<<"\nPreorder Traversal\n";
    obj.Preorder(Head);

    cout<<"\nPostorder Traversal\n";
    obj.Postorder(Head);

    bret=obj.Search(Head,25);
    if(bret==true)
    {
        cout<<"\nElement is present\n";
    }
    else
    {
        cout<<"\nElement is not present\n";
    }

    iRet=obj.CountLeaf(Head);
    cout<<"Number of leaf nodes are : "<<iRet<<"\n";

    iRet=obj.CountParent(Head);
    cout<<"Number of parent nodes are : "<<iRet<<"\n";

    iRet=obj.CountAll(Head);
    cout<<"Number of all nodes are : "<<iRet<<"\n";
    
    

    return 0;
}
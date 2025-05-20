#include<iostream>
using namespace std;

class ArrayX
{
    public:
    int *Arr;
    int iSize;

    ArrayX(int no)
    {
        iSize=no;
        Arr=new int[iSize];
    }

    ArrayX()
    {
        delete []Arr;
    }

    void Accept()
    {
        int i=0;

        cout<<"Enter the elements";

        for(i=0;i<iSize;i++)
        {
            cin>>Arr[i];
        }
    }

    void Display()
    {
        int i=0;

        cout<<"The elements are";

        for(i=0;i<iSize;i++)
        {
            cout<<Arr[i]<<"\n";
        }

    }

    int Addition()
    {
        int iSum=0,i=0;
        for(i=0;i<iSize;i++)
        {
            iSum=iSum+Arr[i];
        }
        return iSum;
    
    }
};

int main()
{
    int iRet=0;
    ArrayX aobj(5);

    aobj.Accept();
    aobj.Display();

    iRet=aobj.Addition();
    cout<<"Addition of elements is "<<iRet<<"\n";

    return 0;
}
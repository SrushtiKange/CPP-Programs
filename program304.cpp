#include<iostream>
using namespace std;

int CountEven(int Arr[],int iSize)
{
    int i=0,iCnt=0;

    for(i=0;i<iSize;i++)
    {
        if(Arr[i]%2==0)
        {
            iCnt++;
        }
    }
    return iCnt;
}

int main()
{
   int *Arr=NULL;
   int iCount=0,i=0,iRet=0;

   cout<<"Enter number of elements\n";
   cin>>iCount;

   Arr=new int[iCount];

   cout<<"Enter the values\n";
   for(i=0;i<iCount;i++)
   {
    cin>>Arr[i];
   }

    iRet=CountEven(Arr,iCount);
    cout<<"Number of even elements are "<<iRet<<endl;

    delete []Arr;
    
    return 0;
}
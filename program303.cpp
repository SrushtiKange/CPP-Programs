#include<iostream>
using namespace std;



int main()
{
   int *Arr=NULL;
   int iCount=0,i=0;

   cout<<"Enter number of elements\n";
   cin>>iCount;

   Arr=new int[iCount];

   cout<<"Enter the values\n";
   for(i=0;i<iCount;i++)
   {
    cin>>Arr[i];
   }

    cout<<"Entered elements are\n";
    for(i=0;i<iCount;i++)
    {
        cout<<Arr[i]<<endl;
    }

    delete []Arr;
    
    return 0;
}
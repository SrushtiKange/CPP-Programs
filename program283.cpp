#include<iostream>
using namespace std;
//Approach 1 using for loop
int Addition(int iNo)
{
    static int i=0;
    static int iSum=0;

    if(i<=iNo)
    {
        iSum=iSum+i;
        i++;
        Addition(iNo);
    }
 return iSum;
    
}

int main()
{
    int iValue=0,iRet=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet=Addition(iValue);

    cout<<"Addition is:"<<iRet<<endl;

    return 0;
}
#include<iostream>
using namespace std;
//Approach 1 using for loop
int Addition(int iNo)
{
    static int iSum=0;

   if(iNo>=1)
   {
       iSum=iSum+iNo;
       iNo--;
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
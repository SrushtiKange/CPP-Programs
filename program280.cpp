#include<iostream>
using namespace std;
//Approach 1 using for loop
void Display(int iNo)
{

   if(iNo>=1)
   {
       cout<<iNo<<endl;
       iNo--;
       Display(iNo);
   }    
  
}

int main()
{
    int iValue=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    Display(iValue);

    cout<<"End of application"<<endl;

    return 0;
}
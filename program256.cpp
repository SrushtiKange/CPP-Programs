#include<iostream>
using namespace std;

bool strcmpX(char *first,char *second)
{

   while((*first!='\0') && (*second!='\0'))
   {
    if(*first!=*second)
    {
        break;
    }
    first++;
    second++;
   }

   if(*first=='\0' && *second=='\0')
   {
    return true;
   }
   else
   {
    return false;
   }

}


int main()
{
    char Arr[30];
    char Brr[30];
    bool bRet=false;

   cout<<"Enter first str:"<<endl;
   cin.getline(Arr,30);

   cout<<"Enter second str:"<<endl;
   cin.getline(Brr,30);

    bRet=strcmpX(Arr,Brr);

    if (bRet==true)
    {
        cout<<"String are identical"<<endl;
    }
    else
    {
        cout<<"Not identical"<<endl;
    }

    return 0;
}
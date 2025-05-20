#include<iostream>
using namespace std;

void strcpyspaceX(char *Dest,char *Src)
{
    while(*Src!='\0')
    {
        if(*Src!=' ')
        {
            *Dest=*Src;

             Dest++;
        }
      Src++;
    }

    *Dest='\0';//navin string sampli he sangayla \0 takle ahee
}

int main()
{
    char Arr[30];
    char Brr[30];

    cout<<"Enter source string"<<endl;
    cin.getline(Arr,30);

    strcpyspaceX(Brr,Arr);  //strcpyX(200,100)

    cout<<"Copied string is:"<<Brr<<endl;

    return 0;
}
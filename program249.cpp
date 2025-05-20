#include<iostream>
using namespace std;

void strcpyX(char *Dest,char *Src)
{
    while(*Src!='\0')
    {
        *Dest=*Src;

        Src++;
        Dest++;
    }

    *Dest='\0';//navin string sampli he sangayla \0 takle ahee
}

int main()
{
    char Arr[30]="Hello";
    char Brr[30];

    strcpyX(Brr,Arr);  //strcpyX(200,100)

    cout<<"Copied string is:"<<Brr<<endl;

    return 0;
}
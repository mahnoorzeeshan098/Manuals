#include<iostream>
using namespace std;
main()
{
    int n=10;
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=i;j++)
        cout<<"  ";
        
        for(int k=1; k<=i;k++)
        cout<<"*";
        cout<<endl;
    }
    cout<<endl;
    for(int m=1;m<=n;m++)
    {
        for(int z=10;z>=m;m--)
        cout<<"*";
        cout<<endl;
    }
    cout<<endl;
}
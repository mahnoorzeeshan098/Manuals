#include<iostream>
using namespace std;
main()
{
    int n=10;
    for(int i=1;i<=n;i++)
    {
        for(int j=10; j>=i;j--)
        cout<"  ";
        
        for(int j=10; j>=i;j--)
        cout<<"*";
        cout<<endl;
    }
    cout<<endl;
}
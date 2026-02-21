#include<iostream>
#include<math.h>
using namespace std;
main()
{
    int a,b,c,d;
    int x,y;
    cout<<" enter first number"<<endl;
    cin>>a;
    cout<<" Enter second number"<<endl;
    cin>>b;
    cout<<" Enter third number"<<endl;
    cin>>c;
    d=b*b-4*a*c;
    cout<<" The fourth number is="<<d<<endl;
    x= -b+d;
    cout<<" The value of x is="<<x<<endl;
    y= -b-d;
    cout<<" the value of y ="<<y<<endl;
}
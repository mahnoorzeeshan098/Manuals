#include<iostream>
using namespace std;
main()
{
    float inter_marks;
    float matric_marks;
    float ecat;
    float aggregate;
    cout<<" enter your matric marks"<<endl;
    cin>>matric_marks;
    cout<<"  enter your inter marks"<<endl;
    cin>>inter_marks;
    cout<<" enter your ecat score"<<endl;
    cin>>ecat;
    matric_marks=matric_marks*10/100;
    inter_marks=inter_marks*50/100;
    ecat=ecat*50/100;
    aggregate=matric_marks+inter_marks+ecat;
    cout<<" the aggregate is"<<aggregate;

}
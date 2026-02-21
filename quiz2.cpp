#include<iostream>
using namespace std;
main()
{
    float weight;
    float height;
    float BMI;
    cout<<"Enter the weight"<<endl;
    cin>>weight;
    cout<<"Enter height"<<endl;
    cin>>height;
    BMI= weight/(height*height);
    cout<<"The value of bmi is:"<<BMI<<endl;
    if(BMI<18.5)
    cout<<"underweight"<<endl;
    if(BMI>18.5 )
    {
        if(BMI<24.9)
        cout<<" NORMAL"<<endl;

    }
    if(BMI>25)
    {
        if(BMI<29.9)
        cout<<" OVER WEIGHT"<<endl;

    }
    if(BMI>=30)
    cout<<"OBESE"<<endl;
}
#include <iostream>

using namespace std;

int main()
{
     float b1;
     float b2;
     float hight;
     cout<<"Enter b1 and b2:\n";
     cin>>b1>>b2;
     cout<<"Enter hight:\n";
     cin>>hight;
     float A;
     /* A=1/2*(b1+b2)*h; */
     A=(b1+b2)*hight/2;
     cout<<"Area of trapezoid is "<<A<<"\n";
    return 0;
}

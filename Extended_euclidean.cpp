#include<iostream>
using namespace std;
void euclidean_gcd(long a,long b)
{
    long q,r1=a,r2=b,r;
    while(r2>0)
    {
     q=r1/r2;//quotient updated
     r=r1-q*r2;//remainder updated
     r1=r2;r2=r;//step:gcd(r1,r2)=gcd(r2,r)
     }
     cout<< "gcd("<<a<<","<<b<<")="<<r1<<endl;
 }
int main()
{   long a,b; 
   cout<<"Enter a and b:"<<endl;
    cin>>a>>b;
    euclidean_gcd(a,b);
    return 0;
}
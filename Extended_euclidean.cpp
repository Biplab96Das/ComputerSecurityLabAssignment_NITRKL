#include<iostream>
using namespace std;
void euclidean_gcd(long a,long b)
{
    long q,r1=a,r2=b,r,s1=1,s2=0,s,t1=0,t2=1,t;
    while(r2>0)
    {
     q=r1/r2;//quotient updated
     //(updated r's')
     r=r1-q*r2;//remainder updated
     r1=r2;r2=r;//step:gcd(r1,r2)=gcd(r2,r)
     //(updated s's')
     s=s1-q*s2;
     s1=s2;s2=s;
     //(updated t's')
     t=t1-q*t2;
     t1=t2;t2=t;
     }
     cout<< "gcd("<<a<<","<<b<<")="<<r1<<" s="<<s1<<" t="<<t1<<endl;
 }
int main()
{   long a,b; 
   cout<<"Enter a and b:"<<endl;
    cin>>a>>b;
    euclidean_gcd(a,b);
    return 0;
}
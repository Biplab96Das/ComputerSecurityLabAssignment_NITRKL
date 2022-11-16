#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

int m_in(int a,int b)
{
int mod=b,n=a;
int i,q,r1=mod,r2=n,r,t1=0,t2=1,t;
    while(r2 != 0)
    {
    q=r1/r2;
    r=r1%r2;
    t=t1-q*t2;

    r1=r2;
    r2=r;
    t1=t2;
    t2=t;
    }
if(t1>0){
     i=t1 % mod;
    return i;
 }
else{
    while(t1<0)
    { int mulF=1;
      t1=t1 + mulF*mod;
      mulF++;
    }
    i=t1 % mod;
    return i;
   }    
        
}

int main(){
	int x,n,md=1;
	vector <int> a;
	vector <int> m;
	vector <int> mr;
	vector <int> mi;
	cout<<"Enter number of equations to enter : ";
	cin>>n;

	for(int i=0;i<n;i++){
		int a1,m1;
		cout<<"Enter values of a"<<i+1<<"and m"<<i+1<<" in equation x = a"<<i+1<<" mod m"<<i+1<<" : ";
		cin>>a1>>m1;
		a.push_back(a1);
		m.push_back(m1);
	}
	

	for(int i=0;i<m.size();i++){
		md=md*m[i];
	}

	for(int i=0;i<m.size();i++){
		mr.push_back(md/m[i]);
	}

	for(int i=0;i<m.size();i++){ 
		int k = m_in(mr[i],m[i]);
		mi.push_back(k);

	}

	for(int i=0;i<m.size();i++){
		cout<<"m["<<i+1<<"]="<<m[i]<<"\t";
	}
	cout<<endl;


	for(int i=0;i<m.size();i++){
		cout<<"M["<<i+1<<"]="<<mr[i]<<"\t";
	}
	cout<<endl;

	for(int i=0;i<m.size();i++){
		cout<<"M["<<i+1<<"]^-1="<<mi[i]<<"\t";
	}
	cout<<endl;
	x=0;
	for(int i=0;i<m.size();i++){
		x+=(a[i]*mr[i]*mi[i]);
	}
	x%=md;
	cout<<"X="<<x<<endl;



}

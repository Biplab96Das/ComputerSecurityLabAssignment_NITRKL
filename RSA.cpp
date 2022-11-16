#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int inv_mod(int a,int b)
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
int binpow(int a, int b,int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(int argc,char **argv)
{
    int p,q,n,count,phi_n;
    cout <<"Hello Bob,select values for p and q"<<endl;
    cin>>p>>q;
    n=p*q;
    phi_n=(p-1)*(q-1);
    cout<<"n="<<n<<" and The Phi("<<n<<") is "<<phi_n<<endl;
    cout <<"Hello Bob,select the value of e,such that 1<=e<="<<(phi_n-1)<<endl;
    int e,d;
    cin>>e;
    d=inv_mod(e,phi_n);
    cout<<"Hello Bob,The value of your private key is "<<d<<endl; 
    int P;
    cout<<"Hello Alice,Enter the plaintext number "<<endl;
    cin>>P;
    int C=binpow(P,e,n);

    cout<<"Hello Alice,sent the ciphertext to Bob which is = "<< binpow(P,e,n)<<endl;
    
    cout<<"I'm Bob,Alice has sent me the number is = "<<binpow(C,d,n)<<endl;
    return 0;
}
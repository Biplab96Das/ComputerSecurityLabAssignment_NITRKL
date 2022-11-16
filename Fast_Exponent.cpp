#include<iostream>
#include<math.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
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
   long long x,y,n,m,res;
   cout << "Enter the value of x,n,m respectively"<<endl;
   cin >> x >> n >> m;
   res=binpow(x,n,m);
   cout <<"The value of Y is = "<<res<<endl;
   return 0;
}

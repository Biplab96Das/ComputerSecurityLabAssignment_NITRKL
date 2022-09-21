//mul cipher ->monoalphabetic substition cipher
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int gcd(int a, int b)
{
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int inverse(int a,int b,int t1,int t2)
{
    if(b==0 && a==1)
        return t1;
    if(a<b)
    {
        int temp=b;
        b=a;
        a=temp;
    }
    int q,t,r;
    q=a/b;
    r=a%b;
    t=t1-q*t2;
    return inverse(b,r,t2,t);
}
int main()
{
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string p,c;
    cout<<"Enter the plain text: ";
    getline(cin,p);
    transform(p.begin(), p.end(),p.begin(), ::toupper);
    int key,key_inv;
    cout<<"Enter the multiplicative key having inverse: ";
    cin>>key;

    if(gcd(key,26)==1)
    {
        key_inv=inverse(key,26,0,1);
        if(key_inv<0)
           key_inv=key_inv%26+26;
    }
    else
    {
        cout<<"inverse does not exist for the given number";
        return 0;
    }


    for(int i=0;i<p.length();i++)
    {
        size_t pos=s.find(p[i]);
        if(pos!=string::npos)
        {
            c.push_back(s[(pos*key)%26]);
        }
        else
        {
            cout<<"illegal chars in the plain text";
            return 0;
        }
    }
    cout<<endl<<"|| Encryption ||"<<endl;
    cout<<endl<<"Plain text: "<<p<<endl;
    cout<<"cipher text: "<<c<<endl;

    p.clear();
    for(int i=0;i<c.length();i++)
    {
        int pos=s.find(c[i]);
        if(pos!=string::npos)
        {
            p.push_back(s[(pos*key_inv)%26]);
        }
        else
        {
            cout<<"illegal chars in the cipher text";
            return 0;
        }
    }
    cout<<endl<<"|| Decryption ||"<<endl;
    cout<<endl<<"cipher text: "<<c<<endl;
    cout<<"Plain text: "<<p<<endl;

}

//vigenere cipher
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string p,c;
    cout<<"Enter the plain text: ";
    getline(cin,p);
    transform(p.begin(), p.end(),p.begin(), ::toupper);
    cout<<"Given plain text: "<<p<<endl;
    string key;
    int block_size;
    cout<<"Enter the key: ";
    cin>>key;
    transform(key.begin(), key.end(),key.begin(), ::toupper);
    block_size=key.length();
    for(int i=0,j=0;i<p.length();i++,j++)
    {
        if(i%block_size==0)
            j=0;
        size_t pos=s.find(p[i]);
        size_t pos2=s.find(key[j]);
        if(pos!=string::npos && pos2!=string::npos)
        {
            c.push_back(s[(pos+pos2)%26]);
        }
        else
        {
            cout<<"illegal chars in the plain text";
            return 0;
        }
    }
    cout<<endl<<"Block size: "<<block_size<<endl;
    cout<<endl<<"|| Encryption ||"<<endl;
    cout<<endl<<"Plain text: "<<p<<endl;
    cout<<"cipher text: "<<c<<endl;

    p.clear();
    for(int i=0,j=0;i<c.length();i++,j++)
    {
        if(i%block_size==0)
            j=0;
        int pos=s.find(c[i]);
        int pos2=s.find(key[j]);
        if(pos!=string::npos && pos2!=string::npos)
        {
            int val=(pos-pos2)%26;
            if(val<0)
                val=val+26;
            p.push_back(s[val]);
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


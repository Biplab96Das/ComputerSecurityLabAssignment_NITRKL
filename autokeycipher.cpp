//autokey cipher
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
    char chark;
    cout<<"Enter the key character: ";
    cin>>chark;
    string key=chark+p;
    transform(key.begin(), key.end(),key.begin(), ::toupper);
    for(int i=0;i<p.length();i++)
    {
        size_t pos=s.find(p[i]);
        size_t pos2=s.find(key[i]);
        if(pos!=string::npos && pos2!=string::npos)
        {
            c.push_back(s[(pos+pos2)%26]);
        }
        else
        {
            cout<<"illegal chars in the text";
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
        int pos2=s.find(key[i]);
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


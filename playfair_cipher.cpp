#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string key;
string alpha="ABCDEFGHIKLMNOPQRSTUVWXYZ";
string pt,ct,cpt;
int ptlen,dtlen;
string conkey;
string keytable[5];
void gen_keytable()
{
    int i=0,col=0;
    for(int j=0;j<conkey.length();j++)
    {
        if(conkey[j]=='J')
            conkey[j]='I';
        int pos=conkey.find(conkey[j]);
        if(pos==j)
        {
            keytable[i].push_back(conkey[j]);
            col++;
            if(col%5==0)
            {
                ++i;
            }
        }
    }
}
void displaytable()
{
    cout<<"Play fair table: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"| "<<keytable[i]<<" |"<<endl;
    }
}
void dummychar()
{
    for(int i=0;i<pt.length();i++)
        if(pt[i]=='J')
            pt[i]='I';
    for(int i=0;i<pt.length();)
    {
        if(pt[i]==pt[i+1])
        {
            if(pt[i]=='X')
                pt.insert(i+1,"Y");
            else
                pt.insert(i+1,"X");

            i=i+2;
        }
        else
            i++;
    }
    dtlen=pt.length();
    if(pt.length()%2!=0)
    {
            if(pt[pt.length()-1]=='X')
                pt.push_back('Y');
            else
                pt.push_back('X');
    }
    cout<<"Final plain text: "<<pt<<endl;
}
void removedummychar()
{
    cpt.erase(dtlen);
    for(int i=0;i<cpt.length();)
    {
        if((cpt[i]==cpt[i+2]) && (cpt[i+1]=='Y'||cpt[i+1]=='X'))
        {
            cpt.erase(cpt.begin() + i+1);
            i=i+2;
        }
        else
            i++;
    }
    cout<<"Final plain text: "<<cpt<<endl;
}
void encrypt()
{
    for(int i=0;i<pt.length();i=i+2)
    {
        char c1,c2;
        int p1=-1,p2=-1,rp1,rp2;
        c1=pt[i];
        c2=pt[i+1];
        for(int row=0;row<5;row++)
        {
            if(p1!=-1 && p2!=-1)
                break;
            if(p1==-1)
            {
                int tp1=keytable[row].find(c1);
                if(tp1!=string::npos)
                {
                    p1=tp1;
                    rp1=row;
                }
            }
            if(p2==-1)
            {
                int tp2=keytable[row].find(c2);
                if(tp2!=string::npos)
                {
                    p2=tp2;
                    rp2=row;
                }
            }
        }
        if(rp1==rp2)
        {
            ct.push_back(keytable[rp1][(p1+1)%5]);
            ct.push_back(keytable[rp2][(p2+1)%5]);
        }
        else if(p1==p2)
        {
            ct.push_back(keytable[(rp1+1)%5][p1]);
            ct.push_back(keytable[(rp2+1)%5][p2]);
        }
        else
        {
           ct.push_back(keytable[rp1][p2]);
           ct.push_back(keytable[rp2][p1]);
        }
        //cout<<endl<<c1<<":"<<rp1<<":"<<p1;
        //cout<<endl<<c2<<":"<<rp2<<":"<<p2;
    }
}

void decrypt()
{
    for(int i=0;i<ct.length();i=i+2)
    {
        char c1,c2;
        int p1=-1,p2=-1,rp1,rp2;
        c1=ct[i];
        c2=ct[i+1];
        for(int row=0;row<5;row++)
        {
            if(p1!=-1 && p2!=-1)
                break;
            if(p1==-1)
            {
                int tp1=keytable[row].find(c1);
                if(tp1!=string::npos)
                {
                    p1=tp1;
                    rp1=row;
                }
            }
            if(p2==-1)
            {
                int tp2=keytable[row].find(c2);
                if(tp2!=string::npos)
                {
                    p2=tp2;
                    rp2=row;
                }
            }
        }
        if(rp1==rp2)
        {
            int temp1,temp2;
            temp1=(p1-1)%5;
            if(temp1<0)
                temp1+=5;
            temp2=(p2-1)%5;
            if(temp2<0)
                temp2+=5;
            cpt.push_back(keytable[rp1][temp1]);
            cpt.push_back(keytable[rp2][temp2]);
        }
        else if(p1==p2)
        {
            int temp1,temp2;
            temp1=(rp1-1)%5;
            if(temp1<0)
                temp1+=5;
            temp2=(rp2-1)%5;
            if(temp2<0)
                temp2+=5;
            cpt.push_back(keytable[temp1][p1]);
            cpt.push_back(keytable[temp2][p2]);
        }
        else
        {
           cpt.push_back(keytable[rp1][p2]);
           cpt.push_back(keytable[rp2][p1]);
        }
        //cout<<endl<<c1<<":"<<rp1<<":"<<p1;
        //cout<<endl<<c2<<":"<<rp2<<":"<<p2;
    }
}

bool checkpt(string &pt)
{
    for(auto x:pt)
    {
        if(!isalpha(x))
            return true;
    }
    return false;
}
int main()
{

    cout<<"Enter the plain text: ";
    getline(cin,pt);
    transform(pt.begin(), pt.end(),pt.begin(), ::toupper);
    ptlen=pt.length();

    if(checkpt(pt))
    {
        cout<<"Illegal characaters in the plain text"<<endl;
        return 0;
    }

    cout<<"Enter the key: ";
    cin>>key;
    transform(key.begin(), key.end(),key.begin(), ::toupper);

    if(checkpt(key))
    {
        cout<<"Illegal characaters in the key text"<<endl;
        return 0;
    }

    conkey=key+alpha;
    cout<<"\nkey : "<<conkey<<endl;
    gen_keytable();
    displaytable();
    cout<<endl<<"|| Encryption ||"<<endl;
    cout<<endl<<"Given plain text: "<<pt<<endl;
    dummychar();
    encrypt();
    cout<<endl<<"Encrypted cipher text: "<<ct<<endl;
    cout<<endl<<"|| Decryption ||"<<endl;
    decrypt();
    cout<<endl<<"Resulted plain text: "<<cpt<<endl;
    removedummychar();
    return 0;
}

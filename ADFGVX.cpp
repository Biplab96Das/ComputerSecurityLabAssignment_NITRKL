#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string key;
string alpha="ABCDEFGHIKLMNOPQRSTUVWXYZ";
string pt,ct,cpt;
string key2;
string s;
string cname="ADFGVX";
int ptlen,dtlen,block_size;
string conkey;
string keytable[5];
vector<int> intcipher;
vector<int> intcipher1;
vector<int> intcipherfinal;
vector<int> intciphersrt;
vector<int> intciphersrt1;
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
void swape(auto &x,auto &y)
{
    char temp=y;
    y=x;
    x=temp;
}
void displaytable()
{
    cout<<"\nBifid key table: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"| "<<keytable[i]<<" |"<<endl;
    }
}

void encrypt()
{
    int i=0;
    for(i=0;i<pt.length();i++)
    {
        if(i%block_size==0 && i!=0)
        {
            for(int k=0;k<key2.length()-1;k++)
            {
                int flag=0;
                for(int j=0;j<key2.length()-k-1;j++)
                {
                    if(s[j]>s[j+1])
                    {
                        swap(s[j],s[j+1]);
                        swap(intcipher[j],intcipher[j+1]);
                        swap(intcipher1[j],intcipher1[j+1]);
                        flag=1;

                    }
                }
                if(flag==0)
                    break;
            }


            copy(intcipher.begin(),intcipher.end(),back_inserter(intcipherfinal));
            copy(intcipher1.begin(),intcipher1.end(),back_inserter(intcipherfinal));


            intcipher.clear();
            intcipher1.clear();
        }
        for(int row=0;row<5;row++)
        {
            if(pt[i]=='J')
                pt[i]='I';
            int pos=keytable[row].find(pt[i]);
            if(pos!=string::npos)
            {
                intcipher.push_back(row);
                intcipher1.push_back(pos);
                intciphersrt.push_back(row);
                intciphersrt1.push_back(pos);
                break;
            }
        }
    }
    if(i%block_size==0 && i!=0)
    {

            for(int k=0;k<key2.length()-1;k++)
            {
                int flag=0;
                for(int j=0;j<key2.length()-k-1;j++)
                {
                    if(s[j]>s[j+1])
                    {
                        swap(s[j],s[j+1]);
                        swap(intcipher[j],intcipher[j+1]);
                        swap(intcipher1[j],intcipher1[j+1]);
                        flag=1;

                    }
                }
                if(flag==0)
                    break;
            }

        copy(intcipher.begin(),intcipher.end(),back_inserter(intcipherfinal));
        copy(intcipher1.begin(),intcipher1.end(),back_inserter(intcipherfinal));

        intcipher.clear();
        intcipher1.clear();
    }
    if(i%block_size!=0)
    {
            for(int k=0;k<key2.length()-1;k++)
            {
                int flag=0;
                for(int j=0;j<key2.length()-k-1;j++)
                {
                    if(s[j]>s[j+1])
                    {
                        swap(s[j],s[j+1]);
                        swap(intcipher[j],intcipher[j+1]);
                        swap(intcipher1[j],intcipher1[j+1]);
                        flag=1;

                    }
                }
                if(flag==0)
                    break;
            }


            copy(intcipher.begin(),intcipher.end(),back_inserter(intcipherfinal));
            copy(intcipher1.begin(),intcipher1.end(),back_inserter(intcipherfinal));


            intcipher.clear();
            intcipher1.clear();
    }
}

void decrypt()
{
    intcipher.clear();
    intcipher1.clear();
    int turn=-1,rem=intcipherfinal.size()%(block_size*2);
    for(int i=0;i<intcipherfinal.size()-rem;i++)
    {
        if(i%block_size==0 && i!=0)
            turn=-turn;
        if(turn<0)
            intcipher.push_back(intcipherfinal[i]);
        else
            intcipher1.push_back(intcipherfinal[i]);
    }

    if(rem!=0)
    {
        int mid=rem/2;
        copy(intcipherfinal.end()-rem,intcipherfinal.end()-mid,back_inserter(intcipher));
        copy(intcipherfinal.end()-mid,intcipherfinal.end(),back_inserter(intcipher1));
    }

    /*for(int i=0;i<key2.length();i++)
    {
        int pos=key2.find(s[i]);
        intciphersrt[pos]=intcipher[i];
        intciphersrt1[pos]=intcipher1[i];
    }

                cout<<endl;
            for(int ind=0;ind<block_size;ind++)
            {
                cout<<cname[intciphersrt[ind]]<<" ";
            }
            cout<<"\n\n\n";
            for(int ind=0;ind<block_size;ind++)
            {
                cout<<cname[intciphersrt1[ind]]<<" ";
            }*/

    for(int i=0;i<intciphersrt.size();i++)
        cpt.push_back(keytable[intciphersrt[i]][intciphersrt1[i]]);
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
    ptlen=pt.length();

    if(checkpt(pt))
    {
        cout<<"Illegal characaters in the plain text"<<endl;
        return 0;
    }
    transform(pt.begin(), pt.end(),pt.begin(), ::toupper);

    cout<<"Enter the 1st key for matrix: ";
    cin>>key;

    cout<<"Enter the 2nd key for sorting: ";
    cin>>key2;
    s=key2;
    block_size=key2.length();

    if(checkpt(key2) || checkpt(key))
    {
        cout<<"Illegal characaters in the key text"<<endl;
        return 0;
    }
    transform(key2.begin(), key2.end(),key2.begin(), ::toupper);
    transform(key.begin(), key.end(),key.begin(), ::toupper);

    conkey=key+alpha;
    gen_keytable();
    displaytable();
    cout<<endl<<"|| Encryption ||"<<endl;
    cout<<endl<<"Given plain text: "<<pt<<endl;
    encrypt();
    cout<<endl<<"Encrypted cipher text: \n";

    for(int ind=0;ind<intcipherfinal.size();ind++)
    {
        cout<<cname[intcipherfinal[ind]]<<" ";
    }



    cout<<endl<<"\n|| Decryption ||"<<endl;
    cout<<endl<<"\nDecrypted cipher text in order: "<<endl;


    for(int ind=0;ind<intciphersrt.size();ind++)
    {
        cout<<cname[intciphersrt[ind]]<<" ";
    }


    for(int ind=0;ind<intciphersrt1.size();ind++)
    {
        cout<<cname[intciphersrt1[ind]]<<" ";
    }


    decrypt();


    cout<<"\n\nFinal resulted plain text: "<<cpt<<endl;
    return 0;
}


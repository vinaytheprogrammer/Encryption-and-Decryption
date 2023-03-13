//Main 
#include<bits/stdc++.h>
#include"mapping.h"
using namespace std;
class code
{
    private:
    string file_name="input.txt";
    int key; //key -encryption , pass - decryption
    char ch;
    public:
    void encrypt();
    void decrypt();
    int randomVal();
};
//FUNCTION FOR GENERATING RANDOM VALUE/KEY
int code::randomVal()
{
    int t;
    srand(time(NULL));// unique key generation
    t = rand() % 9000 + 1000;
    return t;
}
//FUNCTION FOR ENCRYPTING THE DOCUMENT
void code::encrypt()
{
    int i=0;
    int key = randomVal();
    string k = to_string(key);  // convert in string type
    fstream fpin,fpout;
    fpin.open(file_name,fstream::in);       
    fpout.open("encrypt.txt",fstream::out);
    // APPENDING 4 DIGIT KEY AT THE STARTING OF THE FILE
    while(k[i]!='\0')
    {
        string temp=encrypt_mapping(k[i]);
        fpout<<temp;
        i++;
    }
    // READING DATA FROM FILE
    while(fpin>>noskipws>>ch)
    {
        string temp=encrypt_mapping(ch);
        fpout<<temp;
    }
    fpin.close();
    fpout.close();
    cout<<"\nEncrypted";
    cout<<endl<<key<<endl;
}
// FUNCTION FOR DECRYPTING THE FILE
void code::decrypt()
{
    int i=0;
    string pass,st,newst,k1;
    char temp;
    fstream fpin,fpout;
    fpin.open("encrypt.txt",fstream::in);
    fpout.open("decrypt.txt",fstream::out);
    fpin>>noskipws>>st;
    int l=st.length();
    // DECRYPTING THE 4 DIGIT KEY FOR CHECKING
    while(i<16)
    {
        newst=st.substr(i,4);
        temp=decrypt_mapping(newst);
        k1.push_back(temp);
        i=i+4;
    }
    cout<<"Enter a key: ";
    cin>>pass;
    if(pass.compare(k1)==0)
    {
        while(i<l)
        {
            newst=st.substr(i,4);
            temp=decrypt_mapping(newst);
            fpout<<temp;
            i=i+4;
        }
    }else
    {
        cout<<"\n\tOOOOOPS!...You are a fraud."<<endl<<endl;
        exit(0);
    }
    
}
int main()
{
    code cd;
    
    int n;
    do
    {
        cout<<"1.) ENCRYPTION\n2.) DECRYPTION\n";
        cin>>n;   
        switch (n)
        {
            case 1:
            cd.encrypt();
            break;
            case 2:
            cd.decrypt();
            break;
            default:
            cout<<"WRONG CHOICE....";
            break;
        }
    }while (n!=3);
    return 0;
}
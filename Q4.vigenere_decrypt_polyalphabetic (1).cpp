

//4. Implement polyalphabetic cipher substitution operation.
//Vignere decryption

#include<iostream>
#include<string.h>

using namespace std;
//pi = (Ci - ki mod m) mod 26

int main(){
    string plainText;
    string key;
    string cipherText;
    string rkey;
    int index;

    cout <<"\nEnter Cipher Text: ";
    getline(cin, cipherText);

    cout <<"\nEnter Key: ";
    getline(cin, key);

    for(int i=0,j=0;i<cipherText.size();i++,j++){
        index = (int(cipherText[i]) - int(key[j%key.size()]))%26;
        if(index<0)
            index = index+26;
        rkey.push_back(key[j%key.size()]);
        plainText+=(char(index+97));
        cout<<plainText;
    }
	cout<<"\nKeyword: "<<rkey;
    cout<<"\n\nPlain Text: "<<plainText;
}

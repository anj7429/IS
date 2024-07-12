
//3. Implement caeser cipher substitution operation.
//Encryption and Decryption

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

string encryption(string s)
{
    string temp;
    int c;
    for (int i = 0; i < s.length(); i++){

        if (s[i] >= 'A' && s[i] <= 'Z'){
            c = int(s[i]) - 65;
            c = (c + 3) % 26;
            temp.push_back(char(c + 65));
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){
            c = int(s[i]) - 97;
            c = (c + 3) % 26;
            temp.push_back(char(c + 97));
        }
        else{
            temp.push_back(s[i]);
        }
    }

    return temp;
}

string decryption(string s)
{
    string temp;
    int c;
    for (int i = 0; i < s.length(); i++){

        if (s[i] >= 'A' && s[i] <= 'Z'){
            c = int(s[i]) - 65;
            c = (c -3) % 26;
            if(c<0)
                c = c+26;
            temp.push_back(char(c + 65));
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){
            c = int(s[i]) - 97;
            c = (c - 3) % 26;
            if(c<0)
                c = c+26;
            temp.push_back(char(c + 97));
        }
        else{
            temp.push_back(s[i]);
        }
    }

    return temp;
}

int main()
{
      
    
    int ch = 1;
    while(1)
	{
		cout<<"\n__________MENU_________"
			<<"\n1. Encryption"
			<<"\n2. Decryption"
			<<"\n3. Exit"
			<<"\n\nEnter Choice: ";
		
		cin>>ch;
		cin.ignore();
		
		while(!(ch > 0 && ch < 4))
		{
			cout<<"\nInvalid Input, Re-Enter : ";
			cin>>ch;
		}
	
		switch(ch){
			case 1: {
						string msg1;
						cout<<"\nEnter message: ";
    					getline(cin,msg1);
						cout <<"Encrypted message: "<<encryption(msg1)<<endl;
						
					}
					break;
			
			case 2: {	
						string msg;
						cout<<"\nEnter message: ";
    					getline(cin,msg);
						cout<<"Decrypted message: "<<decryption(msg)<<endl;
					}
					break;
			case 3: exit(0);
					break;
		}
	}
}

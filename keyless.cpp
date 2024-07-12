#include<iostream>
using namespace std;
int main(){
    string str,evenstr,oddstr;
    cout<<"Enter the string :";
    cin>>str;
    cout<<"Encrypted message : ";
    for(int i=0;i<str.length();i++){
        if(i%2!=0){
          evenstr+=str[i];
        }
        if(i%2==0){
          oddstr+=str[i];
        }
    }
    cout<<evenstr.append(oddstr);
    return 0;
}
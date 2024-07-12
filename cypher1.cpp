#include<iostream>
using namespace std;

class CeaserCypher{
    public:
    string instr,outstr;
    int key;
    void input();
    void logic();

            
};
void CeaserCypher::input(){
    cout<<"Enter the message : ";
    cin>>instr;
    cout<<"Enter the Key you want to shift : ";
    cin>>key;

}
void CeaserCypher::logic(){
    cout<<"Encrypted message : ";
    for(int i=0;i<instr.length();i++){
        if(instr[i]<91){
        outstr=(((instr[i]+key)-65)%26)+65;
        cout<<outstr;
        }
        else if(instr[i]>=97){
        outstr=(((instr[i]+key)-97)%26)+97;
        cout<<outstr;
        }
    }
    cout<<endl;
}

int main(){
    CeaserCypher obj;
    obj.input();
    obj.logic();
    return 0;
}

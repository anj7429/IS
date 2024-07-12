#include<iostream>
using namespace std;
int main()
{
    string msg,key;
    cout<<"Enter key";
    cin>>key;
    cout<<"enter message";
    cin>>msg;
    int n=msg.length();
    int arr2[n][n];
    int arr1[n][1];

    // for(int i=0;i<n;i++)
    // {
    //     arr1[i][1]=msg[i]-'A';
    // }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr2[i][j]=key[i*n+j]-'A';
            if(j==0)
            {
                 arr1[i][j]=msg[i]-'A';
            }

        }
        
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr1[i][0]<<endl;
    }
    cout<<"second"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr2[i][j]<<" ";
            

        }
        cout<<endl;
        
    }

//ARRAY MULTIPLICATION
int res[n][1];
for(int i=0;i<n;i++)    
{    
    for(int j=0;j<1;j++)    
    {    
        res[i][j]=0;    
        for(int k=0;k<n;k++)    
        {    
            res[i][j]+=arr2[i][k]*arr1[k][j];
            res[i][j]=res[i][j]%26;
        }    
    }    
}
cout<<"your ciphertext is ";

for(int i=0;i<n;i++)
{
    cout<<static_cast<char>('A'  + res[i][0])<<" ";
}




}
#include <iostream>
using namespace std;
#include<string>
#include <time.h>
int count1(string s,int l)
{
    int c = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '1')
        {
            c++;
        }
    }
    return c;
}
int main()
{
    srand(time(0));
    string msg;
    cout << "ENTER MESSAGE";
    cin >> msg;
    int c = count1(msg,msg.length());
   
    if (c % 2 == 0)
    {
        msg += '0';
    }
    else
    {
        msg += '1';
    }
    cout << msg<<endl;

    int in = rand() % (msg.length() - 1);
    int random_01 = rand() % 2;

    cout << "in" << in << "random01" << random_01 << " " << msg << endl;

    string x=to_string(random_01);
    msg[in] =x[0];
    
    cout << "RECEIVED MESSAGE IS" << msg<<" krr "<<msg[in]<<"yyy" << endl;

    c = count1(msg,msg.length()-1);

    if (c % 2 != 0 )
    {
        if(msg[msg.length() - 1] == '1')
            cout << "NO ERROR";
        else
            cout<<"error";
    }
    else if(c % 2 == 0)
    {
        if(msg[msg.length() - 1] == '0')
        cout << "NO ERROR";
        else
            cout<<"error";

    }
    cout<<"end";
}
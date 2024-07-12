
//8. Implement row transposition cipher transposition operation.
//Encryption

#include <iostream>
#include <string>
#include <map>
using namespace std;

//enter columnwise according to key, read row wise

//attackpostponeduntiltwoam
//4312567
//nsacntmettktwXdptpioXuoaolaX
class  RowTranspE
{
	int rounds,r,c;
	string inp,Key,out,t;
	char mat[100][100];
	map<int,int> m;
	public:
		RowTranspE();
		void input();
		void makeMat();
		void encrypt();
		void print();
		string getEncText();
};

RowTranspE::RowTranspE()
{
	r = c = rounds = 0;
	inp = "";
	Key = "";
	out = "";
}

void RowTranspE::input()
{
	cout<<"Enter the plain text: ";
	getline(cin,inp);

	cout<<"Enter the key: ";
	cin>>Key;
	cout<<"Enter number of rounds: ";
	cin>>rounds;

	t = inp;
}

void RowTranspE::makeMat()
{
	while(t.length() % Key.length() != 0)
	{
		t += 'X';
	}

	r = t.length()/Key.length();
	c = Key.length();
	int l = 0;

	cout<<"matrix: \n";
	for(int i=0;i<c;i++)
	{
		m[Key[i]-'0'] = i;
		cout<<Key[i]<<" ";
	}

	cout<<"\n";

	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
			mat[j][m[i+1]] = t[l++];
		}
	}
}

void RowTranspE::encrypt()
{
	for(int k=1;k<=rounds;k++)
	{
		cout<<"\nRound "<<k<<" ";
		makeMat();
		t = "";
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				t += mat[i][j];
				cout<<mat[i][j]<<" ";
			}
			cout<<"\n";
		}
		//cout<<"Cipher text :"<<t<<"\n";
		
	}
	out = t;
}

string RowTranspE::getEncText()
{
	return out;
}

int main()
{
	RowTranspE d;
	d.input();
	d.encrypt();
	cout<<"\nCipher text: "<<d.getEncText()<<"\n";

	return 0;
}

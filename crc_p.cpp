#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
class CRC{
	int ds,gs,*data,*gen,*temp,rsize,size,*div;
	public:
		CRC();
		~CRC();
		void input();
		void zero_append();
		void divide();
		void check();
};
CRC::CRC()
{
	cout<<"Enter number of data bits : ";
	cin>>ds;
	data=new int[ds];
	cout<<"Enter number of  generator bits : ";
	cin>>gs;
	gen=new int[gs];
	temp=new int[ds+gs-1];
}
CRC::~CRC()
{
	cout<<"Destructor called! "<<endl;
	delete[] data;
	delete[] gen;
}
void CRC::input(){
	cout<<"Enter data bits : "<<endl;
	for(int i=0;i<ds;i++)
	{
		cin>>data[i];
	}
	cout<<"Enter generator bits : "<<endl;
	for(int i=0;i<gs;i++)
	{
		cin>>gen[i];
	}
}
void CRC::zero_append(){
	for(int i=0;i<ds+gs-1;i++)
	{
		if(i<ds)
		{
			temp[i]=data[i];
		}
		else
		{
			temp[i]=0;
		}
	}
}
void CRC::divide(){
	int j,k;
	for(int i=0;i<ds;i++)
	{
		k=i;
		j=0;
		if(temp[k]>=gen[j])
		{
			for(j=0,k=i;j<gs;j++,k++)
			{
				if((temp[k]==1 && gen[j]==1)||(temp[k]==0 && gen[j]==0))
				{
					temp[k]=0;
				}
				else
				{
					temp[k]=1;
				}
			}
		}		
	}
	rsize=gs-1;
	div=new int[rsize];
	for(int i=0,j=ds;i<rsize;i++,j++)
	{
		div[i]=temp[j];
	}
	cout<<"Rem bits :"<<endl;
	for(int i=0;i<rsize;i++)
	{
		cout<<div[i]<<" ";
	}
	for(int i=0;i<ds;i++)
	{
		temp[i]=data[i];
	}
	for(int j=0,i=ds;i<(ds+gs-1);i++,j++)
	{
		temp[i]=div[j];
	}
	cout<<endl;
}
void CRC::check(){
	int r,r1;
	size=ds+gs-1;
	int flag=0;
	cout<<"SENDER'S END : ";
	for(int i=0;i<(ds+gs-1);i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<endl;
	cout<<"AT RECEIVER'S END: ";
	srand(time(0));
	r=(rand()%size);
	r1=(rand()%2);
	temp[r]=r1;
	cout<<endl<<"Message at receiver end ";
	for(int i=0;i<(ds+gs-1);i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<endl;
	divide();
	for(int i=0;i<rsize;i++)
	{
		if(div[i]==0)
		flag=0;
		else
		flag=1;
		break;
	}
	if(flag==0)
	{
		cout<<"DATA TRANSMIT SUCCESFULLY!!"<<endl;
	}
	else
	{
		cout<<"Error occured "<<endl;
	}
}
int main()
{
	CRC c;
	c.input();
	c.zero_append();
	c.divide();
	c.check();
	return 0;
}

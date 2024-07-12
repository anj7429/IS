#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
class CRC{
	int ds,gs,rsize,*data,*gen,*temp,size,*div;
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
	cout<<"Enter the number of data bits: ";
	cin>>ds;
	cout<<"Enter the size of generator bits :";
	cin>>gs;
	data=new int[ds];
	gen=new int[gs];
	temp=new int[ds+gs-1];
}
CRC::~CRC()
{
	cout<<endl<<"Destructor called ";
	delete[] data;
	delete[] gen;
}
void CRC::input()
{
	cout<<"Enter the data bits "<<endl;
	for(int i=0;i<ds;i++)
	{
		cin>>data[i];
	}
	cout<<"Enter the generator bits "<<endl;
	for(int i=0;i<gs;i++)
	{
		cin>>gen[i];
	}
}
void CRC::zero_append()
{
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
void CRC::divide()
{
	for(int i=0;i<ds;i++)
	{
		int k=i;
		int j=0;
		if(temp[k]>=gen[j])
		{
			for(j=0,k=i;j<gs;j++,k++)
			{
				if((temp[k]==1 && gen[j]==1) ||(temp[k]==0 && gen[j]==0))
				{
					temp[k]=0;
				}
				else
				temp[k]=1;
			}
		}
	}
	rsize=gs-1;
	div=new int[rsize];
	for(int i=0,j=ds;i<rsize;i++,j++)
	{
//		cout<<"j: "<<j<<" ";
//		cout<<"temp[j]"<<temp[j]<<" ";
		div[i]=temp[j];
	}
	cout<<"REMAINDER BITS :";
	for(int i=0;i<rsize;i++)
	{
		cout<<div[i]<<" ";
	}
	for(int i=0;i<ds;i++)
	{
		temp[i]=data[i];
	}
	for(int i=ds,j=0;i<(ds+gs-1);i++,j++)
	{
		temp[i]=div[j];
	}
	cout<<endl;
}
void CRC::check()
{
	size=ds+gs-1;
	int flag=0;
	cout<<"CODE WORD GENERATED IS ";
	for(int i=0;i<(ds+gs-1);i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<endl<<"AT RECEIVER'S END ";
	srand(time(0));
	int r=(rand()%size);
	int r1=(rand()%2);
	temp[r]=r1;
	cout<<"Message received : ";
	for(int i=0;i<size;i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<endl;
	divide();
	for(int i=0;i<rsize;i++)
	{
		if(div[i]==0)
		{
			flag=0;
		}
		else
		flag=1;
		break;
	}
	if(flag==0)
	cout<<"Data transmitted successfully! "<<endl;
	else
	cout<<"Error occured!"<<endl;
}
int main()
{
	CRC obj;
	obj.input();
	obj.zero_append();
	obj.divide();
	obj.check();
	return 0;
}


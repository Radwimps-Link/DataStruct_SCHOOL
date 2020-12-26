#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class SequentialSort{
	public:
			int *n;
			int len;
		  SequentialSort()
		  {
			cout<<"输入数据(-1结束)\n";
			this->len=0;
			n=(int *)malloc(sizeof(int));
			n[0]=-1;
			int t=0;
			while(t!=-1)
			{
				cin>>t;
				if(t==-1)
				{
					break;
				}
				else
				{
					this->len++;
					n = (int *)realloc(n,(len+1)*sizeof(int));
					n[len]=t; 
				}
			}
		};
		int sort(int a)
		{
			this->n[0]=a;
			int i=this->len; 
			while(n[i]!=a)
			{
				if(n[i]==a)
				{
					break;
				}
				i--;
			}
			if(i==0)
			{
				return -1;
			}
			else
				return i;
		};
		
};



int main(void)
{
	SequentialSort s;
	cout<<"你要查找那个值？"<<"\n";
	int f;
	cin>>f; 
	cout<<s.sort(f)<<"\n";
	
	
	
	
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

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
			sort(n,n+this->len+1); 
		};
		int Bsort(int a,int low,int high)
		{
			
			int mid =(low+high)/2;
			if(low==high&&a!=this->n[mid])
			{
				return -1;
			}
			else if(a==this->n[mid])
			{
				return mid;
			}
			else if(a<this->n[mid])
			{
				return Bsort(a,low,mid-1);
			} 
			else if(a>this->n[mid])
			{
				return Bsort(a,mid+1,high);
			}
		};
		
};



int main(void)
{
	SequentialSort s;
	cout<<"你要查找那个值？"<<"\n";
	int f;
	cin>>f; 
	cout<<s.Bsort(f,1,s.len)<<"\n";
	
	
	
	
	return 0;
}

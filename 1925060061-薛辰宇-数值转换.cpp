#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
	

#define MAX 100


using namespace std;
///数值转换

 
class MyStack
{	

	
	public :
		int *base;
		int *top;
		int size;
		MyStack()
		{
			this->base=(int *)malloc(MAX*sizeof(int));
			this->top=this->base;
			this->size=0;
		}
		void Push(int e)
		{
			*this->top=e;
			this->top++;
			this->size++;
		}
		int Pop()
		{
			this->top--;
			int a=*this->top;
			this->size--;
			return a;
		}
		int GetTop()
		{
			if(this->top==this->base)
			{
				return -1;
			 } 
			int *t=this->top;
			return *--t;
		}
		
		void Destory()
		{
			this->top=this->base;
			this->size=0;
			return;
		}
		void Clear()
		{
			this->size=0;
			this->top=this->base;
			return;
		}
		
		bool Empty()
		{
			if(size==0)
			{
				return true;
			}
			else
				return false;
				
		}
		
		int Len()
		{
			return size;
		}
		
		void vist()
		{
			int *p=this->top-1;
			int book=0;
			while(book<size)
			{
				cout<<(*p)<<" ";
				p--;
				book++;
			}
			
			return ;
		}
};

	
int main()
{	
	double temp=0;
	double a=0;
	cout<<"输入一个数字"<<"\n";
	cin>>temp;
	int n=0;
	cout<<"选择数制"<<"\n";
	cin>>n;
	a=(int)temp;
	MyStack x;
	int ans=a;
	int p=0;
	while(1)
	{
		if(ans==1)
		{
			x.Push(ans);
			break;
		}
		p=ans%n;
		ans-=p;
		ans=ans/n;
		x.Push(p);
	}
	x.vist();
	return 0;
}	

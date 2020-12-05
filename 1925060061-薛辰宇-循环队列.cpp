#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>


#define MAX 5

////采用 长度计数法  


using namespace std;

class LoopQueue
{
	public: 
	int queue[MAX];
	int *head;
	int *tail;
	int len;
	LoopQueue()
	{
		memset(this->queue,0,sizeof(this->queue));
		this->head=&queue[0];
		this->tail=this->head;
		this->len=0;
	}

	void Push(int a)
	{	
		if(this->len==MAX)
		{
			cout<<"队列已满"<<"\n";	
			return;	
		}
		if(this->tail==&queue[MAX-1])
		{
			*(this->tail)=a;
			this->tail=&queue[0];
		}
		else
		{
			*(this->tail)=a;
			this->tail++;
						
		}

		this->len++;
	}
	void pop()
	{
		this->len--;
		this->head++;
	 } 
	void vist()
	{
		int *a=this->head;
		for(int i=0;i<this->len;i++)
		{
			cout<<*a<<" ";
			if(a==&queue[MAX-1])
			{
				a=&queue[0];
			}
			else
				a++;
		}
	}
	void getlen()
	{
		cout<<"长度为 : "<<this->len<<"\n";
		
	 } 
		
};

int main()
{
	LoopQueue q;
	cout<<"循环队列"<<"\n";
	cout<<"1.定义"<<"\n"<<"2.入队"<<"\n"<<"3.出队"<<"\n"<<"4.遍历" <<"\n" 
					<<"5.长度"<<"\n";
	
	int t=0;
	while(t!=-1)
	{
		cin>>t;
		if(t==-1)
		{
			break;
		}
		int e=0;
		switch (t)
		{
			case 1:
					static LoopQueue q;
					cout<<"定义完成"<<"\n";
					break;
			case 2:
					cout<<"请输入数字"<<"\n";
					cin>>e;
					q.Push(e);
					cout<<"FINISH"<<"\n";
					break;
			case 3:
					q.pop();
					cout<<"FINISH"<<"\n";
					break;
			case 4:
					q.vist();
					cout<<"\n"<<"FINISH"<<"\n";
					break;
			case 5:
					q.getlen();
					cout<<"FINISH"<<"\n";
					break;
										
		}
	}	
	
	
	
	return 0;
}








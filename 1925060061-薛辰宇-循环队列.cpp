#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>


#define MAX 5

////���� ���ȼ�����  


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
			cout<<"��������"<<"\n";	
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
		cout<<"����Ϊ : "<<this->len<<"\n";
		
	 } 
		
};

int main()
{
	LoopQueue q;
	cout<<"ѭ������"<<"\n";
	cout<<"1.����"<<"\n"<<"2.���"<<"\n"<<"3.����"<<"\n"<<"4.����" <<"\n" 
					<<"5.����"<<"\n";
	
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
					cout<<"�������"<<"\n";
					break;
			case 2:
					cout<<"����������"<<"\n";
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








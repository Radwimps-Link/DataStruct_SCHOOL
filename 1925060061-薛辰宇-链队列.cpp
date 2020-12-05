#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef struct node
{
	int data;
	node *next;
}node;

	/******************* Tips ************************ 
	*	链式队列----用链表实现，链式队列就是一个操作受限的单向链表
	*	数据域：data----用来存储节点数据                       
	*指针域：struct link *next----用来存储下一个节点的地址
	*链式队列和单向链表比就多了两个指针，头指针和尾指针
	*                                                   
	**********************************************/ 
class queue
{
	public:
		node* head;
		node* tail;
		int len;
		queue()
		{
			this->head=NULL;
			this->tail=head;
			this->len=0;
		}
	/******************* Tips ************************ 
	*	第一步：初始化队列（就是添加一个头节点在队列中），
	*	头结点不存储数据，使队首指针和队尾指针都指向头结点
	* 	第二步：入队（添加节点），使队尾指针指向头新建的节点，
	*	队首指针不变仍然指向头结点                    
	*                                                 
	**********************************************/ 
		void push(int a)
		{
			if(this->head==NULL)
			{
				node *t=(node*)malloc(sizeof(node));
				t->data=a;
				t->next=NULL;
				this->head=t;
				this->tail=this->head;	
			}
			else
			{
				node *t=(node*)malloc(sizeof(node));
				t->data=a;
				t->next=NULL;
				this->tail->next=t;
				this->tail=this->tail->next;
				
			}
			len++;
		}
	/******************* Tips ************************ 
	*	出队时队首指针的位置是不变的，队首指针始终指向头节点，
	*	出队时头节点的指针域指向出队节点的后一节点
	*	                                    
	**********************************************/ 
		void pop()
		{
			this->head=this->head->next;
			len--;
		}
		void init()
		{
			cout<<"初始化"<<"\n"; 
			int t=0;
			while(t!=-1)
			{
				cin>>t;
				if(t==-1)
				{
					break;
				}
				this->push(t);
			}
		}
	/******************* Tips ************************ 
	*	1.顺序队列是用数组实现的，首指针在出队的时候移动，
	*	尾指针在入队的时候移动，需要考虑队列为空和队列为满的两种情况
	*	2.链式队列是用链表实现的，首指针不移动始终指向头节点，
	*	尾指针在入队的时候移动，只考虑队列为空的情况
	*	（不用考虑满是因为链表长度在程序运行过程中可以不断增加，
	*	只要存储空间够malloc就能申请内存空间来存放节点）
	*	出队时头节点的指针域指向出队节点的后一节点
	*	                                    
	**********************************************/ 
		void vist()
		{
			node* itr=this->head;
			if(this->head==NULL)
			{
				cout<<"无元素"<<"\n";
			}
			for(int i=0;i<this->len&&itr!=NULL;i++)
			{
				cout<<itr->data<<" ";
				itr=itr->next;
			}
		}
		
		void destory()
		{
			this->head=NULL;
			this->tail=this->head;
			this->len=0;
			cout<<"销毁完成"<<"\n";
		}
		void getlen()
		{
			cout<<this->len<<"\n";
		 } 
		void clear()
		{
			this->head=NULL;
			this->tail=this->head;
			this->len=0;
		}
		bool empty()
		{
			if(this->len==0)
			{
				return true;
			}
			else
				return false;
		}
}; 



int main(int argc,char** argv)
{
	cout<<"链队列"<<"\n";
	cout<<"1.定义"<<"\n"<<"2.初始化"<<"\n"<<"3.入队"<<"\n"<<"4.出队" <<"\n" 
					<<"5.销毁"<<"\n"<<"6.清空" <<"\n"<<"7.判断为空" <<"\n" 
							<<"8.长度"<<"\n"<<"9.遍历"<<"\n";	
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
					static queue q;
					cout<<"定义完成"<<"\n";
					break;
			case 2:
					q.init();
					cout<<"FINISH"<<"\n";
					break;
			case 3:
					cout<<"输入一个数字"<<"\n";
					cin>>e;
					q.push(e);
					cout<<"FINISH"<<"\n";
					break;
			case 4:
					q.pop();
					cout<<"FINISH"<<"\n";
					break;
			case 5:
					q.destory();
					cout<<"FINISH"<<"\n";
					break;
			case 6:
					q.clear();
					cout<<"FINISH"<<"\n";
					break;
			case 7:
					if(q.empty()) cout<<"为空"<<"\n";
					else cout<<"不为空"<<"\n"; 
					cout<<"FINISH"<<"\n";
					break;
					
			case 8:
					cout<<"长度为："<<"\n"; 
					q.getlen();
					cout<<"FINISH"<<"\n";
					break;
			case 9:
					cout<<"输出："<<"\n"; 
					q.vist();
					cout<<"\n";
					cout<<"FINISH"<<"\n";
					break;
			
								
		}
	}
	
	
	
	return 0;
 } 

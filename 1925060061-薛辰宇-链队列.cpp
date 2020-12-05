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
	*	��ʽ����----������ʵ�֣���ʽ���о���һ���������޵ĵ�������
	*	������data----�����洢�ڵ�����                       
	*ָ����struct link *next----�����洢��һ���ڵ�ĵ�ַ
	*��ʽ���к͵�������ȾͶ�������ָ�룬ͷָ���βָ��
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
	*	��һ������ʼ�����У��������һ��ͷ�ڵ��ڶ����У���
	*	ͷ��㲻�洢���ݣ�ʹ����ָ��Ͷ�βָ�붼ָ��ͷ���
	* 	�ڶ�������ӣ���ӽڵ㣩��ʹ��βָ��ָ��ͷ�½��Ľڵ㣬
	*	����ָ�벻����Ȼָ��ͷ���                    
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
	*	����ʱ����ָ���λ���ǲ���ģ�����ָ��ʼ��ָ��ͷ�ڵ㣬
	*	����ʱͷ�ڵ��ָ����ָ����ӽڵ�ĺ�һ�ڵ�
	*	                                    
	**********************************************/ 
		void pop()
		{
			this->head=this->head->next;
			len--;
		}
		void init()
		{
			cout<<"��ʼ��"<<"\n"; 
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
	*	1.˳�������������ʵ�ֵģ���ָ���ڳ��ӵ�ʱ���ƶ���
	*	βָ������ӵ�ʱ���ƶ�����Ҫ���Ƕ���Ϊ�պͶ���Ϊ�����������
	*	2.��ʽ������������ʵ�ֵģ���ָ�벻�ƶ�ʼ��ָ��ͷ�ڵ㣬
	*	βָ������ӵ�ʱ���ƶ���ֻ���Ƕ���Ϊ�յ����
	*	�����ÿ���������Ϊ�������ڳ������й����п��Բ������ӣ�
	*	ֻҪ�洢�ռ乻malloc���������ڴ�ռ�����Žڵ㣩
	*	����ʱͷ�ڵ��ָ����ָ����ӽڵ�ĺ�һ�ڵ�
	*	                                    
	**********************************************/ 
		void vist()
		{
			node* itr=this->head;
			if(this->head==NULL)
			{
				cout<<"��Ԫ��"<<"\n";
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
			cout<<"�������"<<"\n";
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
	cout<<"������"<<"\n";
	cout<<"1.����"<<"\n"<<"2.��ʼ��"<<"\n"<<"3.���"<<"\n"<<"4.����" <<"\n" 
					<<"5.����"<<"\n"<<"6.���" <<"\n"<<"7.�ж�Ϊ��" <<"\n" 
							<<"8.����"<<"\n"<<"9.����"<<"\n";	
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
					cout<<"�������"<<"\n";
					break;
			case 2:
					q.init();
					cout<<"FINISH"<<"\n";
					break;
			case 3:
					cout<<"����һ������"<<"\n";
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
					if(q.empty()) cout<<"Ϊ��"<<"\n";
					else cout<<"��Ϊ��"<<"\n"; 
					cout<<"FINISH"<<"\n";
					break;
					
			case 8:
					cout<<"����Ϊ��"<<"\n"; 
					q.getlen();
					cout<<"FINISH"<<"\n";
					break;
			case 9:
					cout<<"�����"<<"\n"; 
					q.vist();
					cout<<"\n";
					cout<<"FINISH"<<"\n";
					break;
			
								
		}
	}
	
	
	
	return 0;
 } 

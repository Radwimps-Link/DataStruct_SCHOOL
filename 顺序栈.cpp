#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
	
	
	
#define MAX 100
	
using namespace std;
////˳��ջ
	
	

class MyStack//////���� ջ�� 
{	
	int *base;
	int *top;
	int size;
	/******************* Tips ************************ 
	*	������롢ɾ��������һ����ջ������һ����ջ����
	*	һ�㽫�����ɾ��������Ϊ��ջ�ͳ�ջ��
	**********************************************/ 
	public :
		MyStack()//���캯�� 
		{
			this->base=(int *)malloc(MAX*sizeof(int));//�����ڴ�ռ� 
			this->top=this->base;//��ʼ ʱ   ջͷ����ջβ  
			this->size=0;
		}
		/********************************************* 
		*	ջ��ָ�� S->top ������1������Ҫ��ջ��Ԫ���ڳ��ڴ�ռ䡣
		*	�ٸ�ֵ�����Ǹ���Ӧ������Ԫ�ظ�ֵ��S->data[S->top]=e
		************************************************/ 
		void Push(int e)///ѹջ���� 
		{
			*this->top=e;
			this->top++;
			this->size++;
			return;
		}
		/********************************************* 
		*	ջ����ֵ 
		*	this->top++; 
		*	this->size++;
		************************************************/ 
		void Pop()///��ջ���� 
		{
			if(this->top==this->base)
			{
				return;
			 } 
			this->top--;
			this->size--;
			return;
		}
		/********************************************* 
		*	���this->top==this->base ˵��ջ��   �����в��� 
		*	����  ջ��-- �Ϳ����� 
		*	
		************************************************/ 
		int GetTop()////ȡ��ջ��Ԫ�� 
		{
			if(this->top==this->base)
			{
				return -1;
			 } 
			int *t=this->top;
			return *--t;
		}
		/********************************************* 
		*	���this->top==this->base ˵��ջ��  
		*	����  ȡ�� ջ��Ԫ�ؼ��� 
		*		return *--t;
		************************************************/ 		
		void Destory()////���� ����ջ 
		{
			this->top=this->base;
			this->size=0;
			return;
		}
		/********************************************* 
		*	this->size=0; 
		*	this->top=this->base;
		*		
		************************************************/ 
		void Clear()///���  ջ 
		{
			this->size=0;
			this->top=this->base;
			return;
		}
		/********************************************* 
		*	 
		*	
		*		
		************************************************/ 		
		bool Empty() //// �ж��Ƿ� Ϊ��  ����ֵ 
		{
			if(size==0)
			{
				return true;
			}
			else
				return false;
				
		}
		
		int Len() ///   ���� 
		{
			return size;
		}
		/********************************************* 
		*	 int *p=this->base;ָ�� 
		*		while(book<size)ѭ�� 
		*		cout<<(*p)<<" ";��� 
		*		���� 
		************************************************/ 	
		void vist()/// �������� 
		{
			int *p=this->base;
			int book=0;
			while(book<size)
			{
				cout<<(*p)<<" ";
				p++;
				book++;
			}
			
			return ;
		}
};	
	
	
 	
	
int main()
{	
	cout<<"˳��ջ"<<"\n";
	cout<<"1.����"<<"\n"<<"2.��ʼ��"<<"\n"<<"3.ѹջ"<<"\n"<<"4.��ջ" <<"\n" 
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
			case 1:static MyStack stack;
					cout<<"�������"<<"\n";
					break;
			case 2:
					cout<<"��������"<<"\n";
					while(e!=-1)
					{
						cin>>e;
						if(e==-1)
						{
							
							break;
						}
						stack.Push(e);
					}
					cout<<"FINISH"<<"\n";
					break;
			case 3:
					cout<<"����һ������"<<"\n";
					cin>>e;
					stack.Push(e);
					cout<<"FINISH"<<"\n";
					break;
			case 4:
					stack.Pop();
					cout<<"FINISH"<<"\n";
					break;
			case 5:
					stack.Destory();
					cout<<"FINISH"<<"\n";
					break;
			case 6:
					stack.Clear();
					cout<<"FINISH"<<"\n";
					break;
			case 7:
					if(stack.Empty()) cout<<"Ϊ��"<<"\n";
					else cout<<"��Ϊ��"<<"\n"; 
					cout<<"FINISH"<<"\n";
					break;
					
			case 8:
					cout<<"����Ϊ��"<<stack.Len()<<"\n";
					cout<<"FINISH"<<"\n";
					break;
			case 9:
					cout<<"�����"<<"\n"; 
					stack.vist();
					cout<<"\n";
					cout<<"FINISH"<<"\n";
					break;
			
								
		}
	}
	
	
	
	
	
	
	
	return 0;
 } 	
 	

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
	
	
	
#define MAX 100
	
using namespace std;
////顺序栈
	
	

class MyStack//////定义 栈类 
{	
	int *base;
	int *top;
	int size;
	/******************* Tips ************************ 
	*	允许插入、删除操作的一端是栈顶、另一端是栈顶。
	*	一般将插入和删除操作称为入栈和出栈。
	**********************************************/ 
	public :
		MyStack()//构造函数 
		{
			this->base=(int *)malloc(MAX*sizeof(int));//分配内存空间 
			this->top=this->base;//开始 时   栈头等于栈尾  
			this->size=0;
		}
		/********************************************* 
		*	栈顶指针 S->top 先自增1，给需要进栈的元素腾出内存空间。
		*	再赋值。就是给对应的数组元素赋值：S->data[S->top]=e
		************************************************/ 
		void Push(int e)///压栈操作 
		{
			*this->top=e;
			this->top++;
			this->size++;
			return;
		}
		/********************************************* 
		*	栈顶赋值 
		*	this->top++; 
		*	this->size++;
		************************************************/ 
		void Pop()///出栈操作 
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
		*	如果this->top==this->base 说明栈空   不进行操作 
		*	否则  栈顶-- 就可以了 
		*	
		************************************************/ 
		int GetTop()////取得栈顶元素 
		{
			if(this->top==this->base)
			{
				return -1;
			 } 
			int *t=this->top;
			return *--t;
		}
		/********************************************* 
		*	如果this->top==this->base 说明栈空  
		*	否则  取出 栈顶元素即可 
		*		return *--t;
		************************************************/ 		
		void Destory()////销毁 整个栈 
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
		void Clear()///清空  栈 
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
		bool Empty() //// 判断是否 为空  布尔值 
		{
			if(size==0)
			{
				return true;
			}
			else
				return false;
				
		}
		
		int Len() ///   长度 
		{
			return size;
		}
		/********************************************* 
		*	 int *p=this->base;指针 
		*		while(book<size)循环 
		*		cout<<(*p)<<" ";输出 
		*		自增 
		************************************************/ 	
		void vist()/// 遍历操作 
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
	cout<<"顺序栈"<<"\n";
	cout<<"1.定义"<<"\n"<<"2.初始化"<<"\n"<<"3.压栈"<<"\n"<<"4.出栈" <<"\n" 
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
			case 1:static MyStack stack;
					cout<<"定义完成"<<"\n";
					break;
			case 2:
					cout<<"输入数字"<<"\n";
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
					cout<<"输入一个数字"<<"\n";
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
					if(stack.Empty()) cout<<"为空"<<"\n";
					else cout<<"不为空"<<"\n"; 
					cout<<"FINISH"<<"\n";
					break;
					
			case 8:
					cout<<"长度为："<<stack.Len()<<"\n";
					cout<<"FINISH"<<"\n";
					break;
			case 9:
					cout<<"输出："<<"\n"; 
					stack.vist();
					cout<<"\n";
					cout<<"FINISH"<<"\n";
					break;
			
								
		}
	}
	
	
	
	
	
	
	
	return 0;
 } 	
 	

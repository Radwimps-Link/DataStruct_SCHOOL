//二叉树 的三种遍历
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack> 
#include<queue>
#define ElemType char


using namespace std;

typedef struct node{
	ElemType data;
	node *L;
	node *R;
	unsigned char LTag;///0代表 没有左孩子  则其为线索 
	unsigned char RTag;///0代表 没有右孩子  则其为线索 
}node;


class tree{
	public:
		node *t;//含有头节点 
		
		tree()//初始化 建树 
		{
			t=(node *)malloc(sizeof(node));//头节点  含有头节点的树 
											//里面数据代表长度 
			cout<<"先序顺序输入二叉树(#为空)\n";
			t->data=0;
			t->L=create(t->L);
			t->R=NULL;
			t->RTag=0;
			cout<<"创建完成\n";
		 } 
		node* create(node *T)
		{
			ElemType temp;
			cin>>temp;
			if(temp=='#')
			{
				return NULL;
			}
			T=(node *)malloc(sizeof(node));
			t->data++;
			T->data=temp;
			
			T->L=create(T->L);
			if(T->L!=NULL)
			{
				T->LTag=1;
			}
			else T->LTag=0;
			
			
			T->R=create(T->R);
			if(T->R!=NULL)
			{
				T->RTag=1;
			}
			else T->RTag=0;
			
			return T;
		}
		
		void vist()
		{
			stack<node*> s;
			node *p=(this->t)->L;
			while(p!=NULL||!s.empty())
			{
				if(p!=NULL)
				{
					s.push(p);					
					p=p->L;
				}
				else
				{
					p=s.top();
					s.pop();
					cout<<p->data<<" ";
					p=p->R;	
				}
			}
			
			return;			
		}
		
		
		void Treading()
		{
			stack<node*> s;
			node* f[t->data];
			int i=0;
			node *p=(this->t)->L;
			while(p!=NULL||!s.empty())
			{
				if(p!=NULL)
				{
					s.push(p);					
					p=p->L;
				}
				else
				{
					p=s.top();
					s.pop();
					f[i]=p;
					i++;
					p=p->R;	
				}
			}
			
			for(int i=0;i<t->data;i++)
			{
					if(f[i]->LTag==0)
					{
						if(i==0)
						{
							f[i]->L=this->t;
							
						}
						else
						{
							f[i]->L=f[i-1];					
						}

					}
					if(f[i]->RTag==0)
					{
						
						if(i==t->data-1)
						{
							f[i]->R=this->t;
						}					
						else
						{
							f[i]->R=f[i+1];
						
						}

					}					
				
			}
			cout<<"线索化成功\n" ;
			return;
		}
};



int main(int argc,char**argv)
{
	tree T;
	T.vist();
	cout<<"\n\n";
	T.Treading();

	return 0; 
} 

 

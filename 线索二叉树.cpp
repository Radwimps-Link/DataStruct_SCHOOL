//������ �����ֱ���
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
	unsigned char LTag;///0���� û������  ����Ϊ���� 
	unsigned char RTag;///0���� û���Һ���  ����Ϊ���� 
}node;


class tree{
	public:
		node *t;//����ͷ�ڵ� 
		
		tree()//��ʼ�� ���� 
		{
			t=(node *)malloc(sizeof(node));//ͷ�ڵ�  ����ͷ�ڵ���� 
											//�������ݴ����� 
			cout<<"����˳�����������(#Ϊ��)\n";
			t->data=0;
			t->L=create(t->L);
			t->R=NULL;
			t->RTag=0;
			cout<<"�������\n";
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
			cout<<"�������ɹ�\n" ;
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

 

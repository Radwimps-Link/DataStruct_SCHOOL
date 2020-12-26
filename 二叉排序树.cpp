#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>


using namespace std;

typedef struct node 
{

	int data;
	node *lift;
	node *right;

} node;


class BinTree 
{
	public :
		node *Tree;
		BinTree() 
		{
			Tree = (node *)malloc(sizeof(node));
			Tree->data=-1;
			Tree->lift=NULL;
			Tree->right=NULL;
			int t=0;
			cout<<"输入数值(-1结尾)\n";
			while(t!=-1) 
			{
				node *p = Tree;
				node *q;
				cin>>t;
				if(t==-1) 
				{
					break;
				}
				if(p->data==-1) 
				{
					p->data=t;
					p->lift=NULL;
					p->right=NULL;
				} 
				else 
				{
					while(p!=NULL) 
					{
						if(t<=p->data) 
						{
							
							q=p;
							p=p->lift;
							if(p==NULL) 
							{
								q->lift=(node *)malloc(sizeof(node));
								p=q->lift;
								p->data=t;
								p->lift=NULL;
								p->right=NULL;
								break;
							} 
						}
						else if(t>p->data) 
						{
							q=p;
							p=p->right;
							if(p==NULL) 
							{
								q->right=(node *)malloc(sizeof(node));
								p=q->right;
								p->data=t;
								p->lift=NULL;
								p->right=NULL;
								break;
							}
						}
					}
				}
			}
		};
		int search(int t) 
		{
			node *p=this->Tree;
			node *q;
			while(p!=NULL) 
			{
				if(t==p->data)
				{
					return p->data;
				}
				else if(t<p->data) 
				{
					q=p;
					p=p->lift;
					if(p==NULL&&t!=q->data) 
					{
						return -1;
					}
					else if(p==NULL&&t==q->data)
					{
						return q->data;
					}
				}
				else if(t>p->data) 
				{
					q=p;
					p=p->right;
					if(p==NULL&&t!=q->data) 
					{
						return -1;	
					}
					else if(p==NULL&&t==q->data)
					{
						return q->data;
					}
				}
			}
		}

};


int main(void) 
{
	BinTree T;
	cout<<"输入想要查找的数字\n";
	int f;
	cin>>f;
	cout<<T.search(f)<<"\n";
		
	


	return 0;
}

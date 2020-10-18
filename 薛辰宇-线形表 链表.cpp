////���Ա�  ����ʵ��
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAX 100
using namespace std;

typedef struct node
{
	int data;
	node *next;
}node;

typedef struct List
{
	node *l;
	int len; 
}List;


void init(List &list)
{
	list.len=0;
	printf("���������Ա�(-1��������)\n"); 
	int a=0;
	int i=0;
	node *p=NULL;
	list.l=NULL;
	p=(node *)malloc(sizeof(node));//ָ�����ڴ� 
	while(a!=-1)
	{
		scanf("%d",&a);
		if(a==-1)
		{
			break;
		}
		p->next=(node *)malloc(sizeof(node));
		if(list.l==NULL)
		{
			p->data=a;
			list.l=p;
		}
		else
		{
			p=p->next;
			p->data=a;
			p->next=NULL;	
		}
		i++;
	}
	list.len=i+1;
	printf("�������\n");
	return;
}

void Destory(List &list)
{
	list.l=NULL;
	printf("���ٳɹ�\n") ;
	return;
}

void ClearList(List &list)
{
	list.len=0;
	printf("�����\n"); 
	return;
}

int ListEmpty(List &list)
{
	if(list.l==NULL)
	{
		printf("�����ѱ��ݻ�\n");
		return 0; 
	}
	if(list.len==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int ListLength(List &list)
{
	return list.len;
}
void GetElem(List &list,int i,int &e)
{
	if(i>list.len)
	{
		printf("����̫��\n");
		return;
	}
	else if(list.l==NULL)
	{
		printf("�������ڣ����ȴ�������\n"); 
	}
	node *p=list.l;
	int a=0;
	while((p->next)&&a<i)
	{
		p=p->next;
		a++;
	}
	e=p->data;
	return;
}
int compare(int a,int b)
{
	return a>=b?1:0;
}
int LocateElem(List &list,int e)
{
	node *p=list.l;
	for(int i=0;i<list.len&&p;i++)
	{
		if(compare(p->data,e))
		{
			return i+1;
		}
		p=p->next;
	}
	return 0;
}

void PriorElem(List &list,int cur_e,int &pre_e)
{
	if(cur_e>list.len)
	{
		printf("��������\n");
		return;
	}
	node *p=list.l;
	if(cur_e==0)
	{
		return;
	 } 
	else
	{
		for(int i=0;i<list.len&&p->next!=NULL;i++)
		{
			if(i+1==cur_e)
			{
				pre_e=p->data;
				return;
			}
			p=p->next;
		}
	}
	return;	
}

void NextElem(List &list,int cur_e,int &next_e)
{
	if(cur_e>list.len)
	{
		printf("��������\n");
		return;
	}
	node *p=list.l;
	p=p->next;
	for(int i=1;i<list.len-1&&p->next;i++)
	{
		if(i-1==cur_e)
		{
			next_e=p->data;
			return;
		}
		p=p->next;
	}
	return;	
}

void ListInsert(List &list,int i,int e)
{
	if(i>list.len)
	{
		printf("��������\n");
		return;
	}
	node *p=list.l;
	node *q=(node *)malloc(sizeof(node));
	q->data=e;
	q->next=NULL;
	if(i==0)
	{
		q->next=list.l->next;
		list.l->next=q;
	}
	else
	{
		for(int j=0;j<i-1&&p;j++)
		{
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
	}

	list.len++;
	return;
}

void ListDelete(List &list,int i,int &e)
{
	node *p=list.l;
	node *q=(node *)malloc(sizeof(node));
	if(i>list.len&&i>=0)
	{
		printf("��������\n"); 
		return;
	}
	if(i==0)
	{
		q=list.l;
		list.l=list.l->next;
		free(q);
	}
	else
	{
		for(int j=0;j<i-1&&p;j++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		free(q);	
	}
	list.len--;
	return ;
} 

void mearge(List &list)
{
	printf("��������һ������\n");
	List list2;
	init(list2);
	node *p=list.l;
	node *q=list2.l;
	node *t=NULL;
	node *a=list.l;
	list.len+=list2.len;
	for(int i=0;p&&q;i++)
	{
		
		if(p->data<=q->data)
		{	
			a=p;
			p=p->next;
		}
		/*	t=q;
			q=q->next;
			t->next=p->next;
			p->next=t;*/
		else
		{
			t=q;
			q=q->next;	
			t->next=p;
			if(i==0)
			{
				a=t;
			}
			else
			{
				a->next=t;
				a=a->next;
			}			
		}
	 }
	 a->next=q;
	 return ;
 } 


void ListVist(List &list)
{
	
	if(list.len==0)
	{
		printf("����Ϊ��\n");
		return; 
	}
	else if(list.l==NULL)
	{
		printf("�����ѱ��ݻ�\n");
		return; 
	}
	node *p=list.l;
	for(int j=0;j<list.len&&p!=NULL;j++)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return;
}


int main()
{
	cout<<"0��ʼ��\n1����\n2���\n3�ж�Ϊ��\n4����\n"
					<<"5����Ԫ��ֵ\n6��������\n7����ǰ��\n8���غ��\n9����"
					<<"\n10ɾ��\n11�ϲ�\n12�鿴����\n";
	List list;
	int temp=0;
	int i,e,cur_e,pre_e=-1,next_e=-1;
	while(temp!=-1)
	{
		cout<<"����ѡ��\n";
		cin>>temp;
		switch (temp)
		{
			case 0:init(list);break;
			case 1:Destory(list);break;
			case 2:ClearList(list);break;
			case 3:if(!ListEmpty(list)){
					printf("Ϊ��\n"); 
					}
					else printf("��Ϊ��\n"); 
					break;
			case 4:printf("����%d\n",ListLength(list));break;
			case 5:printf("����λ��i\n");scanf("%d",&i);GetElem(list,i-1,e);
					printf("Ԫ��Ϊ%d\n",e);
					break;
			case 6:printf("������������e(���ڵ���)\n");
					scanf("%d",&e);
					if(LocateElem(list,e))
					{
						printf("λ��Ϊ%d\n",LocateElem(list,e));
					}
					else
					{
						printf("���в���������\n"); 
					}
					break;
			case 7:printf("����λ��i\n");
					scanf("%d",&cur_e);
					PriorElem(list,cur_e-1,pre_e);
					if(pre_e!=-1)
					{
						printf("ǰ���� %d\n",pre_e);
					}
					else
					{
						printf("������ǰ��\n"); 
					}
					break;
			case 8:printf("����λ��i\n");
					scanf("%d",&cur_e);
					NextElem(list,cur_e-1,next_e);
					if(next_e!=-1)
					{
						printf("����� %d\n",next_e);
					}
					else
					{
						printf("�����ں��\n"); 
					}					
					break;
			case 9:printf("�������λ��i(��0��ʼ) ��������e\n");
					scanf("%d%d",&i,&e);
					ListInsert(list,i,e);
					break;
			case 10:printf("����i(��0��ʼ)\n");
					scanf("%d",&i);
					ListDelete(list,i,e);
					break;
			case 11:mearge(list); break;
			case 12:ListVist(list);
					break;
			default: break;
		}
	 } 
	
	
	
	return 0;
 } 

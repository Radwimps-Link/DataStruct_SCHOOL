////���Ա�  ����ʵ��
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAX 100
using namespace std;

typedef struct node
{
	int data;
	int cishu; 
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
	printf("���������Ա�(����-1��������)\n"); 
	int a=0;
	int b=0;
	int i=0;
	node *p=NULL;
	list.l=NULL;
	p=(node *)malloc(sizeof(node));//ָ�����ڴ� 
	while(b!=-1)
	{
		printf("ϵ�� ����\n"); 
		scanf("%d%d",&a,&b);
		if(b==-1)
		{
			break;
		}
		p->next=(node *)malloc(sizeof(node));
		if(list.l==NULL)
		{
			p->data=a;
			p->cishu=b;
			list.l=p;
		}
		else
		{
			p=p->next;
			p->data=a;
			p->cishu=b;
			p->next=NULL;	
		}
		i++;
	}
	list.len=i+1;
	printf("�������\n");
	return;
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
		printf("%dx^%d",p->data,p->cishu);
		if(j<list.len-1)
			printf("+"); 
		p=p->next;
	}
	printf("\n");
	return;
}

void mearge(List &list,List &list2)
{
	printf("��������һ������\n");
	node *p=list.l;
	node *q=list2.l;
	node *t=NULL;
	node *a=list.l;
	list.len=1;
	for(int i=0;p&&q;i++)
	{
		
		if(p->cishu<q->cishu)
		{	
			a=p;
			p=p->next;
			list.len++;
		}
		else if(p->cishu==q->cishu)
		{
			p->data+=q->data;
			a=p;
			p=p->next;
			t=q;
			q=q->next;
			list.len++;
		}
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
			list.len++;			
		}
	 }
	 a->next=q;
	 return ;
 } 


int main()
{
	List list1;
	List list2;
	init(list1);
	init(list2);
	printf("���\n");
	mearge(list1,list2);
	ListVist(list1);
	
	
	return 0;
 } 



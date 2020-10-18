////线性表  数组实现
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 100
using namespace std;

typedef struct List
{
	int l[MAX];
	int len; 
}List;

void init(List *&list)
{
	list=(List*)malloc(sizeof(List));
	list->len=0;
	printf("请输入线性表(-1结束输入)\n"); 
	int a=0;
	int i=0;
	while(a!=-1)
	{
		scanf("%d",&a);
		if(a==-1)
		{
			break;
		}
		list->l[i]=a;
		list->len++;
		i++;
	}
	printf("输入完成\n"); 
	return;
}

void Destory(List *&list)////指针的引用	 List *&p 
{

	list=NULL;
	printf("销毁成功\n") ;
	return;
}

void ClearList(List *list)
{
	list->len=0;
	printf("已清空\n"); 
	return;
}

int ListEmpty(List *list)
{
	if(list==NULL)
	{
		printf("链表已被摧毁\n");
		return 0; 
	}
	if(list->len==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int ListLength(List *list)
{
	return list->len;
}
void GetElem(List *list,int i,int &e)
{
	e=list->l[i];
	return;
}
int compare(int a,int b)
{
	return a>=b?1:0;
}
int LocateElem(List *list,int e)
{
	for(int i=0;i<list->len;i++)
	{
		if(compare(list->l[i],e))
		{
			return i+1;
		}
	}
	return 0;
}

void PriorElem(List *list,int cur_e,int &pre_e)
{
	if(cur_e>list->len)
	{
		printf("超出长度\n");
		return;
	}
	if(cur_e==0)
	{
		return;
	 } 
	else
	{
		for(int i=0;i<list->len;i++)
		{
			if(i+1==cur_e)
			{
				pre_e=list->l[i];
				return;
			}
		}
	}
	return;	
}

void NextElem(List *list,int cur_e,int &next_e)
{

	if(cur_e>list->len)
	{
		printf("超出长度\n");
		return;
	}
	else
	{
		for(int i=0;i<list->len;i++)
		{
			if(i-1==cur_e)
			{
				next_e=list->l[i];;
				return;
			}
		}	
	}

	return;	
}

void ListInsert(List *list,int i,int e)
{

	for(int j=list->len-1;j>=i;j--)
	{
		list->l[j+1]=list->l[j];
	}
	list->l[i]=e;
	list->len++;
	return;
}

void ListDelete(List *list,int i,int &e)
{
	e=list->l[i];
	for(int j=i;j<list->len-1;j++)
	{
		list->l[j]=list->l[j+1];
	}
	list->len-=1;
	return;
} 

void mearge(List *&list)
{
	void ListVist(List *list); 
	printf("请在输入一组数据\n");
	List *list2=(List*)malloc(sizeof(List));
	init(list2);
	sort(list->l,list->l+list->len);
	sort(list2->l,list2->l+list->len);
	int a[MAX];
	int i=0,j=0,k=0;
	for(i=0;j<list->len&&k<list2->len;i++)
	{
		if(list->l[j]<=list2->l[k])
		{
			a[i]=list->l[j];
			j++;
		}
		else
		{
			a[i]=list2->l[k];
			k++;			
		}
	}
	for(int t=j;t<list->len;t++)
	{
		a[i]=list->l[t];
		i++;
	}
	for(int t=k;t<list2->len;t++)
	{
		a[i]=list2->l[t];
		i++;
	}
	list->len=0;
	for(int t=0;t<i;t++)
	{
		list->l[t]=a[t];
		list->len++;
	}
	return;
}

void ListVist(List *list)
{
	if(list==NULL)
	{
		printf("链表已被摧毁\n");
		return; 
	}
	else if(list->len==0)
	{
		printf("链表为空\n");
		return; 
	}
	for(int j=0;j<list->len;j++)
	{
		printf("%d ",list->l[j]);
	}
	printf("\n");
	return;
}


int main()
{
	cout<<"0初始化\n1销毁\n2清空\n3判断为空\n4长度\n"
					<<"5返回元素值\n6满足条件\n7返回前驱\n8返回后继\n9插入"
					<<"\n10删除\n11合并\n12查看链表\n";
	List *list=(List*)malloc(sizeof(List));
	int temp=0;
	int i,e,cur_e,pre_e=-1,next_e=-1;
	while(temp!=-1)
	{
		cout<<"输入选项\n";
		cin>>temp;
		switch (temp)
		{
			case 0:init(list);break;
			case 1:Destory(list);break;
			case 2:ClearList(list);break;
			case 3:if(!ListEmpty(list)){
					printf("为空\n"); 
					}
					else printf("不为空\n"); 
					break;
			case 4:printf("长度%d\n",ListLength(list));break;
			case 5:printf("输入位置i\n");scanf("%d",&i);GetElem(list,i-1,e);
					printf("元素为%d\n",e);
					break;
			case 6:printf("输入条件数字e(大于等于)\n");
					scanf("%d",&e);
					if(LocateElem(list,e))
					{
						printf("位置为%d\n",LocateElem(list,e));
					}
					else
					{
						printf("表中不满足条件\n"); 
					}
					break;
			case 7:printf("输入位置i\n");
					scanf("%d",&cur_e);
					PriorElem(list,cur_e-1,pre_e);
					if(pre_e!=-1)
					{
						printf("前驱是 %d\n",pre_e);
					}
					else
					{
						printf("不存在前驱\n"); 
					}
					break;
			case 8:printf("输入位置i\n");
					scanf("%d",&cur_e);
					NextElem(list,cur_e-1,next_e);
					if(next_e!=-1)
					{
						printf("后继是 %d\n",next_e);
					}
					else
					{
						printf("不存在后继\n"); 
					}					
					break;
			case 9:printf("输入插入位置i(从0开始) 插入数据e\n");
					scanf("%d%d",&i,&e);
					ListInsert(list,i,e);
					break;
			case 10:printf("输入i(从0开始)\n");
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

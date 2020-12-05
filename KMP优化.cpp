#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#define ElemType char


using namespace std;

class String
{
	public:
		ElemType *s;
		int size;
		int *next;
		String()
		{
			this->s=(ElemType*)malloc(sizeof(ElemType));
			this->size=0;
			printf("输入字符串(以句号\".\" 结尾)\n");
			char a='0';
			while(a!='.')
			{
				scanf("%c",&a);
				if(a=='.')
				{
					break;
				}
				this->size++;
				this->s=(ElemType*)realloc(s,size*sizeof(ElemType));
				this->s[size-1]=a;
			}
			this->next=(int*)malloc(this->size*sizeof(int));
			memset(this->next,0,this->size*sizeof(int));
			this->get_next();
			return;
		}
		int KMP(String str)///KMP算法 
		{
			//int book=0;//标记是否成功匹配  0代表不成功  1代表成功 
			int i=0,j=0;//i指向str，j指向 this字符串
			while(j<this->size-1&&i<str.size-1)
			{
				if(str.s[i]==this->s[j])
				{
					i++;
					j++;
				}
				else
				{
					j=this->next[j];
					i++;
				}
			}
			if(j!=this->size-1)
			{
				return -1;
			}
			i-=this->size;
			++i;
			return i+1;
		}
		void get_next()
		{
			int i=0,j=1;
			this->next[0]=0;
			while(j<this->size)
			{
				if(this->s[i]==this->s[j])
				{
					j++;
					i++;
					next[j]=i;
				}
				else if(i==0)
				{
					j++;
					next[j]=0;
				}
				else
				{
					i=next[i];
				}
			}
			return ;
		}
	
	
};


int main(int argc,char** argv)
{
	printf("输入匹配串\n");
	String s;
	getchar();
	printf("输入原串\n");
	String str;
	printf("匹配定位：\n");
	int pos =  s.KMP(str);
	if(pos==-1)
	{
		cout<<"匹配不成功\n";
		
	}
	else 
		cout<<"第"<<pos<<"个字符到第"<<pos+s.size-1<<"个字符之间"<<"\n";
	
	
	return 0;
 } 

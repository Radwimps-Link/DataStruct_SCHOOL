#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>


using namespace std;

typedef struct w{
	int a;
	int b;
	int w;
	int next;
}w;

class graph{
	public:
		int *node;
		w *bian;
		int bianSize;
			
		graph()
		{
			cout<<"���ڴ��� ����ͼ(����Ȩ) ��ʽǰ����\n";
			this->bianSize=0;
			cout<<"����ڵ����\n";
			int n;
			cin>>n;
			this->node = (int *)malloc(n*sizeof(int));
			for(int i=0;i<n;i++)//��ʼ�� 
			{
				this->node[i]=-1;
			}
			bian = (w*)malloc(sizeof(w));
			int j=0;
			int temp=0;
			while(temp!=-1)
			{
				cout<<"�����(-1�˳�)��� �յ� ��Ȩ\n";
				cin>>temp;
				if(temp==-1)
				{
					break;
				}
				bian = (w*)realloc(bian,(this->bianSize+1)*sizeof(w));
				bian[j].a=temp;
				cin>>bian[j].b;
				cin>>bian[j].w;
				bian[j].next = this->node[bian[j].a];
				this->node[bian[j].a]=j;
				
				
				j++;//����+1 
				this->bianSize++;//����+1 
				
			}
			
		}
		
		void vist(){
			for(int i=0;i<this->bianSize;i++)
			{
				cout<<bian[i].a<<"-->"<<bian[i].b<<" ���� : "<<bian[i].w<<" ��һ����"<<bian[i].next<<" \n";
			}
		}
		
		void bianli(int qidian)
		{
			int t = node[qidian];
			while(t!=-1)
			{
				cout<<bian[t].a<<"-->"<<bian[t].b<<" ���� : "<<bian[t].w<<" \n";
				t=bian[t].next;
			}
		}
	
		
};




int main(int argc,char **argv)
{
	graph G;
	G.vist();
	cout<<"\n\n";
	G.bianli(1);
	
	
	
	
	
	
	
	return 0;
}

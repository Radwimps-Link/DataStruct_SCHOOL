#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<stack>

#define inf 0x3f3f3f2f

using namespace std;

typedef struct w{
	int a;//��a ��� 
	int b;// ��b �յ� 
	int w;//��Ȩ 
	int next;//��һ����λ�� 
}w;

typedef struct fla{
	int minValue;
	int node;
}fla; 

class graph{
	public:
		int *node;//���� 
		w *bian;//��ʽǰ����  �߼��� 
		
		int bianSize;//�߸��� 
		int nodeSize;//������� 
		
		fla *flag;//prim�㷨������� 
		
		
		graph()//��ʼ������ 
		{
			this->flag=0;
			cout<<"���ڴ��� ����ͼ(����Ȩ) ��ʽǰ����\n";
			this->bianSize=0;//�߸��� == 0 
			cout<<"����ڵ����\n";
			int n;//������ 
			cin>>n;
			this->node = (int *)malloc(n*sizeof(int));//��һά���� ���㼯�� ����ռ� 
			for(int i=0;i<n;i++)//��ʼ�� 
			{
				this->node[i]=-1;//ȫ��Ϊ-1  ��ʼʱ 
			}
			bian = (w*)malloc(sizeof(w));//�߼��� ��̬���� 
			int j=0;
			int temp=0;
			while(temp!=-1)
			{
				cout<<"�����(-1�˳�)��� �յ� ��Ȩ\n";
				cin>>temp;//temp �� a�� 
				if(temp==-1)
				{
					break;
				}
				bian = (w*)realloc(bian,(this->bianSize+1)*sizeof(w));//����һ���� �߼��� �ռ�+1 
				bian[j].a=temp;//��ֵ a �� ��� 
				cin>>bian[j].b;//��ֵ b �� �յ� 
				cin>>bian[j].w;//��ֵ ��Ȩ 
				bian[j].next = this->node[bian[j].a-1];// �߼��� ָ�� ���㼯��
													//�����㼯�ϴ洢������һ���ߵ�λ�ã���ʼʱΪ-1��
													//  ����Ϊ �����0 ��ʼ ����-1�� 
				this->node[bian[j].a-1]=j;//���㼯�� ָ�� ��������ı� ���߼��� 
				
				
				j++;//����+1 
				this->bianSize++;//����+1 
				
			}
			this->nodeSize=n;
			flag=(fla *)malloc(n*sizeof(int));
			for(int i=0;i<this->nodeSize;i++)
			{
				flag[i].minValue=inf;
				flag[i].node=-1;
			}
		}
		
		void vist(){
			for(int i=0;i<this->bianSize;i++)//ѭ����� �߼��� 
			{
				cout<<bian[i].a<<"-->"<<bian[i].b<<" ���� : "<<bian[i].w<<" ��һ����"<<bian[i].next<<" \n";
			}
		}
		int min();//��flag��������С�Ĺ̶�  //���������±� 
		void chushiflag(int t);//�Ƚϣ������㷨�� //t==�����±�   
		void prim();//Prim�㷨 
};


int graph::min(){
	int min=inf;//����min �������޴� 
	int n=-1;//N ���� -1 
	for(int i=0;i<this->nodeSize;i++)//�����±��0��ʼ 
	{
		if(this->flag[i].minValue<min&&this->flag[i].minValue!=0)//
		//���flag����ĵ�i��ֵ С��min ���Ҳ�Ϊ�� 
		{
			min=this->flag[i].minValue;//��min���� ��Сֵ 
			n=i;//��¼ ������±� 
		}
	}
	
	
	return n;//����������±� ���㿪ʼ 
	
}


void graph::chushiflag(int t){//�Ƚ��㷨 
	int n=node[t];//��������  ��n�����±�Ϊ t �ģ���t+1��Ŷ��㣩 �ĳ������ 
	this->flag[t].minValue=0;//�����Լ�Ϊ0  ����� �Ѿ� ������ 
	while(n!=-1)//n != -1 �� ���г��� 
	{
		if(this->flag[bian[n].b-1].minValue>bian[n].w
				&&this->flag[bian[n].b-1].minValue!=0)
				//�ж� �����  �� ���� 
		//���� ��Сֵ   ʹ ����� �� �� ���ľ������ 
		{
			this->flag[bian[n].b-1].minValue=bian[n].w;
			//����ע�⣡�� bian[n].b�ǽڵ�ı��  ���������0��ʼ
			//��Ҫ -1    �� n����Ҫ  n���������±� 
			this->flag[bian[n].b-1].node=t+1;
			//t+1����Ϊ t�� �����±� node ������Ҫ�� ������ 
			n=bian[n].next;
			//�����һ�β��ͬ�� ���ȱ�   ������һ���� 
		}
		else
		{
			n=bian[n].next;	//��ʹ ������  ҲҪ�� ��һ�� ��  �����ˣ��� 
		}
	}
	return;
}

void graph::prim()
{
	this->chushiflag(0);//�� �����±�Ϊ 0 �Ŀ�ʼ  ���ڵ���Ϊ1 �Ŀ�ʼ 
	int temp=0;//��0��ʼ 
	while(temp<this->nodeSize-1)//ѭ�� nodeSize-1 ��  ��Ϊ���� 1 һ��ʼ���������� 
	{
		int min=this->min();//��flag������С��  �����̶�  min �������±� 
		cout<<flag[min].node<<"-->"<<min+1<<" Ȩֵ�� "<<flag[min].minValue<<"\n";
		//��� ��Ϣ
		 
		this->chushiflag(min);//���� ���� ���� 
		temp++;//����+1 ÿ������ ���� �鲢һ����   
		
	}
	
	
	
	return;
}


int main(int argc,char **argv)
{
	cout<<"�ڽӱ�����ʼ��\n";
	graph G;
	cout<<"\n";
	G.vist();
	cout<<"\n";
	cout<<"prim��С������·��Ϊ��\n"; 
	G.prim();


	
	
	
	
	
	
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<stack>


using namespace std;

typedef struct w{
	int a;//��a ��� 
	int b;// ��b �յ� 
	int w;//��Ȩ 
	int next;//��һ����λ�� 
}w;

class graph{
	public:
		int *node;//���� 
		w *bian;//��ʽǰ����  �߼��� 
		int bianSize;//�߸��� 
		
		int flag;//��¼BFS����� 
		int *book;//��¼�Ƿ񱻷��ʹ� 
		
		
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
			book=(int *)malloc(n*sizeof(int));
			memset(book,0,n*sizeof(int));
		}
		
		void vist(){
			for(int i=0;i<this->bianSize;i++)//ѭ����� �߼��� 
			{
				cout<<bian[i].a<<"-->"<<bian[i].b<<" ���� : "<<bian[i].w<<" ��һ����"<<bian[i].next<<" \n";
			}
		}
		
};




int main(int argc,char **argv)
{
	cout<<"�ڽӱ�����ʼ��\n";
	graph G;
	cout<<"\n�����ڽӱ�\n"; 
	G.vist();
	cout<<"\n\n";


	
	
	
	
	
	
	return 0;
}

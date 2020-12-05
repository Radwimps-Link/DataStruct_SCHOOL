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
		
		void bianli(int qidian)//Ѱ�� ĳһ���� �� ���� ����Ϊ����Ե�� ����-1�� 
		{
			int t = node[qidian];
			while(t!=-1)
			{
				cout<<bian[t].a<<"-->"<<bian[t].b<<" ���� : "<<bian[t].w<<" \n";//��� 
				t=bian[t].next;//t = ��һ���ߵ� �Ǳ꣨����һ�����������е�λ�ã� 
			}
		}
		
		void BFS(int zhongdian)//��ȱ��� ����Ϊ����Ե�ʱ���-1�� 
		{
			queue<w> q;//������� 
			int t=0;//t = 0 �� ��һ������ ��ʼ 
			//cout<<t+1<<" ";
			while(t!=zhongdian)//t������ Ҫ�ҵ��յ� 
			{
				int n = node[t];//��ʼ���� t���� �� ����  ���� ���� ��������� 
				while(n!=-1)//ѭ�� ���� t�� ���г��� 
				{
					 
					q.push(bian[n]);//������� 
					//cout<<bian[n].b<<" ";
					n=bian[n].next;//Ѱ����һ������ 
				}				
				if(q.empty())//��� qΪ��  ˵�� �Ѿ� �ޱ� �ɱ���  
							//�����ʱ ����ѭ���� ���� δ�ҵ� �յ� 
				{
					cout<<"BFSʧ����!\n";
					return;
				}
				t=q.front().b-1;// �Ӷ��� �� ȡ��һ�� ֵ  ��ʼ��һ�� ���� �ı��� 
				q.pop();//�������� 
				
			}
			cout<<"BFS�ҵ��ˣ�\n";//������� ѭ�� �� �� ˵�� t==�յ� �����ҵ��յ� 
			return;
		}
		
		
		void DFS(int zhongdian,int qidian)//��ȱ��� ����Ϊ����Ե�ʱ���-1�� 
		{
			
			int t=qidian;//t = ��� �� ��� ��ʼ
			
			int n=node[t];//��ʼ���� t���� �� ����		
			if(t==zhongdian&&book[t]==0)//��� t== �յ� ���� t == -1 �򷵻� 
			{
				cout<<"DFS�ҵ���\n";
				this->flag=1;
				book[t]=1;
				return;
			}
			if(n==-1||book[t]==1)
			{
				return;
			}
			//cout<<t+1<<" "; 
			book[t]=1;
			while(n!=-1)//t������ Ҫ�ҵ��յ� 
			{
				
				DFS(zhongdian,bian[n].b-1);
				n=bian[n].next;
			}
			if(this->flag!=1)
			{
				cout<<"DFSʧ��!\n";
			}
			return;					
		}
};




int main(int argc,char **argv)
{
	graph G;
	G.vist();
	cout<<"\n\n";
	G.bianli(2);
	cout<<"\n\n";
	int t;
	cout<<"������ҪѰ�ҵĽڵ�\n";
	cin>>t; 
	G.BFS(t-1);
	cout<<"\n";
	G.DFS(t-1,0);
	
	
	
	
	
	
	return 0;
}

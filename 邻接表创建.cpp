#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<stack>


using namespace std;

typedef struct w{
	int a;//点a 起点 
	int b;// 点b 终点 
	int w;//边权 
	int next;//下一个边位置 
}w;

class graph{
	public:
		int *node;//顶点 
		w *bian;//链式前向星  边集合 
		int bianSize;//边个数 
		
		int flag;//记录BFS的入度 
		int *book;//记录是否被访问过 
		
		
		graph()//初始化函数 
		{
			this->flag=0;
			cout<<"正在创建 有向图(带边权) 链式前向星\n";
			this->bianSize=0;//边个数 == 0 
			cout<<"输入节点个数\n";
			int n;//结点个数 
			cin>>n;
			this->node = (int *)malloc(n*sizeof(int));//给一维数组 顶点集合 分配空间 
			for(int i=0;i<n;i++)//初始化 
			{
				this->node[i]=-1;//全部为-1  开始时 
			}
			bian = (w*)malloc(sizeof(w));//边集合 动态分配 
			int j=0;
			int temp=0;
			while(temp!=-1)
			{
				cout<<"输入边(-1退出)起点 终点 边权\n";
				cin>>temp;//temp 是 a点 
				if(temp==-1)
				{
					break;
				}
				bian = (w*)realloc(bian,(this->bianSize+1)*sizeof(w));//输入一个边 边集合 空间+1 
				bian[j].a=temp;//赋值 a 点 起点 
				cin>>bian[j].b;//赋值 b 点 终点 
				cin>>bian[j].w;//赋值 边权 
				bian[j].next = this->node[bian[j].a-1];// 边集合 指向 顶点集合
													//（定点集合存储的是上一条边的位置，开始时为-1）
													//  （因为 数组从0 开始 所以-1） 
				this->node[bian[j].a-1]=j;//定点集合 指向 最新输入的边 （边集合 
				
				
				j++;//序列+1 
				this->bianSize++;//个数+1 
				
			}
			book=(int *)malloc(n*sizeof(int));
			memset(book,0,n*sizeof(int));
		}
		
		void vist(){
			for(int i=0;i<this->bianSize;i++)//循环输出 边集合 
			{
				cout<<bian[i].a<<"-->"<<bian[i].b<<" 长度 : "<<bian[i].w<<" 下一个："<<bian[i].next<<" \n";
			}
		}
		
};




int main(int argc,char **argv)
{
	cout<<"邻接表创建开始：\n";
	graph G;
	cout<<"\n遍历邻接表！\n"; 
	G.vist();
	cout<<"\n\n";


	
	
	
	
	
	
	return 0;
}

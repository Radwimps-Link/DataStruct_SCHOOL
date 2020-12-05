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
		
		void bianli(int qidian)//寻找 某一顶点 的 出度 （因为数组缘故 必须-1） 
		{
			int t = node[qidian];
			while(t!=-1)
			{
				cout<<bian[t].a<<"-->"<<bian[t].b<<" 长度 : "<<bian[t].w<<" \n";//输出 
				t=bian[t].next;//t = 下一条边的 角标（即下一条边在数组中的位置） 
			}
		}
		
		void BFS(int zhongdian)//广度遍历 （因为数组缘故必须-1） 
		{
			queue<w> q;//引入队列 
			int t=0;//t = 0 从 第一个顶点 开始 
			//cout<<t+1<<" ";
			while(t!=zhongdian)//t不等于 要找的终点 
			{
				int n = node[t];//开始遍历 t顶点 的 出度  并把 出度 放入队列中 
				while(n!=-1)//循环 遍历 t的 所有出度 
				{
					 
					q.push(bian[n]);//放入队列 
					//cout<<bian[n].b<<" ";
					n=bian[n].next;//寻找下一个出度 
				}				
				if(q.empty())//如果 q为空  说明 已经 无边 可遍历  
							//如果此时 还在循环中 ，即 未找到 终点 
				{
					cout<<"BFS失败了!\n";
					return;
				}
				t=q.front().b-1;// 从队列 中 取出一个 值  开始新一轮 出度 的遍历 
				q.pop();//弹出队列 
				
			}
			cout<<"BFS找到了！\n";//如果脱离 循环 ， 则 说明 t==终点 ，即找到终点 
			return;
		}
		
		
		void DFS(int zhongdian,int qidian)//广度遍历 （因为数组缘故必须-1） 
		{
			
			int t=qidian;//t = 起点 从 起点 开始
			
			int n=node[t];//开始遍历 t顶点 的 出度		
			if(t==zhongdian&&book[t]==0)//如果 t== 终点 或者 t == -1 则返回 
			{
				cout<<"DFS找到了\n";
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
			while(n!=-1)//t不等于 要找的终点 
			{
				
				DFS(zhongdian,bian[n].b-1);
				n=bian[n].next;
			}
			if(this->flag!=1)
			{
				cout<<"DFS失败!\n";
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
	cout<<"输入需要寻找的节点\n";
	cin>>t; 
	G.BFS(t-1);
	cout<<"\n";
	G.DFS(t-1,0);
	
	
	
	
	
	
	return 0;
}

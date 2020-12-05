#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<stack>

#define inf 0x3f3f3f2f

using namespace std;

typedef struct w{
	int a;//点a 起点 
	int b;// 点b 终点 
	int w;//边权 
	int next;//下一个边位置 
}w;

typedef struct fla{
	int minValue;
	int node;
}fla; 

class graph{
	public:
		int *node;//顶点 
		w *bian;//链式前向星  边集合 
		
		int bianSize;//边个数 
		int nodeSize;//顶点个数 
		
		fla *flag;//prim算法标记数组 
		
		
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
			this->nodeSize=n;
			flag=(fla *)malloc(n*sizeof(int));
			for(int i=0;i<this->nodeSize;i++)
			{
				flag[i].minValue=inf;
				flag[i].node=-1;
			}
		}
		
		void vist(){
			for(int i=0;i<this->bianSize;i++)//循环输出 边集合 
			{
				cout<<bian[i].a<<"-->"<<bian[i].b<<" 长度 : "<<bian[i].w<<" 下一个："<<bian[i].next<<" \n";
			}
		}
		int min();//找flag数组中最小的固定  //返回数组下标 
		void chushiflag(int t);//比较（核心算法） //t==数组下标   
		void prim();//Prim算法 
};


int graph::min(){
	int min=inf;//先令min 等于无限大 
	int n=-1;//N 等于 -1 
	for(int i=0;i<this->nodeSize;i++)//数组下标从0开始 
	{
		if(this->flag[i].minValue<min&&this->flag[i].minValue!=0)//
		//如果flag数组的第i个值 小于min 并且不为零 
		{
			min=this->flag[i].minValue;//令min等于 最小值 
			n=i;//记录 数组的下标 
		}
	}
	
	
	return n;//返回数组的下标 从零开始 
	
}


void graph::chushiflag(int t){//比较算法 
	int n=node[t];//顶点数组  令n等于下标为 t 的（即t+1编号顶点） 的出度入口 
	this->flag[t].minValue=0;//设置自己为0  即标记 已经 遍历过 
	while(n!=-1)//n != -1 即 还有出度 
	{
		if(this->flag[bian[n].b-1].minValue>bian[n].w
				&&this->flag[bian[n].b-1].minValue!=0)
				//判断 如果大  就 缩紧 
		//缩紧 最小值   使 树外的 点 到 树的距离最短 
		{
			this->flag[bian[n].b-1].minValue=bian[n].w;
			//这里注意！！ bian[n].b是节点的编号  由于数组从0开始
			//需要 -1    但 n不需要  n就是数组下标 
			this->flag[bian[n].b-1].node=t+1;
			//t+1是因为 t是 数组下标 node 里面需要存 顶点编号 
			n=bian[n].next;
			//继续找弧尾相同的 出度边   就是下一条边 
		}
		else
		{
			n=bian[n].next;	//即使 不满足  也要找 下一条 边  别忘了！！ 
		}
	}
	return;
}

void graph::prim()
{
	this->chushiflag(0);//从 数组下标为 0 的开始  即节点编号为1 的开始 
	int temp=0;//从0开始 
	while(temp<this->nodeSize-1)//循环 nodeSize-1 次  因为顶点 1 一开始就在树里面 
	{
		int min=this->min();//找flag里面最小的  把他固定  min 是数组下标 
		cout<<flag[min].node<<"-->"<<min+1<<" 权值： "<<flag[min].minValue<<"\n";
		//输出 信息
		 
		this->chushiflag(min);//进行 缩紧 操作 
		temp++;//次数+1 每次缩进 都能 归并一个点   
		
	}
	
	
	
	return;
}


int main(int argc,char **argv)
{
	cout<<"邻接表创建开始：\n";
	graph G;
	cout<<"\n";
	G.vist();
	cout<<"\n";
	cout<<"prim最小生成树路径为：\n"; 
	G.prim();


	
	
	
	
	
	
	return 0;
}

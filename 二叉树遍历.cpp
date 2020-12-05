//二叉树 的三种遍历
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack> 
#define ElemType char


using namespace std;

class tree{
	public:
		ElemType *t;
		int NodeNum;///节点个数 
		tree()
		{
			NodeNum=0;
			cout<<"请按层序顺序输入二叉树(空为# 结束为E)\n";
			t=(ElemType *)malloc(sizeof(ElemType)); 
			ElemType temp;
			while(temp!='E')
			{
				cin>>temp;	
				if(temp=='E')
				{
					break;
				}
				t=(ElemType *)realloc(t,(NodeNum+1)*sizeof(ElemType));
				t[NodeNum]=temp;
				NodeNum++;
			}
			 
		}
		void vist()//层序输出 
		{
			for(int i=0;i<this->NodeNum;i++)
			{
				cout<<this->t[i]<<" ";
			}
		}
		void DLR_re(ElemType *a,int i)//递归 
		{
			if(i>NodeNum)
			{
				return;
			}
			cout<<*a<<" ";
			this->DLR_re(a+i,2*i);
			this->DLR_re(a+i+1,2*i+1);
			return;
		}
		void LDR_re(ElemType *a,int i)//递归 
		{
			if(i>NodeNum)
			{
				return;
			}
			this->LDR_re(a+i,2*i);
			cout<<*a<<" ";
			this->LDR_re(a+i+1,2*i+1);
			return;
		}
		void LRD_re(ElemType *a,int i)//递归 
		{
			if(i>NodeNum)
			{
				return;
			}
			this->LRD_re(a+i,2*i);
			this->LRD_re(a+i+1,2*i+1);
			cout<<*a<<" ";

			return;
		}
		void LDR()//非递归 用栈 中序 
		{
			stack<ElemType> s;
			int i=1;
			while(i<=NodeNum||!s.empty())
			{
				if(i<=NodeNum)
				{
					s.push(i);					
					i=2*i;
				}
				else
				{
					i=s.top();
					s.pop();
					cout<<this->t[i-1]<<" ";
					i=2*i+1;	
				}
			}
			
			
			return;
		 } 
		void DLR()//非递归 用栈 前序 
		{
			stack<ElemType> s;
			int i=1;
			while(i<=NodeNum||!s.empty())
			{
				if(i<=NodeNum)
				{
					cout<<this->t[i-1]<<" ";
					s.push(i);					
					i=2*i;
				}
				else
				{
					i=s.top();
					s.pop();
					i=2*i+1;	
				}
			}
			
			
			return;
		 } 
		void LRD()//非递归 用栈 后序 
		{
			stack<ElemType> s;
			int i=1;
			int a = -1; 
			while(i<=NodeNum||!s.empty())
			{
				if(i<=NodeNum)
				{
					if(2*i==a)//左子树已经完成输出 
						i=2*i+1;//往右走 
					else if(2*i+1==a)//右子树已经完成输出//输出根节点 
					{
						cout<<this->t[i-1]<<" ";
						break;
					} 
					else
					{
						s.push(i);
						i=2*i;//往左走 						
					}

			
				}
				else
				{
					i=s.top();//回退 
					i=2*i+1;
					if(i<=NodeNum)//存在右孩子 
					{
						i=s.top();//回退 
						cout<<this->t[i-1]<<" ";
						i=2*i+1;
						s.push(i);
					}
					else//如果没右孩子   说明两个孩子都没有 是叶子节点 直接输出 
					{
						i=s.top();//回退 
						a =  i;
						cout<<this->t[i-1]<<" ";
						s.pop();
						i=s.top();//回到上一层 
						if(2*i+1==a)	//说明右孩子已经被输出了
						/////那么输出根节点就可以了  在返回上一层 
						{
							a = i;
							cout<<this->t[i-1]<<" ";
							s.pop();
							i=s.top();
						}
						else
						{
							i=2*i+1;
						}
					}
					
				}
			}
			
			
			return;
		 } 
};



int main(int argc,char**argv)
{
	tree T;
	cout<<"层序输出\n";
	T.vist();
	cout<<"\n"; 
	cout<<"前根遍历\n"; 
	T.DLR_re(T.t,1);
	cout<<"\n";
	cout<<"中根遍历\n";
	T.LDR_re(T.t,1);
	cout<<"\n";
	cout<<"后根遍历\n";
	T.LRD_re(T.t,1);
	cout<<"\n";
	cout<<"非递归前根遍历\n";
	T.DLR();
	cout<<"\n";
	cout<<"非递归中根遍历\n";
	T.LDR();
	cout<<"\n";
	cout<<"非递归后根遍历\n";
	T.LRD();
	return 0;
}

 

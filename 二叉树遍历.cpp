//������ �����ֱ���
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
		int NodeNum;///�ڵ���� 
		tree()
		{
			NodeNum=0;
			cout<<"�밴����˳�����������(��Ϊ# ����ΪE)\n";
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
		void vist()//������� 
		{
			for(int i=0;i<this->NodeNum;i++)
			{
				cout<<this->t[i]<<" ";
			}
		}
		void DLR_re(ElemType *a,int i)//�ݹ� 
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
		void LDR_re(ElemType *a,int i)//�ݹ� 
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
		void LRD_re(ElemType *a,int i)//�ݹ� 
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
		void LDR()//�ǵݹ� ��ջ ���� 
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
		void DLR()//�ǵݹ� ��ջ ǰ�� 
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
		void LRD()//�ǵݹ� ��ջ ���� 
		{
			stack<ElemType> s;
			int i=1;
			int a = -1; 
			while(i<=NodeNum||!s.empty())
			{
				if(i<=NodeNum)
				{
					if(2*i==a)//�������Ѿ������� 
						i=2*i+1;//������ 
					else if(2*i+1==a)//�������Ѿ�������//������ڵ� 
					{
						cout<<this->t[i-1]<<" ";
						break;
					} 
					else
					{
						s.push(i);
						i=2*i;//������ 						
					}

			
				}
				else
				{
					i=s.top();//���� 
					i=2*i+1;
					if(i<=NodeNum)//�����Һ��� 
					{
						i=s.top();//���� 
						cout<<this->t[i-1]<<" ";
						i=2*i+1;
						s.push(i);
					}
					else//���û�Һ���   ˵���������Ӷ�û�� ��Ҷ�ӽڵ� ֱ����� 
					{
						i=s.top();//���� 
						a =  i;
						cout<<this->t[i-1]<<" ";
						s.pop();
						i=s.top();//�ص���һ�� 
						if(2*i+1==a)	//˵���Һ����Ѿ��������
						/////��ô������ڵ�Ϳ�����  �ڷ�����һ�� 
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
	cout<<"�������\n";
	T.vist();
	cout<<"\n"; 
	cout<<"ǰ������\n"; 
	T.DLR_re(T.t,1);
	cout<<"\n";
	cout<<"�и�����\n";
	T.LDR_re(T.t,1);
	cout<<"\n";
	cout<<"�������\n";
	T.LRD_re(T.t,1);
	cout<<"\n";
	cout<<"�ǵݹ�ǰ������\n";
	T.DLR();
	cout<<"\n";
	cout<<"�ǵݹ��и�����\n";
	T.LDR();
	cout<<"\n";
	cout<<"�ǵݹ�������\n";
	T.LRD();
	return 0;
}

 

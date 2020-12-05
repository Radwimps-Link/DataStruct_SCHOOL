#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack> 
#include<string>
#include<cctype>
#include<cstring>

using namespace std;

char Precede(char a,char b){     //< > = 都代表优先级 
								 //只考虑 + - * / （ ） 的运算 
	if(a == '+'||a == '-'){
		if(b == '+'||b == '-'||b == ')'||b == '#')return '>';
		else return '<';
	}
	else if(a == '*'||a == '/'){
		if(b == '+'||b == '-'||b == ')'||b == '#'||b == '*'||b == '/')return '>';
		else return '<';
	}
	else if(a == '('){
		if(b == ')')return '=';
		else return '<';
	}
	else if(a == ')'){
		return '>';
	}
	else{
		if(b == '#')return '=';
		else return '<';
	}
} 



double yunsuan(int a,int b,int o)
{	
	switch (o)
	{
		case '+':
			return(a+b);
		case '-':
			return(a-b);
		case '*':
			return(a*b);
		case '/':
			return(a/b);
	}
}


int main()
{

	
	stack<double> num;///
	stack<char> optr;///
	stack<double> optrflag; 
	string str;
	optr.push('#');
	optrflag.push(-100);
	cout<<"请输入表达式"<<"\n";
	cin>>str;
	str.append("#");
	string::iterator itr = str.begin();
	char optr1;
	int num1,num2;
	int book=0;
	book=optrflag.top();
	for(;itr!=str.end();)
	{

		char a = *itr;
		if(isdigit(a))
		{
			
			int t = atoi(&a) ;
			num.push(t);
			itr++;
		}
		else
		{
			switch(Precede(optr.top(),a))
			{
				case '<':
					optr.push(a);itr++;
					break;
				case '=':
					optr.pop();itr++;
					break;
				case '>':	
					optr1=optr.top();
					optr.pop();
					num1=num.top();
					num.pop();
					num2=num.top();
					num.pop();
					num.push(yunsuan(num1,num2,optr1));
					break;
			 } 
			
		}
	
	}
		cout<<num.top()<<"\n";


	return 0;
 } 

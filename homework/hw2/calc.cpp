#include<cstdio>
#include<stdio.h>
#include<math.h>
int cmp(char m)//运算符优先级
{
	if(m=='+'||m=='-')return 1;
	else if(m=='*'||m=='/')return 2;
	else if(m=='^')return 3;
}
int trans(char input[], double s2[], int &top2)//中缀转后缀,返回长度
{
	//为方便存储，将所有运算符的ASCII-100，将其存入double型数组中，采用判断数组中值是否为负的方法来区分运算符
	//特别的，对于负数而言，减号可当作运算符处理，故而可以对输入逐字符处理。 
	double s1[1000];//运算符栈
	int top1 = -1;
	int i=0;
	int len=0;
	int flag=0;
	while(input[i] !='\0')
	{
		if('0'<=input[i]&&'9'>=input[i])
		{
			s2[++top2]=input[i]-48;
			++i;
			++len;
			while('0'<=input[i]&&'9'>=input[i]) //处理整数部分 
			{
				s2[top2]=input[i]-48+s2[top2]*10;
				i++;
			}
			if(input[i]=='.')//处理小数部分 
			{
				i++;
				int j=1;
				while('0'<=input[i]&&'9'>=input[i])
				{
					s2[top2]=input[i]-48+s2[top2]*10;
					j++;
					i++;
				}
				s2[top2]=s2[top2]/pow(10,j-1);
			}
		}
		else if (input[i]=='(')
		{
			s1[++top1]='('-100;
			++i;
			flag++;
		}
		else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='^')
				{
					if(top1==-1||s1[top1]=='('-100||cmp(input[i])>cmp(s1[top1]+100))
					{
						s1[++top1]=input[i]-100;
						++i;
					}
					else
					{
					s2[++top2]=s1[top1--];
					++len;
					}
				}
		else if(input[i]==')')
		{
			while (s1[top1]!=('('-100))
				{
				s2[++top2] = s1[top1--];
				len++;
				}
			if(s1[top1]!='(')
			{
			printf("wrong");
			return -1;
			}
			else --top1;//出栈左括号 
			++i;
			flag--;
		}
	}
	while (top1 !=-1)
	{
		s2[++top2] = s1[top1--];//出栈辅助栈剩余表达式 
		++i;
		++len;
	}
	if(flag!=0)
		{
		printf("wrong");
		return -1;	
		}
	return len;
}
double count(double a,char sym,double b)//运算函数 
{
	if(sym=='+')return a+b;
	if(sym=='-')return a-b;
	if(sym=='*')return a*b;
	if(sym=='/')
	{
		if(b==0)
		{
			printf("error\n");
			return 0;
		}
		else return a/b;
	}
	if(sym=='^')return pow(a,b);
}
double calc(double exp[],int len)//后缀式计算函数 
{
	int i;
	double a,b,c;
	double stack[1000];
	int top=-1;
	
	char sym;
	for(i=0;i<len;++i)
	{
		if(exp[i]<0)
		{
			sym=exp[i]+100;
			b=stack[top--];
			a=stack[top--];
			c = count(a,sym,b);
			stack[++top]=c;
		}
		else
		stack[++top]=exp[i];
	}
	
	if(top!=0)printf("wrong");
	return stack[top];
}
int main()
{
	char input[1000];
	gets(input);
	double temp[1000]={0};
	int top2=-1;
	
	int len =trans(input,temp,top2);
	if(len!=-1)printf("%.2f",calc(temp,len));
	return 0;
}

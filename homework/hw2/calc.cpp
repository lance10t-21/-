#include<cstdio>
#include<stdio.h>
#include<math.h>
int cmp(char m)//��������ȼ�
{
	if(m=='+'||m=='-')return 1;
	else if(m=='*'||m=='/')return 2;
	else if(m=='^')return 3;
}
int trans(char input[], double s2[], int &top2)//��׺ת��׺,���س���
{
	//Ϊ����洢���������������ASCII-100���������double�������У������ж�������ֵ�Ƿ�Ϊ���ķ��������������
	//�ر�ģ����ڸ������ԣ����ſɵ�������������ʶ����Զ��������ַ����� 
	double s1[1000];//�����ջ
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
			while('0'<=input[i]&&'9'>=input[i]) //������������ 
			{
				s2[top2]=input[i]-48+s2[top2]*10;
				i++;
			}
			if(input[i]=='.')//����С������ 
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
			else --top1;//��ջ������ 
			++i;
			flag--;
		}
	}
	while (top1 !=-1)
	{
		s2[++top2] = s1[top1--];//��ջ����ջʣ����ʽ 
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
double count(double a,char sym,double b)//���㺯�� 
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
double calc(double exp[],int len)//��׺ʽ���㺯�� 
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

/*
��Ŀ����
Copy ��¬ţ������˵��һƬ�� yz �������������Ų��ٱ��أ����� Copy ���������������Ϊ n���������ء�
¬ţ������Copy���ﹲ��n�����أ��ֱ���ڵ� Pi �� (1<=Pi<=N)����Copy����֪��ÿ������֮��ľ��롣
���� Copy �� 1�����������Ҫ������еı��ز��� n�������뿪��Copy ������ֻ��������Ϊ��Ѱ��һ�����ʵ���·��ʹ�����߹��ľ�����̡�
## �����ʽ

��һ��һ�������� N(1<=N<=100)
������һ�� N*N �ľ��󣬵� i+1 �е� j�е����ֱ�ʾ���� i,j ֮��ľ��롣ÿ�������ÿո���������뱣֤ i toj<=1000����ע��� i to j ���벢��һ������ j to i�ľ��롣

�� N+2 ��һ������ P(0<=P<=10)$��

�� N+3 �й� P ���ÿո��������������ʾ�б��ص������š�

## �����ʽ

һ��������Ϊ Copy ���ȫ��������Ҫ����̾��롣���ݱ�֤��С�ڵ��� maxlongint��
### �������� #1

��������1
2
0 4
5 0
2
1 2
��������2
3
0 2 6
1 0 4
7 10 0
1
2
�������1
4
�������1
6
*/
#include<bits/stdc++.h>
using namespace std;
int s[11]={0};
long long sum=0,ans=0x7fffffff;
long long a[200][200];			
bool b[100];
int n,p;
int dfs(int now,int j,long long sum)
{
	if(j==0)ans=min(ans,sum+a[now][n]);
	else 
		for(int x=1;x<=p;x++)
			if(!s[x])
			{
				s[x]=1;
				dfs(b[x],j-1,sum+a[now][b[x]]);
				s[x]=0;
			}	
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);		
	scanf("%d",&p);
	for(i=1;i<=p;i++)scanf("%d",&b[i]);
	
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j!=k)a[i][j]=min(a[i][k]+a[k][j],a[i][j]);							
	dfs(1,p,0);
	printf("%lld",ans);			
	return 0;
}

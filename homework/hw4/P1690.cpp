/*
题目描述
Copy 从卢牛那里听说在一片叫 yz 的神的领域埋藏着不少宝藏，于是 Copy 来到了这个被划分为 n个区域的神地。
卢牛告诉了Copy这里共有n个宝藏，分别放在第 Pi 个 (1<=Pi<=N)区域。Copy还得知了每个区域之间的距离。
现在 Copy 从 1号区域出发，要获得所有的宝藏并到 n号区域离开。Copy 很懒，只好来找你为他寻找一条合适的线路，使得他走过的距离最短。
## 输入格式

第一行一个正整数 N(1<=N<=100)
接下来一个 N*N 的矩阵，第 i+1 行第 j列的数字表示区域 i,j 之间的距离。每个距离用空格隔开，距离保证 i toj<=1000。请注意的 i to j 距离并不一定等于 j to i的距离。

第 N+2 行一个整数 P(0<=P<=10)$。

第 N+3 行共 P 个用空格隔开的整数，表示有宝藏的区域编号。

## 输出格式

一个整数，为 Copy 获得全部宝藏需要的最短距离。数据保证答案小于等于 maxlongint。
### 样例输入 #1

样例输入1
2
0 4
5 0
2
1 2
样例输入2
3
0 2 6
1 0 4
7 10 0
1
2
样例输出1
4
样例输出1
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

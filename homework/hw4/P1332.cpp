/*
题目描述 
军团是一个 n 行 m 列的矩阵，每个单元是一个血色先锋军的成员。
感染瘟疫的人，每过一个小时，就会向四周扩散瘟疫，直到所有人全部感染上瘟疫。你已经掌握了感染源的位置，任务是算出血色先锋军的领主们感染瘟疫的时间，并且将它报告给巫妖王，
以便对血色先锋军进行一轮有针对性的围剿。
 
 输入 
第1行：四个整数 n，m，a，b
表示军团矩阵有n行m列。有a个感染源，b为血色敢死队中领主的数量。
接下来a行：每行有两个整数x，y表示感染源在第 x 行第 y 列。
接下来 b 行：每行有两个整数 x，y，表示领主的位置在第 x 行第 y 列。
 输出 
第 1至 b 行：每行一个整数，表示这个领主感染瘟疫的时间，输出顺序与输入顺序一致。如果某个人的位置在感染源，那么他感染瘟疫的时间为 0。


样例：
	输入 
	5 4 2 3
	1 1
	5 4
	3 3
	5 3
	2 4
输出：
	3
	1
	3
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a,b;
struct qq{int x,y;}q[250005];
int qr,ql;
bool v[505][505];
int map[505][505],x,y; 
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    memset(map,-1,sizeof(map));
    memset(v,true,sizeof(v));
    ql=1;
    qr=1;
    for (int i=1;i<=a;i++){ 
        scanf("%d%d",&x,&y);
        map[x][y]=0;
        q[qr].x=x;
        q[qr].y=y;
        qr++;
        v[x][y]=false;
    }
    while (ql<qr){
        int xx,yy;
        xx=q[ql].x;
        yy=q[ql].y;
        ql++;
        for (int i=0;i<=3;i++){
            if (v[xx+dx[i]][yy+dy[i]]&&xx+dx[i]>0&&xx+dx[i]<=n&&yy+dy[i]>0&&yy+dy[i]<=m){
                v[xx+dx[i]][yy+dy[i]]=false;
                q[qr].x=xx+dx[i];
                q[qr].y=yy+dy[i];
                qr++;
                map[xx+dx[i]][yy+dy[i]]=map[xx][yy]+1;
            }
        }
    }
    for (int i=1;i<=b;i++){ 
        scanf("%d%d",&x,&y);
        printf("%d\n",map[x][y]);
    }
    return 0;
}



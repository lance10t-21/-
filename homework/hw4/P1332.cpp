/*
��Ŀ���� 
������һ�� n �� m �еľ���ÿ����Ԫ��һ��Ѫɫ�ȷ���ĳ�Ա��
��Ⱦ���ߵ��ˣ�ÿ��һ��Сʱ���ͻ���������ɢ���ߣ�ֱ��������ȫ����Ⱦ�����ߡ����Ѿ������˸�ȾԴ��λ�ã����������Ѫɫ�ȷ���������Ǹ�Ⱦ���ߵ�ʱ�䣬���ҽ����������������
�Ա��Ѫɫ�ȷ������һ��������Ե�Χ�ˡ�
 
 ���� 
��1�У��ĸ����� n��m��a��b
��ʾ���ž�����n��m�С���a����ȾԴ��bΪѪɫ��������������������
������a�У�ÿ������������x��y��ʾ��ȾԴ�ڵ� x �е� y �С�
������ b �У�ÿ������������ x��y����ʾ������λ���ڵ� x �е� y �С�
 ��� 
�� 1�� b �У�ÿ��һ����������ʾ���������Ⱦ���ߵ�ʱ�䣬���˳��������˳��һ�¡����ĳ���˵�λ���ڸ�ȾԴ����ô����Ⱦ���ߵ�ʱ��Ϊ 0��


������
	���� 
	5 4 2 3
	1 1
	5 4
	3 3
	5 3
	2 4
�����
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



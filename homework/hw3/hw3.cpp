#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXVALUE 32767		
#define NODENUM 26		//Ҷ�ӽ����
typedef struct
{
	char data;				
	int weight;				
	int parent, lch, rch;	
}htNode,*huffmanTree;		
 
typedef char** huffmanCode;	//��һ��*�Ǵ�������ָ�������˵����������
							//�ڶ���*˵������ָ�����飬�������char����������ÿ��Ԫ�ض���*huffmanCode����
 
int initHuffmanTree(huffmanTree& HT);								//��ʼ����������
void creatHuffmanTree(huffmanTree& HT, int n);						//������������
void createHuffmanCode(huffmanTree HT, huffmanCode &HC, int n);		//��д����������

int initHuffmanTree(huffmanTree& HT)
{
	HT = (htNode*)malloc(sizeof(htNode) * (2 * NODENUM));			//����ռ� 
	for (int i = 1; i <= 2 * NODENUM - 1; i++)	
	{
		HT[i].parent = HT[i].lch = HT[i].rch = -1;					//˫�׺ͺ��ӵ�ֵ����Ϊ-1
	}
	int a[26]={568,116,182,270,888,224,175,384,565,21,51,342,188,485,607,96,7,413,429,671,176,81,165,5,128,6};//Ȩ�ظ�ֵ 

	for (int i = 1; i <=26; i++)
	{
	HT[i].data = 'a'+i-1;				//��ÿ����㸳��Ȩֵ
	HT[i].weight=a[i-1];				//��ÿ����㸳������
	}
	return 1;
}
 
void creatHuffmanTree(huffmanTree& HT, int n)
{
	if (n <= 1)return;													//��������С�ڵ���1��������
	int min1, min2;														//�洢ÿ��ѡȡ��С��������Ȩֵ
	int rnode, lnode;													//���������±�ֵ�����洢ÿ��ѡȡ��С���������±�
	for (int i = n + 1; i <= 2 * n -1; i++)								//Ҫ����n-1����㣬����Ҫ����n��1���Ҵ��±�Ϊn+1��ʼ�洢
	{
		int min1 = MAXVALUE; int lnode = -1;														
		int min2 = MAXVALUE; int rnode = -1;
		for (int j = 1; j <= i - 1; j++)								//��Ϊ��������ǰn����ѡ����С����������Ȩֵ����������һ����͵���ǰn+1����ѡ����С����������Ȩֵ							
		{																
				if (HT[j].weight < min1 && HT[j].parent == -1)			
				{
					min2 = min1;	rnode = lnode;						
					min1 = HT[j].weight; lnode = j;						
				}
				else if (HT[j].weight < min2 && HT[j].parent == -1)
				{
					min2 = HT[j].weight;
					rnode = j;
				}
		}
		HT[lnode].parent = HT[rnode].parent = i;						//��С��������parent��Ϊ���ɽ����±�
		HT[i].lch = lnode; HT[i].rch = rnode;							//���ɽ�������Ϊ��С��min1���±꣬�Һ���ͬ��
		HT[i].weight = HT[lnode].weight + HT[rnode].weight;				//���ɽ���Ȩֵ������С����Ȩֵ���
	}
		
}
 
void createHuffmanCode(huffmanTree HT, huffmanCode& HC, int n)
{
	HC = (huffmanCode)malloc(sizeof(huffmanCode) * n + 1);				//����n + 1��huffmanCode��СhuffmanCode���͵���ʱ�ռ�																//��Ϊ�±��Ǵ�һ��ʼ����������Ҫ����Ƚ���һ���Ľ�㣬�͹��������Ľṹ��Ӧ���������
	char* cd = (char*)malloc(sizeof(char) * n);							//����n��char��Сchar���͵���ʱ�ռ䣬�����ʱ�����¼ÿ�α��������ı���
	int start = 0,c = 0,f = 0;											//startΪcd�����¼�±꣬c��ʼΪҶ�ӽ���±꣬������Ǻ��ӽ����±꣬f��¼˫�׽����±�
	cd[n - 1] = '\0';												
	for (int i = 1; i <= n; i++)										//ֻҪҶ�ӽ��ı���
	{
		start = n - 1;											
		c = i;	
		f = HT[c].parent;
		while (f != -1)													//���ڵ�û��˫��
		{
			start--;
			if (HT[f].lch == c)											//�����Ӿ���0���Һ��Ӿ�Ϊ1
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f; f = HT[c].parent;									//������ӽ�
		}
		HC[i] = (char*)malloc(sizeof(char) * (n - start));				//�����������������n - start��char��С��char*���͵���ʱ�ռ�
		strcpy(HC[i], &cd[start]);										//cd���¼�ı����HC�ĵ�i������
	}
	free(cd);															//�ͷ���ʱ�ռ�
}
int main()
{
	huffmanTree HT ;
	initHuffmanTree(HT);
	huffmanCode HC;
	creatHuffmanTree(HT,NODENUM);
	createHuffmanCode(HT,HC,NODENUM);

	for (int i = 1; i <= 26; i++)								//�����������
	{
		printf("%c:\t",HT[i].data);
		printf("%s\n", HC[i]);
	}
	return 0;
}


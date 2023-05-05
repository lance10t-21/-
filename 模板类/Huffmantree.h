#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory.h>
#ifdef __unix
#define  N_CHAR  (0x80 - 0x20)//仅以可打印字符为例
struct HuffChar//Huffman字符
{
	char ch; unsigned int weight; //字符、频率
	HuffChar(char c = '^', unsigned int w = 0) : ch(c), weight(w) {};
	// 比较器、判等器
	bool operator< (HuffChar const& hc) { return weight > hc.weight; } //频率越大，霍夫曼编码值越小
	bool operator<= (HuffChar const& hc) { return weight >= hc.weight; }
	bool operator> (HuffChar const& hc) { return weight < hc.weight; } //频率越小，霍夫曼编码值越大
	bool operator>= (HuffChar const& hc) { return weight <= hc.weight; }
	bool operator== (HuffChar const& hc) { return weight == hc.weight; }
	bool operator!= (HuffChar const& hc) { return weight != hc.weight; }
};//书上p145代码5.29，完成huffchar结构 

class Bitmap//位图Bitmap类 
{ 
private:
    unsigned char* M;
    Rank N, _sz; //位图空间M[]，N*sizeof(char)*8个比特中含_sz个有效位
protected:
    void init(Rank n){
        M = new unsigned char[N = (n + 7) / 8]; memset(M, 0, N); _sz = 0;}
public:
    Bitmap(Rank n = 8) { init(n); } //按指定容量创建位图
    ~Bitmap() { delete[] M; M = NULL; _sz = 0; } //析构时释放位图空间

    Rank size() { return _sz; }
    void set(Rank k) { expand(k); _sz++; M[k >> 3] |= (0x80 >> (k & 0x07)); }
    void clear(Rank k) { expand(k); _sz--; M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
    bool test(Rank k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }

    char* bits2string(Rank n) //将前n位转换为字符串——
    { 
        expand(n - 1); //此时可能被访问的最高位为bitmap[n - 1]
        char* s = new char[n + 1]; s[n] = '\0'; //字符串所占空间，由上层调用者负责释放
        for (Rank i = 0; i < n; i++) s[i] = test(i) ? '1' : '0';
        return s; //返回字符串位置
    }
    void expand(Rank k)//若被访问的Bitmap[k]已出界，则需扩容
    { 
        if (k < 8 * N) return; //仍在界内，无需扩容
        Rank oldN = N; unsigned char* oldM = M;
        init(2 * k); //与向量类似，加倍策略
        memcpy_s(M, N, oldM, oldN);
        delete[] oldM; //原数据转移至新空间
    }
};//完成位图Bitmap类的定义
class HuffTable//Huffman编码表
{
public:
    HuffTable() {};
    HuffTable(char, char*);
    ~HuffTable();
    bool put(char, char*); 
    char** get(char k);
private:
    Vector<char> key;
    Vector<char*> value;
};
HuffTable::HuffTable(char k,char* v)
{
    key.insert(k);
    value.insert(v);
}
HuffTable::~HuffTable()
{
    key.~Vector();
    value.~Vector();
}
inline bool HuffTable::put(char k, char* v)
{
    if (key.find(k) != -1)return false;
    key.insert(k);
    value.insert(v);
    return true;
}
inline char** HuffTable::get(char k)
{
    Rank r = key.find(k);
    if (r==-1)return nullptr;
    
    else return &value[r];
    
}
using HuffTree = BinTree<HuffChar>; //Huffman树，由BinTree派生，节点类型为HuffChar
using HuffForest = List<HuffTree*>; //Huffman森林
using HuffCode = Bitmap; //Huffman二进制编码

int* statistics(char*); //根据样本文件统计各字符出现频率
extern HuffForest* initForest(int*); //创建编码树森林
extern HuffTree* generateTree(HuffForest*); //构造编码树
extern HuffTable* generateTable(HuffTree*); //由编码树转换为编码表
extern int encode(HuffTable*, Bitmap*, char*); //明文的编码，返回编码长度
extern void decode(HuffTree*, Bitmap*, int); //二进制串的解码
#endif
 

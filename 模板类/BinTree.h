#include "BinNode.h" //���ö��������ģ����
template <typename T> class BinTree {
protected:
 
    int _size; //��ģ
 
    BinNodePosi(T) _root; //���ڵ�
 
    virtual int updateHeight(BinNodePosi(T) x); //���µ�ǰ�ڵ�߶�
 
    void updateHeightAbove(BinNodePosi(T) x); //�����������Ƚڵ�߶�
 
public:
 
    /*--��������������--*/
    BinTree(): _size(0), _root(NULL) {}
 
    ~BinTree() { if (_size > 0) remove(_root); }
 
    /*--���ýӿ�--*/
 
    int size() const { return _size; } //��ģ
 
    bool empty() const { return !_root; } //�п�
 
    BinNodePosi(T) root() const { return _root; } //ȡ��
    BinNodePosi(T)  insertAsRoot(T const &e); //������ڵ�
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e); //��Ϊ���ӽڵ����
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e); //��Ϊ�Һ��ӽڵ����
    BinNodePosi(T) attachaAsLC(BinNodePosi(T) x, BinTree <T>* &S); //��Ϊ����������
    BinNodePosi(T) attachaAsRC(BinNodePosi(T) x, BinTree <T>* &S); //��Ϊ����������
    int remove(BinNodePosi(T) x); //ɾ����x�ڵ�Ϊ������������������ԭ�ȵĹ�ģ 
 
    BinTree<T>* secede(BinNodePosi(T) x); //ɾ��������������ת��Ϊ�������� 
 
    /*--�����ӿ�--*/
 
    template <typename VST> void travLevel(VST&visit) //��α���
    { if (_root) _root->travLevel(visit); }
 
    template <typename VST> void travPre(VST&visit) //�������
    { if (_root) _root->travPre(visit); }
    
    template <typename VST> void travIn(VST&visit) //�������
    { if (_root) _root->travIn(visit); }
    
    template <typename VST> void travPost(VST&visit) //�������
    { if (_root) _root->travPost(visit); }
    
    /*--�ж������Ƚ���--*/
    bool operator>(BinTree<T> const& t)
    { return _root && t._root && lt(_root, t._root); }
    bool operator<(BinTree<T> const& t)
    { return _root && t._root && lt(_root, t._root); }
    bool operator==(BinTree<T> const& t) 
    { return _root && t._root && (_root == t._root); }
    bool operator!=(BinTree<T> const& t) 
    { return _root && t._root && (_root != t._root); }
    bool operator>=(BinTree<T> const& t) 
    { return _root && t._root && (_root >= t._root); }
    bool operator<=(BinTree<T> const& t) 
    { return _root && t._root && (_root <= t._root); }
};

template <typename T> int BinTree<T>::updateHeight( BinNodePosi(T) x )
{
	return x->height = 1 + max( stature (x -> lc), stature (x -> rc));
}
template <typename T> void BinTree<T>::updateHeightAbove( BinNodePosi(T) x )
{
	while(x){ updateHeight (x); x = x->parent;}
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const &e)
{ _size ++; return _root = new BinNode<T>(e); }                         //���嵱�����ڵ����յĶ�����
 
template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e)
{ _size ++; x->insertAsLC(e); updateHeightAbove(x); return x->lchild; }   //�����Ϊ��������
 
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{ _size ++; x->insertAsRC(e); updateHeightAbove(x); return x->rchild; }   //�����Ϊ�����Һ���

template <typename T>//��Ϊ������ 
BinNodePosi(T) BinTree<T>::attachaAsLC(BinNodePosi(T) x, BinTree <T>* &S)
{//�������� 
    if ( x->lc = S->root ) x->lc->parent = x;
    _size += S->_size; updateHeightAbove(x);
    S->root = NULL; S->size = 0; release(S); S = NULL;
    return x;
}
template <typename T>//as right child tree
BinNodePosi(T) BinTree<T>::attachaAsRC(BinNodePosi(T) x, BinTree <T>* &S)
{
    if ( x->rc = S->root ) x->rc->parent = x;
    _size += S->_size; updateHeightAbove(x);
    S->root = NULL; S->size = 0; release(S); S = NULL;
    return x;
}
template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x) {
    IsLChild(x) ? x->parent->lChild = NULL: x->parent->rChild = NULL;
    updateHeightAbove(x.parent);
    int n = removeAt(x); return n;
}
template <typename T>
int removeAt(BinNodePosi(T) x) {
    if (x) return 0;
    int n = 1 + removeAt(x->lChild) +  removeAt(x->rChild);
    release(x); 
    return n;
}

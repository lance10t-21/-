#include "BinNode.h" //引用二叉树结点模板类
template <typename T> class BinTree {
protected:
 
    int _size; //规模
 
    BinNodePosi(T) _root; //根节点
 
    virtual int updateHeight(BinNodePosi(T) x); //更新当前节点高度
 
    void updateHeightAbove(BinNodePosi(T) x); //更新所有祖先节点高度
 
public:
 
    /*--构造与析构函数--*/
    BinTree(): _size(0), _root(NULL) {}
 
    ~BinTree() { if (_size > 0) remove(_root); }
 
    /*--常用接口--*/
 
    int size() const { return _size; } //规模
 
    bool empty() const { return !_root; } //判空
 
    BinNodePosi(T) root() const { return _root; } //取根
    BinNodePosi(T)  insertAsRoot(T const &e); //插入根节点
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e); //作为左孩子节点插入
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e); //作为右孩子节点插入
    BinNodePosi(T) attachaAsLC(BinNodePosi(T) x, BinTree <T>* &S); //作为左子树插入
    BinNodePosi(T) attachaAsRC(BinNodePosi(T) x, BinTree <T>* &S); //作为右子树插入
    int remove(BinNodePosi(T) x); //删除以x节点为根的子树，返回子树原先的规模 
 
    BinTree<T>* secede(BinNodePosi(T) x); //删除子树，并将其转化为独立子树 
 
    /*--遍历接口--*/
 
    template <typename VST> void travLevel(VST&visit) //层次遍历
    { if (_root) _root->travLevel(visit); }
 
    template <typename VST> void travPre(VST&visit) //先序遍历
    { if (_root) _root->travPre(visit); }
    
    template <typename VST> void travIn(VST&visit) //中序遍历
    { if (_root) _root->travIn(visit); }
    
    template <typename VST> void travPost(VST&visit) //后序遍历
    { if (_root) _root->travPost(visit); }
    
    /*--判断器、比较器--*/
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
{ _size ++; return _root = new BinNode<T>(e); }                         //将ｅ当作根节点插入空的二叉树
 
template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e)
{ _size ++; x->insertAsLC(e); updateHeightAbove(x); return x->lchild; }   //ｅ插入为ｘ的左孩子
 
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{ _size ++; x->insertAsRC(e); updateHeightAbove(x); return x->rchild; }   //ｅ插入为ｘ的右孩子

template <typename T>//作为左子树 
BinNodePosi(T) BinTree<T>::attachaAsLC(BinNodePosi(T) x, BinTree <T>* &S)
{//子树接入 
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

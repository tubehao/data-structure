//
// Created by 12268 on 2023/10/19.
//

//
// Created by 12268 on 2023/10/19.
//




#include <iostream>
using namespace std;


class illegalSize{};
class outOfBound{};

template <class elemType>
class linkQueue;

template <class elemType>
class NodeQueue
{
    friend class linkQueue<elemType>;
private:
    elemType data;
    NodeQueue *next;
public:
    NodeQueue(){next = nullptr; }
    NodeQueue(const elemType &x, NodeQueue *p = nullptr)
    { data = x; next = p;}
};


template <class elemType>
class linkQueue
{ private:
    NodeQueue<elemType> *Front, *Rear;
public:
    linkQueue(){Front = Rear = nullptr; }; //初始化链式队列，使得其为空队
    bool isEmpty() {return !Front; }; //判断队空否，空返回true，否则为false
    bool isFull(){return false; };  //判断队满否，满返回true，否则为false
    elemType front(); //读取队首元素的值，队首不变
    void enQueue(const elemType &x); //将x进队，成为新的队尾
    void deQueue(); //将队首元素出队
    ~linkQueue(); //释放队列元素所占据的动态数组
};


template <class elemType>
elemType linkQueue<elemType>::front() //读取队首元素的值，队首不变
{
//    if (isEmpty()) throw outOfBound();
    return Front->data;
}


template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)  //将x进队，成为新的队尾
{
    if (!Rear)
        Front = Rear = new NodeQueue<elemType>(x);
    else
    { Rear->next = new NodeQueue<elemType>(x);
        Rear = Rear->next;
    }
}


template <class elemType>
void linkQueue<elemType>::deQueue() //将队首元素出队
{   //if (isEmpty()) throw outOfBound();

    NodeQueue<elemType> *tmp = Front;
    Front = Front->next;
    delete tmp;

    if (!Front) Rear = nullptr;
}


template <class elemType>
linkQueue<elemType>::~linkQueue() //释放链式栈所占空间
{   NodeQueue<elemType> *p;
    p= Front;

    while (p)
    {
        Front=Front->next;
        delete p;
        p=Front;
    }
}




template <class elemType>
class linkStack;
template <class elemType>
class NodeStack
{
    friend class linkStack<elemType>;
private:
    elemType data;
    NodeStack *next;
public:
    NodeStack(){next = nullptr;}
    NodeStack(const elemType &x, NodeStack *p=nullptr)
    { data = x; next = p; }
};


template <class elemType>
class linkStack
{
private:
    NodeStack<elemType> *Top;
public:
    linkStack(){ Top = nullptr; }; //初始化栈，使其为空栈
    bool isEmpty(){ return (Top==nullptr); }; //栈为空返回true,否则返回false。
    bool isFull(){ return false; }; //栈满true，否则false。结点空间不连续，故总能满足
    elemType top();
    void push(const elemType &e);
    void pop();
    ~linkStack();
};


template <class elemType>
elemType linkStack<elemType>::top()
{
//    if (!Top) throw outOfBound();//栈空
    return Top->data;
}


template <class elemType>
void linkStack<elemType>::push(const elemType &e)
{  Top = new NodeStack<elemType>(e, Top);  }


template <class elemType>
void linkStack<elemType>::pop()
{
    NodeStack<elemType> *tmp;
//    if (!Top) throw outOfBound();//栈空

    tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; //实际将栈顶结点弹出栈

    delete tmp;//释放原栈顶结点空间
}


template <class elemType>
linkStack<elemType>::~linkStack()
{
    NodeStack<elemType> *tmp;
    while (Top)
    {
        tmp = Top;
        Top=Top->next;
        delete tmp;
    }
}








template <class elemType>
class BTree;

template <class elemType>
class node{
    friend class BTree<elemType>;
private:
    elemType data;
public:
    node *left, *right;
    node(){
        left=nullptr;
        right=nullptr;
    };
    explicit node(const elemType &e, node *L=nullptr, node *R=nullptr)
    {  data = e;  left=L; right=R; };
};

template <class elemType>
class BTree
{
private:


    int Size (node<elemType> *t); //求以t为根的二叉树的结点个数。
    int Height (node<elemType> *t); //求以t为根的二叉树的高度。
    void DelTree(node<elemType> *t);//删除以t为根的二叉树
    void PreOrder(node<elemType> *t);
    // 按前序遍历输出以t为根的二叉树的结点的数据值
    void InOrder(node<elemType> *t);
    // 按中序遍历输出以t为根的二叉树的结点的数据值
    void PostOrder(node<elemType> *t);
    // 按后序遍历输出以t为根的二叉树的结点的数据值
    void LevelOrder(node<elemType> *t);
public:
    node<elemType> *root;
    BTree(){root=nullptr;}
    BTree(node<elemType> *r){root = r;}
    void createTree(const elemType &stopFlag);//创建一棵二叉树
    bool isEmpty () { return (root == nullptr);}// 二叉树为空返回true，否则返回false
    node<elemType> * GetRoot(){ return  root; }
    int Size (){return Size(root);}; //求二叉树的结点个数。
    int Height (){return Height(root);}; //求二叉树的高度。
    void DelTree(){return DelTree(root);};//删除二叉树
    void PreOrder(){return PreOrder(root);};// 按前序遍历输出二叉树的结点的数据值
    void InOrder(){return InOrder(root);};// 按中序遍历输出二叉树的结点的数据值
    void PostOrder(){return PostOrder(root);};// 按后序遍历输出二叉树的结点的数据值
    void LevelOrder(){return LevelOrder(root);};// 按中序遍历输出二叉树的结点的数据值
    node<elemType> *SeqToTree(elemType pre[], int pl, int pr,
                              elemType mid[], int ml,int mr);
};

template<class elemType>
node<elemType> *BTree<elemType>::SeqToTree(elemType pre[], int pl, int pr,
                                           elemType mid[], int ml,int mr){
    auto *tree = new node<elemType>;
    if(pl>pr) return nullptr;
    auto *r = new node<elemType>(pre[pl]);
    int lpl, lpr, lml, lmr; //左子树中前序的左右边界、中序的左右边界
    int rpl, rpr, rml, rmr; //右子树中前序的左右边界、中序的左右边界
    int ro;
    if(!root) root = r;

    ro = mr;
    while (mid[ro]!=r->data){
        ro--;
//        cout<<ro<<' '<<mid[ro]<<' '<<r->data;
    }
//    cout<<ro<<endl;
    auto *left = new node<elemType>;
    auto *right = new node<elemType>;
    lpr = ro-1-ml+(pl+1);
    lpl = pl+1;
    lml = ml;
    lmr = ro-1;
    left = SeqToTree(pre, lpl, lpr, mid, lml, lmr);

    rpr = pr;
    rpl = lpr+1;
    lml = ro+1;
    lmr = mr;
    right = SeqToTree(pre, rpl, rpr, mid, lml, lmr);

    r->left = left;
    r->right = right;
    return r;
}


template<class elemType>
int BTree<elemType>::Size(node<elemType> *t) {
    return 0;
}

template<class elemType>
int BTree<elemType>::Height(node<elemType> *t) {

    return 0;
}

template<class elemType>
void BTree<elemType>::DelTree(node<elemType> *t) {

}

template<class elemType>
void BTree<elemType>::PreOrder(node<elemType> *t) {
    if (root == nullptr) return;
    linkStack<node<elemType> *> s;
    node<elemType> *p = root;
    s.push(p);
    while (!s.isEmpty()){
        p = s.top();
        s.pop();
        cout<<p->data<<endl;
        node<elemType> *n;
        n = p->right;
        if(n != nullptr) s.push(n);
        if(p->left != nullptr) s.push(p->left);
    }
}

template<class elemType>
void BTree<elemType>::InOrder(node<elemType> *t) {
    if(!root) return;
    linkStack<node<elemType> *> s;
    node<elemType> *p = root;
    s.push(p);
    while (p->left) {
        p = p->left;
        s.push(p);
    }
    while(!s.isEmpty()){
        p = s.top();
        s.pop();
        cout<<p->data<<' ';
        if (p->right != nullptr){
            p = p->right;
            s.push(p);
            while(p->left){
                p = p->left;
                s.push(p);
            }
        }
    }
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::PostOrder(node<elemType> *t) {
    if(!root) return;
    linkStack<node<elemType> *>s1;
    linkStack<int> s2;
    node<elemType> *p = root;
    s1.push(p);
    s2.push(0);
    while(!s1.isEmpty()){
        p = s1.top();
        if(s2.top()==2){
            s2.pop();
            p = s1.top();
            s1.pop();
            cout<<p->data<<' ';
        }
        else if(s2.top() == 1){
            s2.pop();
            s2.push(2);
            if(p->right){
                p = p->right;
                s1.push(p);
                s2.push(0);
            }
        }
        else if(s2.top() == 0){
            s2.pop();
            s2.push(1);
            if(p->left){
                p = p->left;
                s1.push(p);
                s2.push(0);
            }
        }
    }
    cout<<endl;
}

template<class elemType>
void BTree<elemType>::LevelOrder(node<elemType> *t) {
    node<elemType> *p = root;
    linkQueue<node<elemType> *> q;
    q.enQueue(root);
    while(!q.isEmpty()){
        p = q.front();
        q.deQueue();
        cout<<p->data<<endl;
        if(p->left != nullptr) q.enQueue(p->left);
        if(p->right != nullptr) q.enQueue(p->right);
    }
}

template<class elemType>
void BTree<elemType>::createTree(const elemType &stopFlag) {
    int r;
    cin>>r;
    root = new node<elemType>(r);
    node<elemType> *p = root;
    linkQueue<node<elemType> *> q;
    q.enQueue(root);
    while(!q.isEmpty()){
        p = q.front();
        q.deQueue();
        elemType x, y;
        cin>>x>>y;
        if(x != stopFlag){
            p->left = new node<elemType>(x, nullptr, nullptr);
            q.enQueue(p->left);
        }
        else return;
        if(y != stopFlag){
            p->right = new node<elemType>(y);
            q.enQueue(p->right);
        }
        else return;
    }
}




#include "string"

node<int> *BseqToTree(){

    string s;
    node<int> *r;
    cin>>s;
//    while (x!=' '){
//        cin>>x;
//        s+=x;
//    }
//    if(s=="")return nullptr;

    if(s == "."){
        return nullptr;
    }
    else{
        int in = stoi(s);
//        cout<<in<<endl;
        r = new node<int>(in);
    }
    node<int> *left;
    node<int> *right;
    left = BseqToTree();
    right = BseqToTree();
    r->left = left;
    r->right = right;
    return r;
}

int main(){
    BTree<int> tree;
//    char pre[] = {'b','l','s','c','f','d','g','i','h'};
//    char mid[] = {'l','s','b','f','c','i','g','h','d'};
//    tree.SeqToTree(pre,0,8,mid,0,8);
//    tree.createTree(0);
    node<int> *p = BseqToTree();
    tree = BTree<int>(p);
//    cout<<111;
//    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();
    //    cout<<1<<endl;
    return 0;
}
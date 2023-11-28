#include "vector"
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
public:
    elemType data;
    node *left, *right;
    int l, r;
    bool isRoot = true;
    int nodeDepth;
    node(){
        left=nullptr;
        right=nullptr;
        l = 0;
        r = 0;
        nodeDepth = 0;
    };
    explicit node(const elemType &e, node *L=nullptr, node *R=nullptr)
    {  data = e;  left=L; right=R; };
};

template <class elemType>
class BTree
{
private:
    void InOrder(node<elemType> *t);
    // 按中序遍历输出以t为根的二叉树的结点的数据值
public:
    node<elemType> *root;
    BTree(){root=nullptr;}
    void InOrder(){return InOrder(root);};// 按中序遍历输出二叉树的结点的数据值
};

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

void cleartree(node<int> *p){
    if(p == nullptr) return;
    if(p->left != nullptr){
        cleartree(p->left) ;
        p->left = nullptr;
    }
    if(p->right != nullptr){
        cleartree(p->right);
        p->right = nullptr;
    }
    delete p;
}

void depth(node<int> *p, int nodeDepth){
    if(p == nullptr) return ;
    p->nodeDepth = nodeDepth;
    int lDepth,rDepth;
    depth(p->left, nodeDepth+1);
    depth(p->right, nodeDepth+1);
//    cout<<p->data<<' '<<p->nodeDepth<<endl;
}


int main(){
    BTree<int> tree;
    int root;
    int n = 10;
    cin>>n;
    vector<node<int> *> nodelist(n+1);
    for(int i = 1;i<=n;i++){
        node<int> *p;
        if(nodelist[i] == nullptr){
            p = new node<int>(i);
            nodelist[i] = p;
        }
        else p = nodelist[i];
        int l,r;
        cin>>l>>r;
        if(l == -1) {
            p->left = nullptr;
        }
        else{
            if(!nodelist[l]) {
                node<int> *left = new node<int>(l);
                nodelist[l] = left;
            }
            nodelist[l]->isRoot = false;
            p->left = nodelist[l];
            p->l = l;
        }
        if(r == -1) p->right = nullptr;
        else{
            if(!nodelist[r]) {
                node<int> *right = new node<int>(r);
                nodelist[r] = right;
            }
            nodelist[r]->isRoot = false;
            p->right = nodelist[r];
            p->r = r;
        }
    }
//    cout<<1111<<endl;
    for(int i = 1;i <= n;i++){//find root
        if (nodelist[i]->isRoot) {
            root = i;
            break;
        }
    }
    depth(nodelist[root],1);//set depth
    tree.root = nodelist[root];
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int k;
        cin>>k;
        int which;
        linkQueue<int> que;
        for(int j = 1; j <= n; j++) {
//            cout<<j;
            if(nodelist[j]->nodeDepth % k == 0){
                que.enQueue(j);
            }
        }
        node<int> *temp;
        while (!que.isEmpty()){
            which = que.front();
            que.deQueue();
            temp = nodelist[which]->left;
            nodelist[which]->left = nodelist[which]->right;
            nodelist[which]->right = temp;
        }
        tree.InOrder();
    }
    for (int i = 1;i <= n;i++){
        if(nodelist[i] != nullptr) {
//            cout<<nodelist[i]->data<<endl;
            delete nodelist[i];
            nodelist[i] = nullptr;
        }
    }

    return 0;

}
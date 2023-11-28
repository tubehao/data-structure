//
// Created by 12268 on 2023/10/19.
//

#ifndef TWOTREE_TWOTREE_H
#define TWOTREE_TWOTREE_H
#include "linkQueue.h"
#include "linkStack.h"
#include <iostream>
using namespace std;

template <class elemType>
class BTree;

template <class elemType>
class node{
    friend class BTree<elemType>;
private:
    elemType data;
public:
    node *left, *right;
    int level;
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
    void LevelOrder(node<elemType> *t,int sum);
public:
    node<elemType> *root;
    int level;
    BTree(){root=nullptr;}
    void createTree(const elemType &stopFlag);//创建一棵二叉树
    bool isEmpty () { return (root == nullptr);}// 二叉树为空返回true，否则返回false
    node<elemType> * GetRoot(){ return  root; }
    int Size (){return Size(root);}; //求二叉树的结点个数。
    int Height (){return Height(root);}; //求二叉树的高度。
    void DelTree(){return DelTree(root);};//删除二叉树
    void PreOrder(){return PreOrder(root);};// 按前序遍历输出二叉树的结点的数据值
    void InOrder(){return InOrder(root);};// 按中序遍历输出二叉树的结点的数据值
    void PostOrder(){return PostOrder(root);};// 按后序遍历输出二叉树的结点的数据值
    void LevelOrder(int sum){return LevelOrder(root,sum);};// 按中序遍历输出二叉树的结点的数据值
    node<elemType> *SeqToTree(elemType pre[], int pl, int pr,
                             elemType mid[], int ml,int mr,int nodelevel);
};

template<class elemType>
node<elemType> *BTree<elemType>::SeqToTree(elemType pre[], int pl, int pr,
                         elemType mid[], int ml,int mr,int nodelevel){
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
    left = SeqToTree(pre, lpl, lpr, mid, lml, lmr,nodelevel+1);

    rpr = pr;
    rpl = lpr+1;
    lml = ro+1;
    lmr = mr;
    right = SeqToTree(pre, rpl, rpr, mid, lml, lmr,nodelevel+1);

    r->left = left;
    r->right = right;
    r->level = nodelevel;
//    cout<<nodelevel<<r->data<<endl;
    return r;
}


template<class elemType>
int BTree<elemType>::Size(node<elemType> *t) {
    return 0;
}

template<class elemType>
int BTree<elemType>::Height(node<elemType> *t) {

    if(t == nullptr) return 0;
    else{
        int leftHeight = Height(t->left);
        int rightHeight = Height(t->right);
        return (max(leftHeight,rightHeight)+1);
    }
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
        cout<<p->data<<endl;
        if (p->right != nullptr){
            p = p->right;
            s.push(p);
            while(p->left){
                p = p->left;
                s.push(p);
            }
        }
    }
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
        if(s2.top()==2){
            s2.pop();
            p = s1.top();
            s1.pop();
            cout<<p->data<<endl;

        }
        else if(s2.top() == 1){
            s2.pop();
            s2.push(2);
            p = p->right;
            s1.push(p);
            s2.push(0);
        }
        else if(s2.top() == 0){
            s2.pop();
            s2.push(1);
            p = p->left;
            s1.push(p);
            s2.push(0);
        }
    }
}



template<class elemType>
void BTree<elemType>::LevelOrder(node<elemType> *t, int sum) {
    node<elemType> *p = t;
    linkQueue<node<elemType> *> q;
    q.enQueue(t);
    while(!q.isEmpty()){
        if(sum == 0) return;
        p = q.front();
        q.deQueue();
        if(p == nullptr)
        {
            cout<<"NULL"<<' ';
            continue;
        }
        else {
            cout<<p->data<<' ';
            sum--;
        }
//        if(p->left == nullptr&&p->right == nullptr) continue;
        if(p->left == nullptr&&p->level<level) q.enQueue(nullptr);
        else q.enQueue(p->left);
        if(p->right == nullptr&&p->level<level) q.enQueue(nullptr);
        else q.enQueue(p->right);
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


#endif //TWOTREE_TWOTREE_H

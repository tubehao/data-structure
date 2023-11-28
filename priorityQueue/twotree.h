
//
// Created by 12268 on 2023/10/19.
//


#include "linkQueue.h"
#include "linkStack.h"
#include <iostream>
/*
using namespace std;

template<class elemType>
class BTree;

template<class elemType>
class node {
    friend class BTree<elemType>;

private:
    elemType data;
public:
    node *left, *right;

    node() {
        left = nullptr;
        right = nullptr;
    };

    explicit node(const elemType &e, node *L = nullptr, node *R = nullptr) {
        data = e;
        left = L;
        right = R;
    };
};

template<class elemType>
class BTree {
private:
    node<elemType> *root;

    int Size(node<elemType> *t); //求以t为根的二叉树的结点个数。
    int Height(node<elemType> *t); //求以t为根的二叉树的高度。
    void DelTree(node<elemType> *t);//删除以t为根的二叉树
    void PreOrder(node<elemType> *t);

    // 按前序遍历输出以t为根的二叉树的结点的数据值
    void InOrder(node<elemType> *t);

    // 按中序遍历输出以t为根的二叉树的结点的数据值
    void PostOrder(node<elemType> *t);

    // 按后序遍历输出以t为根的二叉树的结点的数据值
    void LevelOrder(node<elemType> *t);

public:
    BTree() { root = nullptr; }

    void createTree(const elemType &stopFlag);//创建一棵二叉树
    bool isEmpty() { return (root == nullptr); }// 二叉树为空返回true，否则返回false
    node<elemType> *GetRoot() { return root; }

    int Size() { return Size(root); }; //求二叉树的结点个数。
    int Height() { return Height(root); }; //求二叉树的高度。
    void DelTree() { return DelTree(root); };//删除二叉树
    void PreOrder() { return PreOrder(root); };// 按前序遍历输出二叉树的结点的数据值
    void InOrder() { return InOrder(root); };// 按中序遍历输出二叉树的结点的数据值
    void PostOrder() { return PostOrder(root); };// 按后序遍历输出二叉树的结点的数据值
    void LevelOrder() { return LevelOrder(root); };// 按中序遍历输出二叉树的结点的数据值
};

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
    while (!s.isEmpty()) {
        p = s.top();
        s.pop();
        cout << p->data << endl;
        node<elemType> *n;
        n = p->right;
        if (n != nullptr) s.push(n);
        if (p->left != nullptr) s.push(p->left);
    }
}

template<class elemType>
void BTree<elemType>::InOrder(node<elemType> *t) {
    if (!root) return;
    linkStack<node<elemType> *> s;
    node<elemType> *p = root;
    s.push(p);
    while (p->left) {
        p = p->left;
        s.push(p);
    }
    while (!s.isEmpty()) {
        p = s.top();
        s.pop();
        cout << p->data << endl;
        if (p->right != nullptr) {
            p = p->right;
            s.push(p);
            while (p->left) {
                p = p->left;
                s.push(p);
            }
        }
    }
}

template<class elemType>
void BTree<elemType>::PostOrder(node<elemType> *t) {
    if (!root) return;
    linkStack<node<elemType> *> s1;
    linkStack<int> s2;
    node<elemType> *p = root;
    s1.push(p);
    s2.push(0);
    while (!s1.isEmpty()) {
        if (s2.top() == 2) {
            s2.pop();
            p = s1.top();
            s1.pop();
            cout << p->data << endl;

        } else if (s2.top() == 1) {
            s2.pop();
            s2.push(2);
            p = p->right;
            s1.push(p);
            s2.push(0);
        } else if (s2.top() == 0) {
            s2.pop();
            s2.push(1);
            p = p->left;
            s1.push(p);
            s2.push(0);
        }
    }
}

template<class elemType>
void BTree<elemType>::LevelOrder(node<elemType> *t) {
    node<elemType> *p = root;
    linkQueue<node<elemType> *> q;
    q.enQueue(root);
    while (!q.isEmpty()) {
        p = q.front();
        q.deQueue();
        cout << p->data << endl;
        if (p->left != nullptr) q.enQueue(p->left);
        if (p->right != nullptr) q.enQueue(p->right);
    }
}

template<class elemType>
void BTree<elemType>::createTree(const elemType &stopFlag) {
    int r;
    cin >> r;
    root = new node<elemType>(r);
    node<elemType> *p = root;
    linkQueue<node<elemType> *> q;
    q.enQueue(root);
    while (!q.isEmpty()) {
        p = q.front();
        q.deQueue();
        elemType x, y;
        cin >> x >> y;
        if (x != stopFlag) {
            p->left = new node<elemType>(x, nullptr, nullptr);
            q.enQueue(p->left);
        } else return;
        if (y != stopFlag) {
            p->right = new node<elemType>(y);
            q.enQueue(p->right);
        } else return;
    }
}


#endif //TWOTREE_TWOTREE_H
*/

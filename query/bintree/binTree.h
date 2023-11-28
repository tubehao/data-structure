//
// Created by 12268 on 2023/11/14.
//

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "linkQueue.h"
#include "iostream"
using namespace std;
template<class elemType>
struct node{
    elemType data;
    node<elemType> *left,*right,*parent;
    int depth;
    int size;
    node(){left = nullptr;right = nullptr;};
    node(const elemType &x, node<elemType> *l = nullptr, node<elemType> *r = nullptr){
        data = x;
        left = l;
        right = r;
    };
};

template<class elemType>
class binTree {
private:
    node<elemType> *root;
    int height;
    bool search(const elemType &x, node<elemType> *t) const{
        if(!t) return false;
        if(t->data == x) return true;
        else if (t->data>x) return search(x, t->left);
        else return search(x, t->right);
    }
    void insert(const elemType &x, node<elemType> *&t){//pay attention to the & of the t, which can change the father's child
        if(t == nullptr){
            t = new node<elemType>(x);
//            cout<<t->data<<endl;
            return;
        }
        if(t->data == x) return;
        if(t->data>x) insert(x, t->left);
        else insert(x, t->right);
    }
    void remove(const elemType &x, node<elemType> *&t){
        if(t == nullptr) return;
        if(t->data < x) remove(x, t->right);
        else if (t->data > x) remove(x, t->left);
        else {
            if(!(t->left&&t->right)){
                node<elemType> *nowPointer = t;
                t = (t->left)? t->left : t->right;
                cout<<nowPointer->data<<endl;
                delete nowPointer;
                return;
            }
            else{
                node<elemType> *p = t->right, *pParent = t->right;
                while (p->left) {
                    pParent = p;
                    p = p->left;
                }
                t->data = p->data;
                p->data = x;
                if(pParent == t->right) remove(x, t->right);
                else remove(x, pParent);
            }
        }
    }
    int setSize(node<elemType> *p){
        if(p == nullptr) return 0;
        p->size = setSize(p->left)+setSize(p->right)+1;
        return p->size;
    }

public:
    binTree(){root = nullptr;}
    bool search(const elemType &x) const{search(x, root);}
    void insert(const elemType &x) { insert(x, root);}
    void remove(const elemType &x) { remove(x, root);}
    void levelTravese() const{
        node<elemType> *p = root;
//        cout<<root->data<< endl;
        linkQueue<node<elemType>*> que;
        que.enQueue(root);
        while(!que.isEmpty()){
            p = que.front();
            que.deQueue();
            cout<<p->data<<' '<<p->size<<endl;
            if(p->left) que.enQueue(p->left);
            if(p->right) que.enQueue(p->right);
        }
        cout<<endl;
    }//层次遍历,用于验证插入、删除操作
    void setSize(){setSize(root);}

    int findLow(int i){
        if(root->size<i) return -1;
        if(i == 1) {
            node<elemType> *p;
            while(p->left) p = p->left;
            return p->data;
        }
        else{
            node<elemType> *now = root;
            while(now){
                if(now->left->size<i) {
                    if(i-now->left->size == 1) return now->data;
                    else{
                        i = i-now->left->size-1;
                        now = now->right;
                    }
                }
                else{
                    now = now->left;
                }
                cout<<now->data<<endl;
            }
        }
    };
};



#endif //BINTREE_BINTREE_H

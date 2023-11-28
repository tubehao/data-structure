//
// Created by 12268 on 2023/10/19.
//

#include "twotree.h"
#include <iostream>
using namespace std;

template<class elemType>
void cinTree(){
    cout<<"cin root"<<endl;
    elemType x;
    cin>>x;
    node<elemType> *root;

}

int main(){
    BTree<int> tree;
    tree.createTree(0);
//    cout<<111;
    tree.PreOrder();
//    cout<<1<<endl;
    return 0;
}
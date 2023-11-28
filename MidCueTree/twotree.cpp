//
// Created by 12268 on 2023/10/19.
//

#include "twotree.h"
#include <iostream>
using namespace std;

int main(){
    BTree<int> tree;
    tree.createTree(0);
//    cout<<111;
    tree.PreOrder();
//    cout<<1<<endl;
    return 0;
}
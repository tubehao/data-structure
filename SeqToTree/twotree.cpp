//
// Created by 12268 on 2023/10/19.
//

#include "twotree.h"
#include <iostream>
#include <cstring>

using namespace std;
#include "string"


int main(){
    BTree<char> tree;
//    char pre[] = {'b','l','s','c','f','d','g','i','h'};
//    char mid[] = {'l','s','b','f','c','i','g','h','d'};
//char pre[] = {'A','B','C','D'};
//char mid[] = {'B','A','D','C'};
    string spre, smid;
    cin>>spre;
    cin>>smid;
//    char *pre = new char[spre.length()+1];
//    strcpy(pre, pre);
    char pre[27],mid[27];
    for(int i = 0;i<spre.size();i++){
        pre[i]=spre[i];
    }
    for(int i = 0;i<smid.size();i++){
        pre[i]=smid[i];
    }
//    cout<<1;

    tree.SeqToTree(pre,0,3,mid,0,3,1);
//    tree.createTree(0);
//    cout<<111;
//    tree.PreOrder();
    tree.level = tree.Height();
//    cout<<tree.level;
//    tree.InOrder();
    tree.LevelOrder(4);

//    cout<<1<<endl;
    return 0;
}
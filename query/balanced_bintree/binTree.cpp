//
// Created by 12268 on 2023/11/14.
//

#include "binTree.h"
#include "iostream"
using namespace std;

int main(){
    binTree<int> t;
    t.insert(80);
    t.insert(40);
    t.insert(150);
    t.insert(30);
    t.insert(50);
    t.insert(100);
    t.insert(200);
    t.insert(35);
//    t.insert(20);
//    t.insert(105);
    cout<<t.search(200)<<endl;
    t.levelTravese();
    t.remove(40);
    t.levelTravese();
    return 0;
}
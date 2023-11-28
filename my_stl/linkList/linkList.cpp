//
// Created by 12268 on 2023/10/15.
//
#include <iostream>
#include "linkList.h"
using namespace std;

int main(){
    linkList<int> l;
    for(int i=0;i<10;i++){
        l.insert(i,i);
    }
    cout<<l.length()<<endl;
    return 0;
}
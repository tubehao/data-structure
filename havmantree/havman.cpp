//
// Created by 12268 on 2023/10/28.
//

#include "havman.h"
#include "iostream"
#include "linkStack.h"
using namespace std;

template<class elemType>
void hufCode(huffman<elemType> h){
    for(int i = 11;i>0;i--){
        HuffmanNode<elemType> no;
        no = *h.array[i];
        cout<<no.data;
        if(no.left!=0||no.right!=0) break;
        linkStack<int> s;
        int now = i;
        while (no.parent!=0){
            if(h.array[no.parent]->left == now){
                s.push(0);
            }
            else s.push(1);
//            cout<<'i'<<i<<' '<<"parent"<<no.parent<<' '<<h.array[no.parent]->left<<endl;
            now = no.parent;
            no = *h.array[no.parent];
        }
//        cout<<1<<endl;
        while (!s.isEmpty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }

}

int main(){
    huffman<char> h;
    char a[] = {'A','B','C','D','E','F'};
    double w[] = {3,8,10,12,50,4};
    h.buildtree(a,w,6);
    hufCode(h);
    return 0;
}
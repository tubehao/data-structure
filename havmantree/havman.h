//
// Created by 12268 on 2023/10/28.
//

#ifndef HAVMANTREE_HAVMAN_H
#define HAVMANTREE_HAVMAN_H
#include "iostream"
using namespace std;
template <class elemType>
struct HuffmanNode
{
    elemType data;
    double weight;
    int parent = 0;
    int left = 0, right = 0;
};

template <class elemType>
struct huffman {
    HuffmanNode<elemType> **array;

    huffman() {};
    int minIndex(HuffmanNode<elemType> *a[],int begin,int end){
        int min = 99999999,index;
        for(int i = begin;i<end;i++){
            HuffmanNode<elemType> *s = a[i];
//            cout<<"index"<<index<<endl;
            if(s->weight<min&&s->parent==0) {
                min = s->weight;
                index = i;
            }
        }
//        cout<<min<<endl;
        return index;
    };


    void buildtree(elemType a[],const double w[],int len){
        HuffmanNode<elemType> *huffman[len*2];
        array = new HuffmanNode<elemType> * [len*2];
//        HuffmanNode<elemType> *finalHuffman[len*2];
        for(int i = len-1;i>=0;i--){
            HuffmanNode<elemType> *n = new HuffmanNode<elemType>;

            n->data = a[i];
            n->weight = w[i];
            array[len+i] = n;
        }//create the back half of the tree
//        for(int i = len;i<len*2;i++){
//            cout<<huffman[i]->data<<huffman[i]->weight<<endl;
//        }
        for(int i = len-1; i>0; i--){
            HuffmanNode<elemType> *thisOne;
            if(i==1) {
                thisOne->parent = 0;
            }
            int min1,min2;
            thisOne = new HuffmanNode<elemType>;

            min1 = minIndex(array,i+1,2*len);
            thisOne->left = min1;
            array[min1]->parent = i;
//            cout<<"min1"<<' '<<min1<<' '<<endl;
            min2 = minIndex(array,i+1,2*len);
            thisOne->right = min2;
            array[min2]->parent = i;
//            cout<<"min2"<<' '<<min2<<endl;

            thisOne->weight = array[min1]->weight+array[min2]->weight;
            array[i] = thisOne;

        }
        for(int i = 1;i<2*len;i++){
            cout<<i<<' '<<array[i]->weight<<' '<<array[i]->parent<<' '<<array[i]->left<<' '<<array[i]->right<<endl;
        }
        cout<<"end"<<endl;
    }
};


/*    void buildtree(elemType a[],const double w[],int len){
        HuffmanNode<elemType> *huffman[len*2];
//        HuffmanNode<elemType> *finalHuffman[len*2];
        for(int i = len-1;i>=0;i--){
            HuffmanNode<elemType> *n = new HuffmanNode<elemType>;

            n->data = a[i];
            n->weight = w[i];
            huffman[len+i] = n;
        }//create the back half of the tree
//        for(int i = len;i<len*2;i++){
//            cout<<huffman[i]->data<<huffman[i]->weight<<endl;
//        }
        for(int i = len-1; i>0; i--){
            HuffmanNode<elemType> *thisOne;
            if(i==1) {
                thisOne->parent = 0;
            }
            int min1,min2;
            thisOne = new HuffmanNode<elemType>;

            min1 = minIndex(huffman,i+1,2*len);
            thisOne->left = min1;
            huffman[min1]->parent = i;
//            cout<<"min1"<<' '<<min1<<' '<<endl;
            min2 = minIndex(huffman,i+1,2*len);
            thisOne->left = min2;
            huffman[min2]->parent = i;
//            cout<<"min2"<<' '<<min2<<endl;

            thisOne->weight = huffman[min1]->weight+huffman[min2]->weight;
            huffman[i] = thisOne;

        }
        for(int i = 1;i<2*len;i++){
            cout<<i<<' '<<huffman[i]->weight<<endl;
        }
        cout<<"end"<<endl;
    }
};*/


#endif //HAVMANTREE_HAVMAN_H

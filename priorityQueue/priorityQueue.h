//
// Created by 12268 on 2023/10/26.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include "linkQueue.h"
#include "linkStack.h"
#include "iostream"
using namespace std;

//小顶堆
template<class elemType>
class priorityQueue{
private:
    int maxsize,len = 0;
    elemType *array;
public:

    priorityQueue (int size) //建立空优先级队列
    {
        array = new elemType[size]; //申请实际的队列存储空间
        maxsize = size;
        len = 0;
    };

    priorityQueue (elemType a[], int n) //建立优先级队列
    {
        maxsize = n+10;
        array = new elemType[n+10]; //申请实际的队列存储空间，多10，支持入队
        len = n;
        for (int i=0; i<n; i++){
           array[i] = a[i];
        }
        for (int i=(n-1)/2; i>=0; i--)    { adjust(i);}   //首次建立小顶堆
    };

/*    priorityQueue (elemType a[], int n) //建立优先级队列
    {
        array = new elemType[n+10]; //申请实际的队列存储空间，多10，支持入队
        maxsize = n+10;     len = n;
        for (int i=0; i<n; i++)    array[i] = a[i];
        for (int i=(n-1)/2; i>=0; i--)     adjust(i);   //首次建立小顶堆
    };*/


/*    void adjust(int hole)
//反复向下调整hole的位置
    {
        int minChild;      elemType x, temp;

        x = array[hole];
        while (true)
        {    minChild = 2*hole+1;  //hole的左子下标
            if (minChild>len-1) break;
            if (minChild+1<=len-1) //hole还有右子
                if (array[minChild+1]< array[minChild])
                    minChild++; //右子最大
            if (x<array[minChild]) break;
            array[hole] = array[minChild];
            hole = minChild;  //继续向下调整
        }

        array[hole] = x;
    }
//比较次数最多为：二叉树的高度*/


    void adjust(int i){
        while(true){
            int mi;
            if (2*i+1>=len) break;
            mi = array[2*i+1];
            if (2*i+2<len) {
                mi = min(array[2*i+1],array[2*i+2]);
            }
            if(array[i]<mi) break;
            else {
                if(array[2*i+1]==mi) {
                    array[2*i+1] = array[i];
                    array[i] = mi;
                    i = 2*i+1;
                }
                else if (array[2*i+2]==mi) {
                    array[2*i+2] = array[i];
                    array[i] = mi;
                    i = 2*i+2;
                }
            }

        }
    };

    bool isEmpty(){
        return (len == 0);
    };

    bool isFull(){
        return (len == maxsize);
    };

    elemType top(){
        return array[0];
    };

    elemType deQueue(){
        elemType x = array[0];
        array[0] = array[len-1];
        len--;
        adjust(0);
    };

    void enQueue(elemType x){
//        if(isFull()){
//            priorityQueue(array,maxsize+10);
//        }
        array[len] = x;
        len++;
        for(int i = (len-1)/2;i>=0;i--){
            adjust(i);
        }
    };

    void print(){
        for (int i = 0; i < len; ++i) {
            cout<<array[i]<<' ';
        }
        cout<<endl;
    }

};
















#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

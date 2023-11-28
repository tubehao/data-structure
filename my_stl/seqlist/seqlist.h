#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

#include <iostream>
#define INITSIZE 100
using namespace std;

class illegalSize{};
class outOfBound{};

template <class elemType>
class seqList
{    private:
        elemType *elem; // 顺序表存储数组，存放实际的数据元素。
        int len;        // 顺序表中的元素个数，亦称表的长度。
        int maxSize;    // 顺序表的的最大可能的长度。
        void doubleSpace(); //私有函数，做内部工具
    public:
        seqList(int size=INITSIZE); //初始化顺序表
        //表为空返回true,否则返回false。
        bool isEmpty()const { return ( len == 0 ); }
        //表为满返回true，否则返回false。
        bool isFull()const { return (len == maxSize); }
        int length()const {return len;}  //表的长度，即实际存储元素的个数。
        elemType get(int i )const;//返回第i个元素的值
        //返回值等于e的元素的序号，无则返回0.
        int find (const elemType &e )const;
        //在第i个位置上插入新的元素（值为e），
        //使原来的第i个元素成为第i+1个元素。
        void insert(int i, const elemType &e );
        // 若第i个元素存在，删除并将其值放入e指向的空间。
        void remove(int i, elemType &e );
        void clear() { len=0; }; //清除顺序表，使得其成为空表
        ~seqList() { delete []elem; }; //释放表占用的动态数组

};

template <class elemType> 
seqList<elemType>::seqList(int size)
//初始化顺序表
{
    elem = new elemType[size];//申请动态数组
    if (!elem) throw illegalSize(); //连续空间，判定申请是否成功
    maxSize = size-1; //0下标位置用于查找时做哨兵位。
    len = 0;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{   int i;
    elemType *tmp = new elemType[2*maxSize];
    if (!tmp) throw illegalSize();
    for (i=1; i<=len; i++) tmp[i] = elem[i];
    delete []elem;   elem = tmp;
    maxSize = 2*maxSize - 1;
}

template <class elemType> //注意各处const, const+&组合的用法
int seqList<elemType>::find (const elemType &e )const  
// 返回值等于e的元素的序号，无则返回0.
{
    int i;
    elem[0] = e;  //哨兵位先置为待查元素
    for (i=len; elem[i]!=e; i--);
    return i;
}

template <class elemType>
void seqList<elemType>::insert (int i, const elemType &e )
{  int k;
    if ((i<1)||(i>len+1)) return; //插入位置越界
    if (len==maxSize) doubleSpace(); //空间满了，无法插入元素

    for (k=len+1; k>i; k--)
        elem[k]=elem[k-1];
    elem[i]=e;
    len++;
}

template <class elemType> //注意五步口诀法
void seqList<elemType>::remove (int i, elemType &e )
{  int k;
    if ((i<1)||(i>len)) return;
    e=elem[i];

    for (k=i; k<len; k++)
        elem[k]=elem[k+1];
    len--;
} 

template <class elemType> 
elemType seqList<elemType>::get(int i)const// 返回第i个元素的值
{
    if ((i<1)||(i>len)) throw outOfBound();
    return elem[i];
}

#endif
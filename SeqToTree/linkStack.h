#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include "twotree.h"

template <class elemType>
class linkStack;
template <class elemType>
class NodeStack
{
    friend class linkStack<elemType>;
    private:
        elemType data;
        NodeStack *next;
    public:
        NodeStack(){next = nullptr;}
        NodeStack(const elemType &x, NodeStack *p=nullptr)
        { data = x; next = p; }
};


template <class elemType>
class linkStack
{
    private:
        NodeStack<elemType> *Top;
    public:
        linkStack(){ Top = nullptr; }; //初始化栈，使其为空栈
        bool isEmpty(){ return (Top==nullptr); }; //栈为空返回true,否则返回false。
        bool isFull(){ return false; }; //栈满true，否则false。结点空间不连续，故总能满足
        elemType top();
        void push(const elemType &e);
        void pop();
        ~linkStack();
};


template <class elemType>
elemType linkStack<elemType>::top()
{
    if (!Top) throw outOfBound();//栈空
    return Top->data;
}


template <class elemType>
void linkStack<elemType>::push(const elemType &e)
{  Top = new NodeStack<elemType>(e, Top);  }


template <class elemType>
void linkStack<elemType>::pop()
{
    NodeStack<elemType> *tmp;
//    if (!Top) throw outOfBound();//栈空

    tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; //实际将栈顶结点弹出栈

    delete tmp;//释放原栈顶结点空间
}


template <class elemType>
linkStack<elemType>::~linkStack()
{
    NodeStack<elemType> *tmp;
    while (Top)
    {
        tmp = Top;
        Top=Top->next;
        delete tmp;
    }
}

#endif
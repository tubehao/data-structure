#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

class illegalSize{};
class outOfBound{};

template<class elemType>
class seqStack
{
private:
    elemType *array;
    int Top;
    int maxSize;
    void doublespace();

public:
    seqStack(int initSize = 100);
    int isEmpty() const;
    int isFull() const;
    elemType top() const;
    void push(const elemType &e) const;
    void pop();
    ~seqStack(){delete []array};
} ;


template<class elemType>
seqStack<elemType>::seqStack(int initSize)
{
    array = new elemType[initSize];
    if (!array) return throw illegalSize();
    Top = -1;
    maxSize = initSize;
}


template<class elemType>
int seqStack<elemType>::isEmpty()
{
    return (Top == -1);
}


template<class elemType>
int seqStack<elemType>::isFull()
{
    return (Top == maxSize-1);
}


template<class elemType>
void seqStack::doublespace()
{
    elemType *tmp;

    tmp = new elemType[maxSize*2];
    if (!tmp) throw illegalSize();

    for (int=0;i<=Top;++i)
        tmp[i]=array[i];
    delete []array;
    array=tmp;
    maxSize=2*maxSize;
}


template<class elemType>
elemType seqStack::top()
{
    if (isEmpty()) throw outOfBound();
    return array[Top];
}

template<class elemType>
void seqStack::push(const elemType &e)
{
    if (isFull()) doublespace();
    array[++Top]=e;
}

template<class elemType>
void seqStack::pop()
{
    if (isEmpty()) throw outOfBound();
    Top--;
}





#endif // SEQSTACK_H_INCLUDED0

#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

class illegalSize{};
class outOfBound{};
template <class elemType>
class seqQueue
{
private:
    elemType *array;
    int maxSize;
    int Front, Rear;//rear is the last element plus one
    void doubleSpace(); //扩展队队列元素的存储空间为原来的2倍
public:
    seqQueue(int size=10); //初始化队列元素的存储空间
    bool isEmpty(); //判断队空否，空返回true，否则为false
    bool isFull();  //判断队满否，满返回true，否则为false
    elemType front(); //读取队首元素的值，队首不变
    void enQueue(const elemType &x); //将x进队，成为新的队尾
    elemType deQueue(); //将队首元素出队
    ~seqQueue(); //释放队列元素所占据的动态数组
};

template<class elemType>
seqQueue<elemType>::seqQueue(int size) {
    if (!array) throw illegalSize();
    maxSize = size;
    Front = Rear = 0;
}

template<class elemType>
void seqQueue<elemType>::doubleSpace() {
    elemType *temp = new elemType[maxSize*2];
    int i;
    for (i = Front; i < maxSize; ++i) {
        temp[i-Front] = array[i];
    }
    i++;
    for (int j = 0; j < Rear; ++j) {
        temp[i+j] = array[j];
    }
    array = temp;
    delete[]temp;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty() {
    return (Front == Rear);
}

template<class elemType>
elemType seqQueue<elemType>::deQueue() {
    elemType a = array[Front];
    Front++;
    return a;
}

template<class elemType>
elemType seqQueue<elemType>::front() {
    return array[Front];
}

template<class elemType>
bool seqQueue<elemType>::isFull() {
    return (Rear+1)%maxSize == Front;
}

template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &x) {
    Rear++;
    array[Rear] = x;
}

template<class elemType>
seqQueue<elemType>::~seqQueue() {
    delete []array;
}

#endif //QUEUE_QUEUE_H

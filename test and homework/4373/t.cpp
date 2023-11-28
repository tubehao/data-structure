#include <iostream>
using namespace std;


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
    int sum;
    seqQueue(int size=10); //初始化队列元素的存储空间
    bool isEmpty(); //判断队空否，空返回true，否则为false
    bool isFull();  //判断队满否，满返回true，否则为false
    elemType front(); //读取队首元素的值，队首不变
    int enQueue(const elemType &x); //将x进队，成为新的队尾
    int deQueue(); //将队首元素出队
    ~seqQueue(); //释放队列元素所占据的动态数组
};

template<class elemType>
seqQueue<elemType>::seqQueue(int size) {
    array = new elemType[size];
    if (!array) throw illegalSize();
    maxSize = size;
    Front = Rear = 0;
    sum = 0;
}

template<class elemType>
void seqQueue<elemType>::doubleSpace() {
    elemType *temp = new elemType[maxSize*2];
    if (Front<Rear){
        for (int i = Front; i < Rear; ++i) {
            temp[i-Front] = array[i];
        }
    }
    else{
        int i;
        for (i = Front; i < maxSize; ++i) {
            temp[i-Front] = array[i];
        }
        i++;
        for (int j = 0; j < Rear; ++j) {
            temp[i+j] = array[j];
        }
    }

    Front = 0;
    Rear = sum;
    delete[]array;
    array = temp;
}

template<class elemType>
bool seqQueue<elemType>::isFull() {
    return (Rear+1)%maxSize == Front;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty() {
    return (Front == Rear);
}

template<class elemType>
elemType seqQueue<elemType>::front() {
    return array[Front];
}

template<class elemType>
int seqQueue<elemType>::enQueue(const elemType &x) {
    if (isFull()) { doubleSpace();Rear++;}
    else if (Rear+1 == maxSize) Rear = 0;
    else Rear++;
    sum++;
    array[Rear] = x;
    return Rear;
}

template<class elemType>
int seqQueue<elemType>::deQueue() {
    if (this->isEmpty()) return Front;

    if (Front+1 == maxSize) Front = 0;
    else Front++;

    elemType a = array[Front];
    sum--;
    return Front;
}

template<class elemType>
seqQueue<elemType>::~seqQueue() {
    delete []array;
}



int main(){
    int s,n;
    cin>>s>>n;
    seqQueue<int> m(s);
    for (int i = 0; i < n; ++i) {
        int oper;
        cin>>oper;
        if(oper == 0) {
            int x;
            cin>>x;
            cout<<m.enQueue(x)<<' '<<m.sum<<endl;
        }
        else {
            cout<<m.deQueue()<<' '<<m.sum<<endl;
        }
//        cout<<"i="<<i<<endl;
    }
    return 0;
}
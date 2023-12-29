//
// Created by 12268 on 2023/11/30.
//

#include "iostream"
#include "cstring"
using namespace std;
template<class elemType>
class linkQueue;

template<class elemType>
class NodeQueue {
    friend class linkQueue<elemType>;

private:
    elemType data;
    NodeQueue *next;
public:
    NodeQueue() { next = nullptr; }
    NodeQueue(const elemType &x, NodeQueue *p = nullptr) {
        data = x;
        next = p;
    }
};


template<class elemType>
class linkQueue {
private:
    NodeQueue<elemType> *Front, *Rear;
public:
    linkQueue() { Front = Rear = nullptr; }; //初始化链式队列，使得其为空队
    bool isEmpty() { return !Front; }; //判断队空否，空返回true，否则为false
    bool isFull() { return false; };  //判断队满否，满返回true，否则为false
    elemType front() //读取队首元素的值，队首不变
    {
//        if (isEmpty()) throw outOfBound();
        return Front->data;
    }
    void enQueue(const elemType &x)  //将x进队，成为新的队尾
    {
        if (!Rear)
            Front = Rear = new NodeQueue<elemType>(x);
        else {
            Rear->next = new NodeQueue<elemType>(x);
            Rear = Rear->next;
        }
    }
    void *deQueue() //将队首元素出队
    {
//        if (isEmpty()) throw outOfBound();

        NodeQueue<elemType> *tmp = Front;
        Front = Front->next;
        delete tmp;

        if (!Front) Rear = nullptr;
    }
    ~linkQueue() //释放链式栈所占空间
    {
        NodeQueue<elemType> *p;
        p = Front;

        while (p) {
            Front = Front->next;
            delete p;
            p = Front;
        }
    }
};



template<class elemType>
class linkStack;

template<class elemType>
class NodeStack {
    friend class linkStack<elemType>;

private:
    elemType data;
    NodeStack *next;
public:
    NodeStack() { next = nullptr; }

    NodeStack(const elemType &x, NodeStack *p = nullptr) {
        data = x;
        next = p;
    }
};

template<class elemType>
class linkStack {
private:
    NodeStack<elemType> *Top;
public:
    linkStack() { Top = nullptr; }; //初始化栈，使其为空栈
    bool isEmpty() { return (Top == nullptr); }; //栈为空返回true,否则返回false。
    bool isFull() { return false; }; //栈满true，否则false。结点空间不连续，故总能满足
    elemType top() {
//        if (!Top) throw outOfBound();//栈空
        return Top->data;
    }

    void push(const elemType &e) { Top = new NodeStack<elemType>(e, Top); }

    void pop(){
        NodeStack<elemType> *tmp;
        tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
        Top = Top->next; //实际将栈顶结点弹出栈
        delete tmp;//释放原栈顶结点空间
    }

    ~linkStack() {
        NodeStack<elemType> *tmp;
        while (Top) {
            tmp = Top;
            Top = Top->next;
            delete tmp;
        }
    }
};


template<class elemType>
struct nodepq{
    int priority;
    elemType data;
    nodepq(elemType d, int p){
        data = d;
        priority = p;
    }
};


//小顶堆
template<class elemType>
class priorityQueue{
private:
    int maxsize,len = 0;
    nodepq<elemType> **array;
    nodepq<elemType>* getMin(nodepq<elemType> *p, nodepq<elemType> *q){
        if(p->priority < q->priority) return p;
        return q;
    }
public:

    priorityQueue (int size) //建立空优先级队列
    {
        array = new nodepq<elemType>*[size]; //申请实际的队列存储空间
        maxsize = size;
        len = 0;
    };

    priorityQueue(nodepq<elemType>* a[], int n) {
        maxsize = n + 10;
        array = new nodepq<elemType>*[maxsize];
        memcpy(array, a, sizeof(nodepq<elemType>*) * n); // 使用memcpy进行复制
        len = n;
        for (int i = (n - 1) / 2; i >= 0; i--) {
            adjust(i);
        }
    }

    // 调整方法，用于维持小顶堆的性质
    void adjust(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < len && array[left]->priority < array[smallest]->priority) {
            smallest = left;
        }

        if (right < len && array[right]->priority < array[smallest]->priority) {
            smallest = right;
        }

        if (smallest != i) {
            swap(array[i], array[smallest]);
            adjust(smallest);
        }
//        cout<<"ajust:"<<endl;
//        print();
    }

// 插入新元素，并进行必要的上浮调整
    void enQueue(elemType x, int p) {
        if (isFull()) {
            resize(maxsize + 10);
        }
        array[len] = new nodepq<elemType>(x, p);
        int current = len;
        len++;
//        adjust(0);
        while (current > 0 && array[current / 2]->priority > array[current]->priority) {
            swap(array[current/ 2], array[current]);
            current = current / 2;
        }
    }



    bool isEmpty(){
        return (len == 0);
    };

    bool isFull(){
        return (len == maxsize);
    };

    elemType top(){
        if(isEmpty()) return -1;
        return array[0]->data;
    };

    void deQueue(){
        if (isEmpty()) return;
        elemType x = array[0]->data;
        delete array[0];
        array[0] = array[len-1];
//        cout<<"dequeue"<<endl;
//        print();
        len--;
        adjust(0);
    };
    void resize(int newSize) {
        nodepq<elemType>** newArray = new nodepq<elemType>*[newSize];
        memcpy(newArray, array, sizeof(nodepq<elemType>*) * len);
        delete[] array;
        array = newArray;
        maxsize = newSize;
    }



    void print(){
        for (int i = 0; i < len; ++i) {
            cout<<array[i]->data<<' '<<array[i]->priority<<endl;
        }
        cout<<endl;
    }
    ~priorityQueue() {
        for (int i = 0; i < len; ++i) {
            delete array[i];
        }
        delete[] array;
    }

};

int main() {
    int n, m;
    cin>>n>>m;
    priorityQueue<int> **list;
    list = new priorityQueue<int>* [n];
    for(int i = 0;i<n;i++){
        int pr;
        priorityQueue<int>* pointer = new priorityQueue<int>(10);
        cin>>pr;
        pointer->enQueue(pr, pr);
        list[i] = pointer;
    }
    for (int i = 0; i<m; i++){
        int operation = 1;
        cin>>operation;
        int a,b;
        priorityQueue<int> *newQueue;
        priorityQueue<int> *c, *d;
        int min1,min2;

        switch (operation) {
            case 0:
                cin>>a>>b;
                newQueue = new priorityQueue<int>(10);
                c = list[a];
                d = list[b];

                while (true){
                    if (c->isEmpty()&&d->isEmpty()) break;
                    if (c->isEmpty()){
                        newQueue->enQueue(d->top(),d->top());
                        d->deQueue();
                        continue;
                    }
                    if (d->isEmpty()){
                        newQueue->enQueue(c->top(),c->top());
                        c->deQueue();
                        continue;
                    }
                    else{
                        newQueue->enQueue(c->top(), c->top());
                        newQueue->enQueue(d->top(), d->top());
                        c->deQueue();
                        d->deQueue();
                    }
                }
                list[a] = newQueue;
//                c->print();
                break;
            case 1:
                cin>>a;
                cout<<list[a]->top()<<endl;
                list[a]->deQueue();
                break;
            case 2:
                cin>>a>>b;
                list[a]->enQueue(b,b);
                break;
            default:
                break;
        }
    }


    return 0;
}

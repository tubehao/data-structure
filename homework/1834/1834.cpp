//
// Created by 12268 on 2023/11/30.
//

#include "iostream"
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
    NodeQueue<int> *deQueue() //将队首元素出队
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
        return array[0]->data;
    };

    elemType deQueue(){
        elemType x = array[0]->data;
        delete array[0];
        array[0] = array[len-1];
//        cout<<"dequeue"<<endl;
//        print();
        len--;
        adjust(0);
        return x;
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
    priorityQueue<int> priorityQ(10);

    // 示例 1
    priorityQ.enQueue(5, 2);
    priorityQ.enQueue(3, 1);
    priorityQ.enQueue(6, 5);
    priorityQ.enQueue(4, 3);
    priorityQ.enQueue(2, 0);
    cout << "11111111" << endl;
    priorityQ.print();

    // 示例 2
    cout << "222222222" << endl;
    priorityQ.deQueue();
    priorityQ.print();
    priorityQ.deQueue();
    priorityQ.print();
//
//    // 示例 3
//    cout << "示例 3 - 混合操作:" << endl;
    priorityQ.enQueue(7, 4);
    priorityQ.enQueue(1, 2);
    priorityQ.deQueue();
    priorityQ.enQueue(8, 1);
    priorityQ.print();
//
//    // 示例 4
//    cout << "示例 4 - 队列顶部元素: " << priorityQ.top() << endl;

    return 0;
}

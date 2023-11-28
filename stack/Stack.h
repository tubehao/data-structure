class illegalSize{};
class outOfBound{};

template<class elemType>
class seqStack {
private:
    elemType *array;
    int Top;
    int maxSize;
    void doubleSpace();
public:
    explicit seqStack(int initSize = 100);
    bool isEmpty(){return Top == -1;};
    bool isFull(){return Top == maxSize-1;};
    elemType top();
    void push(const elemType &e);
    elemType pop();
    ~seqStack(){delete []array;};
};


template<class elemType>
seqStack<elemType>::seqStack(int initSize){
    Top = -1;
    maxSize = initSize;
    array = new elemType[initSize];
    if (!array) throw illegalSize();
}

template<class elemType>
elemType seqStack<elemType>::top(){
    if (Top == -1) throw outOfBound();
    return array[Top];
}

template<class elemType>
void seqStack<elemType>::push(const elemType &e){
    if (isFull()) doubleSpace();
    Top++;
    array[Top] = e;
}

template<class elemType>
elemType seqStack<elemType>::pop(){
    if (Top == -1) throw outOfBound();
    elemType temp = array[Top];
    Top--;
    return temp;
}

template<class elemType>
void seqStack<elemType>::doubleSpace() {
    elemType *temp = new elemType[maxSize*2];
    for (int i = 0; i <= Top; ++i) {
        temp[i] = array[i];
    }
    delete []array;
    array = temp;
}
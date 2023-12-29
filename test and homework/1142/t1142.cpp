//
// Created by work on 2023/10/28.
//
#include <iostream>
#include <string>
#include <sstream>
template <typename ElementType>
class Queue
{
public:
    virtual ~Queue() {}
    virtual bool empty() const = 0;
    virtual void push(const ElementType& element) = 0;
    virtual ElementType pop() = 0;
    virtual ElementType front() const = 0;
    virtual void clear() = 0;
};

class OutofBound{};

template <typename ElementType>
class Less
{
public:
    bool operator()(const ElementType& left, const ElementType& right) const
    {
        return left < right;
    }
};

template <typename ElementType>
class Greater
{
public:
    bool operator()(const ElementType& left, const ElementType& right) const
    {
        return left > right;
    }
};

template <typename ElementType, typename CompareRule = Less<ElementType>>
class PriorityQueue : public Queue<ElementType>
{
private:
    ElementType* elementData;
    unsigned long long int currentLength, totalCapacity;
    CompareRule compare;
    void expand();
    void update(unsigned long long int hole);
    void construct();

public:
    PriorityQueue(unsigned long long int size = 100);
    PriorityQueue(const ElementType content[], unsigned long long int size);
    ~PriorityQueue();
    bool empty() const;
    void push(const ElementType& element);
    ElementType pop();
    ElementType front() const;
    ElementType top() const;
    void clear();
    void merge(const PriorityQueue& other){
        for(unsigned long long int i=1;i<=other.currentLength;i++){
            push(other.elementData[i]);
        }
    }
};

template <typename ElementType, typename CompareRule>
void PriorityQueue<ElementType, CompareRule>::expand()
{
    ElementType* tempData = elementData;
    totalCapacity <<= 1;
    elementData = new ElementType[totalCapacity + 1];
    for (unsigned long long int i = 0; i <= currentLength; i++)
        elementData[i] = tempData[i];
    delete[] tempData;
}

template <typename ElementType, typename CompareRule>
void PriorityQueue<ElementType, CompareRule>::update(unsigned long long int hole)
{
    ElementType temp = elementData[hole];
    for (unsigned long long int next = 0; (hole << 1) <= currentLength; hole = next)
    {
        next = hole << 1;
        if (next != currentLength && compare(elementData[next | 1], elementData[next]))
            next |= 1;
        if (!compare(elementData[next], temp))
            break;
        elementData[hole] = elementData[next];
    }
    elementData[hole] = temp;
}

template <typename ElementType, typename CompareRule>
void PriorityQueue<ElementType, CompareRule>::construct()
{
    for (unsigned long long int i = currentLength >> 1; i; i--)
        update(i);
}

template <typename ElementType, typename CompareRule>
PriorityQueue<ElementType, CompareRule>::PriorityQueue(unsigned long long int size) : currentLength(0), totalCapacity(size)
{
    elementData = new ElementType[size];
}

template <typename ElementType, typename CompareRule>
PriorityQueue<ElementType, CompareRule>::PriorityQueue(const ElementType content[], unsigned long long int size) : currentLength(size), totalCapacity(size + 10)
{
    elementData = new ElementType[totalCapacity];
    for (unsigned long long int i = 0; i < size; i++)
        elementData[i + 1] = content[i];
    construct();
}

template <typename ElementType, typename CompareRule>
PriorityQueue<ElementType, CompareRule>::~PriorityQueue()
{
    delete[] elementData;
}

template <typename ElementType, typename CompareRule>
bool PriorityQueue<ElementType, CompareRule>::empty() const
{
    return currentLength == 0;
}

template <typename ElementType, typename CompareRule>
void PriorityQueue<ElementType, CompareRule>::push(const ElementType& element)
{
    if (currentLength == totalCapacity - 1)
        expand();
    unsigned long long int hole = ++currentLength;
    for (; hole > 1 && compare(element, elementData[hole >> 1]); hole >>= 1)
        elementData[hole] = elementData[hole >> 1];
    elementData[hole] = element;
}

template <typename ElementType, typename CompareRule>
ElementType PriorityQueue<ElementType, CompareRule>::pop()
{
    if (!currentLength)
        throw OutofBound{};
    ElementType result = elementData[1];
    elementData[1] = elementData[currentLength--];
    update(1);
    return result;
}

template <typename ElementType, typename CompareRule>
ElementType PriorityQueue<ElementType, CompareRule>::front() const
{
    return elementData[1];
}

template <typename ElementType, typename CompareRule>
ElementType PriorityQueue<ElementType, CompareRule>::top() const
{
    return elementData[1];
}

template <typename ElementType, typename CompareRule>
void PriorityQueue<ElementType, CompareRule>::clear()
{
    currentLength = 0;
}
using namespace std;



int main(){
    unsigned long long int n, k;
//    set<int> s;
    cin>>k>>n;
    PriorityQueue<unsigned long long int> q(10000);
    unsigned long long int a[n+1];
    unsigned long long int aSize = 0;

    unsigned long long int suShu[k];
    for (int i = 0; i < k; ++i) {
        unsigned long long int shu;
        cin>>shu;
        q.push(shu);
        suShu[i] = shu;
    }


    unsigned long long int min;
    while (true){
        min = q.top();
        q.pop();
        if(a[aSize] != min) {
            aSize++;
            a[aSize] = min;
            if(aSize == n) break;
            for(unsigned long long int i = 0;i<k;i++){
                unsigned long long int temp = min*suShu[i];
                q.push(temp);
            }
        }
    }
    cout<<a[n]<<endl;
    return 0;
}
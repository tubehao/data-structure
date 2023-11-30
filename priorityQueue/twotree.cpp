#include "iostream"
#include "priorityQueue.h"
using namespace std;

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
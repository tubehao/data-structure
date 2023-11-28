//
// Created by 12268 on 2023/10/19.
//

//#include "twotree.h"
#include "priorityQueue.h"
#include <iostream>

using namespace std;

int main() {
    int p[8] = {5,8,10,15,35,88,31,20};
    priorityQueue<int> s(p,8);
    s.print();
    s.enQueue(19);
    s.print();
    s.enQueue(13);
    s.print();
    s.deQueue();
    s.print();
    return 0;
}
#include "sequence_query.h"
#include <iostream>

using namespace std;

int main() {
    // 测试数据
    int arr[] = {1, 2, 3, 4, 5};
    staticQuery<int> query(arr, 5);

    // 顺序查找
    cout << "Sequential Search for 3: ";
    cout << (query.seqQuery(3)) << endl;

    // 二分查找
    cout << "Binary Search for 4: ";
    cout << (query.Bsearch(4)) << endl;

    // 插值查找
    cout << "Interpolation Search for 2: ";
    cout << (query.insertSearch(2)) << endl;

    // 块查找
    int blockSize = 2;
    int index[] = {1, 3, 5}; // 块的索引数组
    cout << "Block Search for 5: ";
    cout << (query.BlockSearch(5, blockSize, index, 3)) << endl;

    return 0;
}
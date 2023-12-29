//
// Created by 12268 on 2023/12/13.
//
#include "iostream"
using namespace std;

class heap{
private:
    int *data;
    int size;
    int capacity;
public:
    heap(int n){
        data = new int[n];
        size = 0;
        capacity = n;
    }

    ~heap(){
        delete []data;
    }


    void enQueue(int n){
        if(size == capacity){
            cout << "full" << endl;
            return;
        }
        data[size] = n;
        int index = size;
        size++;
        if (index == 1){
            return;
        }
        while (index > 0){
//            cout<<index<<endl;
            if(data[index] < data[(index-1)/2]){
                swap(data[index], data[(index-1)/2]);
                index = (index-1)/2;
            }
            else break;
        }
    }

    void deQueue(){
        if(size == 0){
            cout << "empty" << endl;
            return;
        }
        data[0] = data[--size];
        int index = 0;
        while (index < size){
            if(index*2+1 >= size){
                break;
            }
            if(index*2+2 >= size){
                if(data[index] > data[index*2+1]){
                    swap(data[index], data[index*2+1]);
                    index = index*2+1;
                }
                break;
            }
            if(data[index] < data[index*2+1] && data[index] < data[index*2+2]){
                break;
            }
            else{
                if(data[index*2+1] < data[index*2+2]){
                    swap(data[index], data[index*2+1]);
                    index = index*2+1;
                }
                else{
                    swap(data[index], data[index*2+2]);
                    index = index*2+2;
                }
            }
        }
    }

    int top(){
        if(size == 0){
            cout << "empty" << endl;
            return -1;
        }
        return data[0];
    }
};


int main(){
    int n;
    cin >> n;
    heap h(n);
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        h.enQueue(num);
    }
    int a[n];
    for(int i = 0; i<n; i++){
        a[i] = h.top();
        h.deQueue();
    }
//
//    for(int i = n-1; i>=0; i--){
//        cout << a[i] << " ";
//    }
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    cout<<endl;

    return 0;
}

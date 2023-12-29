//
// Created by 12268 on 2023/12/14.
//
#include "iostream"
#include "string"
using namespace std;

class heap{
private:
    unsigned long long int *data;
    int size;
    int capacity;
public:
    heap(int n){
        data = new unsigned long long int[n];
        size = 0;
        capacity = n;
    }

    ~heap(){
        delete []data;
    }


    void enQueue(unsigned long long int n){
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



const int B = 7;

typedef long long ll;

//unsigned long long int get_hash(const string& s) {
//    unsigned long long int res = 0;
//    for (int i = 0; i < s.size(); ++i) {
//        res = ((ll)res * B + s[i]);
//    }
//    return res;
//}

unsigned long long int get_hash(const string& s) {
    unsigned long long int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = (res + s[i]*i);
    }
    return res;
}

int main(){
    int N;
    cin>>N;
    heap h(N);
    for (int i = 0; i < N; ++i) {
        string s;
        cin>>s;
        h.enQueue(get_hash(s));
    }

    int num = N;
    unsigned long long int b;

    for(int i = 0; i<N; i++){
        if(h.top() == b){
            h.deQueue();
            num--;
            continue;
        }
        b = h.top();
        h.deQueue();
    }
    cout<<num;
    return 0;





}
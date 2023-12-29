//
// Created by 12268 on 2023/12/13.
//
#include "iostream"
using namespace std;

struct node {
    int data;
    node* next;
};


int main() {
    int n;
    cin >> n;
    node *head = new node;
    node *p = head;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        p->next = new node;
        p = p->next;
        p->data = x;
        p->next = nullptr;
    }
    int m;
    int count = 0;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        node *q = head;
        p = head->next;
        while(p != nullptr) {
            count++;
            if(p->data == x) {
                q->next = p->next;
                p->next = head->next;
                head->next = p;
                break;
            }
            q = p;
            p = p->next;
        }
//        cout<<count<<endl;
    }
    cout<<count;
    return 0;
}









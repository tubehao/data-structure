#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        int data;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = new NODE;
        head->next = head;
    }
//    NODE* move(int i) {
//        //todo
//    }

    void insert(int i, int x) {
        NODE *p = head;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        NODE *q = new NODE;
        q->data = x;
        q->next = p->next;
        p->next = q;
        len++;
    }
    void remove(int i) {
        NODE *p = head;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        NODE *q = p->next;
        p->next = q->next;
        delete q;
        len--;
    }
    void remove_insert(int i) {
        NODE *p = head;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        NODE *q = p->next;
        p->next = q->next;//delete

        NODE *m = p;
        while(m->next!=head) {
            m = m->next;
        }
        m->next = q;
        q->next = head;//insert to tail

    }
    int get_length() {
        return len;
    }
    int query(int i) {
        NODE *p = head;
        if (head->next == head) return -1;
        for (int j = 0; j <= i; ++j) {
            p = p->next;
        }
        if(p == head) return -1;
        return p->data;
    }
    int get_max() {
        int max = -99;
        NODE *m = head;
        if (head->next == head) return -1;
        while(m->next!=head) {
            m = m->next;
            if(m->data>max) max = m->data;
        }
        return max;
    }
    void clear() {
        NODE *m = head->next, *q;
        if (head->next == head) {
            delete head;
            return;
        }
        while (m != head) {
            q = m->next;
            delete m;
            m = q;
        }
        delete head;  // 释放 head 指向的内存
        head = nullptr;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                cout<<LIST::get_length()<<endl;
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                cout<<LIST::query(p)<<endl;
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                cout<<LIST::get_max()<<endl;
                break;
        }
//        cout<<_<<endl;
    }
    LIST::clear();
    return 0;
}
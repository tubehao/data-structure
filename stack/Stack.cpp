#include "Stack.h"
#include <iostream>
using namespace std;


//seqStack<elemType> copied;

/*template<class elemType>
seqStack<elemType> copy(seqStack<elemType> s) {
    seqStack<elemType> s1;
    while (!s.isEmpty()){
        s1.push(s.pop());
    }
    while (!s1.isEmpty()){
        elemType a = s1.pop();
        s.push(a);
        copied.push(a);
    }
    return copied;
}*/

bool match(seqStack<char> &s1){
    seqStack<char> right;
    seqStack<char> store;
    while (!s1.isEmpty()){
        char a = s1.pop();
        store.push(a);
//        cout<<a<<' ';
//        cout<<endl;
        if (a == ')') {
            right.push(a);
        }
        else{
            if (right.isEmpty()){
                while (!store.isEmpty()){
                    char x = store.pop();
//                    cout<<x<<endl;
                    s1.push(x);
                }
                return false;
            }
            right.pop();
        }
    }
    if (!right.isEmpty()){
        while (!store.isEmpty()){
            char x = store.pop();
//            cout<<x<<endl;
            s1.push(x);
        }
        return false;
    }
    while (!store.isEmpty()){
        char x = store.pop();
//        cout<<x<<endl;
        s1.push(x);
    }
    return true;
}
int main(){
    seqStack<char> s;
    int n;
    cin>>n;
    while (n>0){
        int oper;
        cin>>oper;
        switch (oper) {
            case 1:
                char a;
                cin>>a;
                s.push(a);
                break;
            case 2:
                if (s.isEmpty()) break;
                s.pop();
                break;
            case 3:
                if (s.isEmpty()) break;
                cout<<s.top()<<endl;
                break;
            case 4:
//                cout<<"top"<<s.top()<<endl;
//                seqStack<char> s1;
//                cout<<1111<<s1.top();
                if (match(s)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
//                cout<<"top"<<s.top()<<endl;
                break;
        }
        n--;
    }
    return 0;
}
/*int main(){
    seqStack<int> s;
    for (int i = 0;i<5;i++){
        s.push(i);
    }
    seqStack<int> s1 = s.copy();
    for (int i = 0;i<5;i++){
        cout<<(s1.pop()==s.pop())<<endl;
    }
}*/

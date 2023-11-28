#include <iostream>
using namespace std;

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
    maxSize*=2;
    delete []array;
    array = temp;
}


bool match(seqStack<char> &s1){
    seqStack<char> rights,rightm,rightl,right;
//    seqStack<char> store;
    while (!s1.isEmpty()){
        char a = s1.pop();
//        store.push(a);
//        cout<<a<<' ';
//        cout<<endl;
        if (a == ')'||a==']'||a == '}') {
            right.push(a);
            /* switch (a) {
                 case ')':
                     rights.push(a);
                     break;
                 case ']':
                     rightm.push(a);
                     break;
                 case '}':
                     rightl.push(a);
                     break;
             }*/
        }
        else{
            switch (a) {
                case '(':
                    /*if (rights.isEmpty()){
                        while (!rightl.isEmpty()){
                            char x = rightl.pop();
                            s1.push(x);
                        }
                        while (!rightm.isEmpty()){
                            char x = rightm.pop();
                            s1.push(x);
                        }
                        return false;
                    }*/
                    if (right.isEmpty() || right.top() != ')') {
                        while (!right.isEmpty()) {
                            char x = right.pop();
                            s1.push(x);
                        }
                        return false;
                    }
                    right.pop();
                    break;
                case '[':
                    if (right.isEmpty() || right.top() != ']') {
                        while (!right.isEmpty()) {
                            char x = right.pop();
                            s1.push(x);
                        }
                        return false;
                    }
                    right.pop();
                    break;
                case '{':
                    if (right.isEmpty() || right.top() != '}') {
                        while (!right.isEmpty()) {
                            char x = right.pop();
                            s1.push(x);
                        }
                        return false;
                    }
                    right.pop();
                    break;
            }
        }

    }
    /*if (!(rights.isEmpty()&&rightl.isEmpty()&&rightm.isEmpty())){
        while (!rights.isEmpty()){
            char x = rights.pop();
            s1.push(x);
        }
        while (!rightm.isEmpty()){
            char x = rightm.pop();
            s1.push(x);
        }
        while (!rightl.isEmpty()){
            char x = rightl.pop();
            s1.push(x);
        }
        return false;
    }*/
    if (!right.isEmpty()){
        while (!right.isEmpty()){
            char x = rights.pop();
            s1.push(x);
        }
        return false;
    }
    return true;
}

int main(){
    seqStack<char> s;
    seqStack<char> matching;
    int n;
    cin>>n;
    while (n>0){
        int oper;
        cin>>oper;
        char pop_character;
        switch (oper) {
            case 1:
                char a;
                cin>>a;
                s.push(a);
                matching.push(a);
                break;
            case 2:
                if (s.isEmpty()) break;
                pop_character = s.pop();
                if (matching.isEmpty()){
                    switch (pop_character) {
                        case ')':
                            matching.push('(');
                            break;
                        case ']':
                            matching.push('[');
                            break;
                        case '}':
                            matching.push('{');
                            break;
                        default:
                            break;
                    }
                }
                else matching.pop();
                break;
            case 3:
                if (s.isEmpty()) break;
                cout<<s.top()<<endl;
                break;
            case 4:
                if (match(matching)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                break;
        }
        n--;
    }
    return 0;
}

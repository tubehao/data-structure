#include <iostream>
using namespace std;
class outOfBound{};
template <class elemType>
class linkStack;
template <class elemType>
class Node
{  friend class linkStack<elemType>;
private:
    elemType data;
    Node *next;
public:
    Node(){next = NULL;}
    Node(const elemType &x, Node *p=NULL)
    { data = x; next = p; }
};


template <class elemType>
class linkStack
{
private:
    Node<elemType> *Top;
public:
    linkStack(){ Top = NULL; }; //初始化栈，使其为空栈
    bool isEmpty(){ return (Top==NULL); }; //栈为空返回true,否则返回false。
    bool isFull(){ return false; }; //栈满true，否则false。结点空间不连续，故总能满足
    elemType top();
    void push(const elemType &e);
    void pop();
    ~linkStack();
};


template <class elemType>
elemType linkStack<elemType>::top()
{
    if (!Top) throw outOfBound();//栈空
    return Top->data;
}


template <class elemType>
void linkStack<elemType>::push(const elemType &e)
{  Top = new Node<elemType>(e, Top);  }


template <class elemType>
void linkStack<elemType>::pop()
{
    Node<elemType> *tmp;
    if (!Top) throw outOfBound();//栈空

    tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; //实际将栈顶结点弹出栈

    delete tmp;//释放原栈顶结点空间
}


template <class elemType>
linkStack<elemType>::~linkStack()
{
    Node<elemType> *tmp;
    while (Top)
    {
        tmp = Top;
        Top=Top->next;
        delete tmp;
    }
}

int get_int(){
    string s;
    char c = '0';
    while (c!='.')
    {
        cin>>c;
        s += c;
    }
    return stoi(s);
}

int string_to_int(const string& s){
    int res = 0;
    for (char i : s){
        res = res*10 + i-'0';
    }
    return res;
}

int calcPost(string Str)
{   int op1, op2, op;
    int tmp, i;
    linkStack<int> s;
    i=0;
    string store;
    while (Str[i]!='@'){
        if ((Str[i]>='0')&&(Str[i]<='9'))
        {
            store+=Str[i];
        }
        else if (Str[i] == '.'){
            tmp = string_to_int(store);
            store = "";
            s.push(tmp);
        }
        else
        {
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            switch (Str[i])
            {
                case '*': op = op1*op2; break;
                case '/': op = op1/op2; break;
                case '+': op = op1+op2; break;
                case '-': op = op1-op2; break;
            };
            s.push(op);
        }
        i++;
    }
    op = s.top();
    s.pop();
    return op;
}


int main(){
    linkStack<int> s_num;
    linkStack<char> s_char;
    int n;
    string in;
    cin>>in;
    cout<<calcPost(in)<<endl;



    return 0;
}



















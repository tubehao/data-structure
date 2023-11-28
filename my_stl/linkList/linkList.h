#ifndef lINKLIST_H_INCLUDED
#define lINKLIST_H_INCLUDED

class outOfBound{};

template <class elemType>
class linkList;//���ǰ��˵��

template <class elemType>
class node
{
    friend class linkList<elemType>;
private:
    elemType data;
    node* next;
public:
    node():next(NULL){};
    node(const elemType &e,node *N = NULL)
        {data = e; next = N;};
};


template <class elemType>
class linkList
{
private:
    node<elemType> *head;
public:
    linkList();
    bool isEmpty() const;
    //bool isFull() const {return false};
    int length() const;
    elemType get(int i) const;
    int find(const elemType &e) const;
    void insert(int i,const elemType &e);
    void remove(int i,elemType &e);
    void reverse() const;
    void clear();
    ~linkList();
};


template <class elemType>
linkList<elemType>::linkList()
{
    head = new node<elemType>();
}

template <class elemType>
bool linkList<elemType>::isEmpty() const
{
    if (head->next == nullptr) return true;
    return false;
}

template <class elemType>
int linkList<elemType>::length() const
{
    int count = 0;
    node<elemType> *p;
    p = head->next;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

template <class elemType>
elemType linkList<elemType>::get(int i) const
{
    if (i<1) throw outOfBound();
    int j = 1;
    node<elemType> *p = head->next;
    while (p && j<i)
    {
        p = p->next;
        j++;
    }
    if (p) return p->data;
    else throw outOfBound();
}

//���ص���e��Ԫ�ص���ţ����Ҳ����򷵻�0
template <class elemType>
int linkList<elemType>::find(const elemType &e) const
{
    int i=1;
    node<elemType> *p = head->next;

    while (p)
    {
        if (p->data == e) break;
        i++;
        p = p->next;
    }
    if (p) return i;
    return 0;
}

template <class elemType>
void linkList<elemType>::insert(int i,const elemType &e)
{
    if (i<1) return;
    int j=0;
    node<elemType> *tmp,*p = head;

    while(p && j<i-1)
    {
        j++;
        p = p->next;
    }

    if (!p) return;
    tmp = new node<elemType>(e,p->next);
    p->next = tmp;
}

template <class elemType>
void linkList<elemType>::remove(int i,elemType &e)
{
    if (i<1) return;
    int j = 0;
    node<elemType> *tmp,*p = head;

    while(p && j<i-1)
    {
        j++;
        p = p->next;
    }

    if (!p && p->next) return;//����iԽ��
    tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

template <class elemType>
void linkList<elemType>::clear()
{
    node<elemType> *p,*q;

    p = head->next;
    head->next = nullptr;

    while(p)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class elemType>
linkList<elemType>::~linkList()
{
    clear();
    delete head;
}

template <class elemType>
void linkList<elemType>::reverse() const
{   node<elemType> *p,*q;  //兄弟俩协同
     p=head->next;   head->next = NULL;  
     while (p)
    {  q = p->next;
        p->next = head->next; head->next = p; //首席插入
        p=q;
    }
}


#endif // linkList_H_INCLUDED

//
// Created by 12268 on 2023/11/14.
//

#ifndef SEQUENCE_QUERY_SEQUENCE_QUERY_H
#define SEQUENCE_QUERY_SEQUENCE_QUERY_H

template<class elemType>
class staticQuery {
    private:
        elemType *data;
        int len;
    public:
        staticQuery(elemType a[], int x);
        int seqQuery(elemType const &x)const;
        int Bsearch(elemType const &x)const;
        int insertSearch(elemType const &x)const;
        int BlockSearch(elemType const &x, int blockSize, int index[], int indexSum) ;

};

template<class elemType>
int staticQuery<elemType>::BlockSearch(const elemType &x, int blockSize, int *index, int indexSum) {
    int i = 0;
    while (i<len&&data[i]<x){
        i+=blockSize;
    }
    int j = i-blockSize+1;
    for(int k = j; k < i; k++){
        if(data[k] == x) return k;
    }
    return 0;
}

template<class elemType>
int staticQuery<elemType>::insertSearch(const elemType &x) const {
    int i;
    int left = 1,right = len;
    while(left<=right){
        i=left+(right-left)*((x-data[left])/(data[right]-data[left]));
        if(data[i] == x) return i;
        if(data[i]<x) {
            left = i+1;
        }
        else right = i-1;
    }
    return 0;
}

template<class elemType>
staticQuery<elemType>::staticQuery(elemType *a, int x) {
    data = new elemType(x+1);
    for(int i = 1;i<=x; i++){
        data[i] = a[i-1];
    }
    len = x;
}

template<class elemType>
int staticQuery<elemType>::seqQuery(const elemType &x) const {
    int i = len;
    data[0] = x;
    while(true){
        if(data[i] == x) break;
        i--;
    }
    return i;
}

template<class elemType>
int staticQuery<elemType>::Bsearch(const elemType &x) const {
    int i;
    int left = 1,right = len;
    while(left<=right){
        i = (left+right)/2;
        if(data[i] == x) return i;
        if(data[i]<x) {
            left = i+1;
        }
        else right = i-1;
    }
    return 0;
}



#endif //SEQUENCE_QUERY_SEQUENCE_QUERY_H

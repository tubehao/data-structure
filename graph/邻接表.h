//
// Created by 12268 on 2023/12/11.
//

#ifndef PICTURE_GRAPH_H
#define PICTURE_GRAPH_H

#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <class edgeType>
struct edgeNode{
    int dest;
    edgeType weight;
    edgeNode<edgeType> *link;
};


template <class verType, class edgeType>
struct verNode{
    verType data;
    edgeNode<edgeType> *adj;
};

template <class verType, class edgeType>
class graph {
private:
    int verts, edges;
    int maxVertex;// 图的实际顶点数
    verNode<verType, edgeType> *verList;
    bool directed;                 // 有向图为 true，无向图为 false

public:
    graph(bool direct) : directed(direct) {
        int i ;
        directed = direct;
        verts = 0;
        edges = 0;
        maxVertex = 20;
        verList = new verNode<verType, edgeType>[maxVertex];
    }

    ~graph(){
        int i;
        edgeNode<edgeType> *p, *q;
        for(i = 0; i<verts;i++){
            while(verList[i].adj != NULL){
                p = verList[i].adj;
                verList[i].adj = p->link;
                delete p;
            }
        }
        delete []verList;
    }

    int numberOfVertex() const {
        return verts;
    }

    int numberOfEdge() const {
        return edges;
//        int edgeCount = 0;
//        for (const auto &adj : verList) {
//            edgeCount += adj.size();
//        }
//        return directed ? edgeCount : edgeCount / 2;
    }

    bool existEdge(verType vertex1, verType vertex2) const {
        int index1 = -1, index2 = -1;
        for (int i = 0; i < verts; i++) {
            if (verList[i] == vertex1) {
                index1 = i;
            } else if (verList[i] == vertex2) {
                index2 = i;
            }
        }
        if (index1 == -1 || index2 == -1) {
            return false; // 顶点不存在
        }
        edgeNode<edgeType> *p = verList[index1].adj;
        while (p != nullptr){
            if(p->dest == index2){
                return true;
            }
            p = p->link;
        }

        return false; // 未找到边
    }

    void insertVertex(verType vertex) {
        if(verts == maxVertex){
            cout << "图的顶点数超过最大值" << endl;
            return;
        }
        verList[verts].data = vertex;
        verList[verts].adj = nullptr;
        verts++;
    }

    void insertEdge(verType vertex1, verType vertex2, edgeType edge) {
        int index1 = -1, index2 = -1;
        for (int i = 0; i < verts; i++) {
            if (verList[i] == vertex1) {
                index1 = i;
            } else if (verList[i] == vertex2) {
                index2 = i;
            }
        }
        if (index1 == -1 || index2 == -1) {
            return; // 顶点不存在
        }

        edgeNode<edgeType> *p = new edgeNode<edgeType>;
        p->dest = index2;
        p->weight = edge;
        p->link = verList[index1].adj;
        verList[index1].adj = p;
        edges++;
        if(!directed){
            p = new edgeNode<edgeType>;
            p->dest = index1;
            p->weight = edge;
            p->link = verList[index2].adj;
            verList[index2].adj = p;
        }
    }

    void removeVertex(verType vertex) {
        int i;
        int count = 0;
        edgeNode<edgeType> *p, *q, *tmp;
        for(i = 0; i < verts; i++){
            if(verList[i].data == vertex){
                break;
            }
        }
        if(i == verts){
            cout << "图中没有这个顶点" << endl;
            return;
        }
        while (verList[i].adj != nullptr){
            p = verList[i].adj;
            verList[i].adj = p->link;
            delete p;
            count++;
        }
        for(int j = 0; j < verts; j++){
            p = verList[j].adj;
            q = nullptr;
            while (p != nullptr){
                if(p->dest == i){
                    break;
                }
                q = p;
                p = p->link;
            }
            if (!p) continue;
            if (!q) verList[i].adj = p->link;
            else q->link = p->link;
            delete p;
            count++;
        }
        for(int j = 0; j < verts; j++){
            p = verList[j].adj;
            while (p != nullptr){
                if(p->dest > i){
                    p->dest--;
                }
                p = p->link;
            }
        }
        if(directed) edges -= count;
        else edges -= count / 2;

        for(int j = 0;j<verts;j++){
            if(j > i){
                verList[j-1] = verList[j];
            }
        }
        verts--;

    }


    //not changed
    /*void removeEdge(verType vertex1, verType vertex2) {
        int index1 = -1, index2 = -1;
        for (int i = 0; i < verts; i++) {
            if (verList[i] == vertex1) {
                index1 = i;
            } else if (verList[i] == vertex2) {
                index2 = i;
            }
        }
        if (index1 == -1 || index2 == -1) {
            return; // 顶点不存在
        }

        for (auto it = adjList[index1].begin(); it != adjList[index1].end();) {
            if (it->first == index2) {
                it = adjList[index1].erase(it);
            } else {
                ++it;
            }
        }

        if (!directed) {
            for (auto it = adjList[index2].begin(); it != adjList[index2].end();) {
                if (it->first == index1) {
                    it = adjList[index2].erase(it);
                } else {
                    ++it;
                }
            }
        }
    }*/

    void DFS() const{
        bool *visited = new bool[verts];
        for (int i = 0; i < verts; i++)
            visited[i] = false;
        for (int i = 0; i < verts; i++){
            if(!visited[i])
                DFS(i, visited);
        }
    }

    void DFS(int start, bool visited[]) const{
        edgeNode<edgeType> *p;
        visited[start] = true;
        cout<< verList[start] << " ";
        p = verList[start].adj;
        while (p){

        }
    }
};
#endif // PICTURE_GRAPH_H

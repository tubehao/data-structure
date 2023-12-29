//
// Created by 12268 on 2023/12/7.
//

#ifndef CLION_CPPCODE_GRAPH_H
#define CLION_CPPCODE_GRAPH_H
#define DefaultNumVertex 20

template<class edgeType>
struct edgeNode{
    int dest;
    edgeType weight;
    edgeNode *link;
};

template <class verType, class edgeType>
struct  verNode{
    verType data;
    edgeNode<edgeType> *adj;
};

template <class verType, class edgeType>
class graph {
private:
    boo directed;
    int verts, edges;
    int maxVertex;
    verNode<verType, edgeType> *verList;
public:
    graph(bool direct){
        int i;
        directed = direct;
        verts = 0;
        edges = 0;
        maxVertex = DefaultNumVertex;
        verList = new verNode<verType, edgeType>[maxVertex];
    }
    ~graph(){
        int i;
        edgeNode<edgeType> *p;
        for (i = 0; i<verts; i++){
            while (verList[i].adj){
                p = verList[i].adj;
                verList[i].adj = p->link;
                delete p;
            }
        }
        delete []verList;
    };
    int numOfVertex{ret};
    int numberOfEdge()const{ return edges; }; // 返回图当前边数
    int getVertex(verType vertex) const{//返回顶点为vertex值的元素在顶点表中的下标
        for(int i = 0; i<verts; i++)
            if (verList[i] == vertex)
                return i;
        return -1;
    }
    bool existEdge(verType vertex1,verType vertex2)const{

    }; //判断某两个顶点间是否有边
    int getFirstNeighbor(verType vertex ) const{

    };
    //返回顶点vertex1的相对vertex2的下一个邻接点，如无下一个邻接点返回-1\

    int getNextNeighbor(verType vertex1, verType vertex2)const{

    };
    void disp() const{

    }; //显示邻接矩阵的值
    void insertVertex(verType vertex){
        if(verts == maxVertex) return;
        verList[verts].data = vertex;
        verList[verts].adj = NULL;
        verts++;
    }; //插入顶点

    void insertEdge(verType vertex1, verType vertex2, edgeType edge){
        int i, j;
        edgeNode<edgeType> *p;
        for(i = 0; i<verts; i++)
            if (verList[i].data == vertex1)
                break;
        for(j = 0; j<verts; j++)
            if (verList[j].data == vertex2)
                break;
        if(i == verts || j == verts) return;
        p = new edgeNode<edgeType>;
        tmp->dest = j;
        tmp->weight = edge;
        tmp->link = verList[i].adj;
        verList[i].adj = tmp;
        edges++;
        if(!directed){
            p = new edgeNode<edgeType>;
            tmp->dest = i;
            tmp->weight = edge;
            tmp->link = verList[j].adj;
            verList[j].adj = tmp;
        }
    }; //插入边
    void removeVertex(verType vertex){
        int i, j;
        edgeNode<edgeType> *p, *q;
        for(i = 0; i<verts; i++)
            if (verList[i].data == vertex)
                break;
        if(i == verts) return;
        while (verList[i].adj){
            p = verList[i].adj;
            verList[i].adj = p->link;
            delete p;
        }
        verts--;
        verList[i].data = verList[verts].data;
        p = verList[i].adj = verList[verts].adj;
        while (p){
            j = p->dest;
            q = verList[j].adj;
            while (q){
                if(q->dest == verts){
                    q->dest = i;
                    break;
                }
                q = q->link;
            }
            p = p->link;
        }
    };  //删除顶点
    void removeEdge(verType vertex1, verType vertex2){}; //删除边

};


#endif //CLION_CPPCODE_GRAPH_H

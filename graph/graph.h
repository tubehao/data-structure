//
// Created by 12268 on 2023/12/4.
//

#ifndef PICTURE_GRAPH_H
#define PICTURE_GRAPH_H

#define DefaultNumVertex 20



template <class verType, class edgeType>
class graph {
private:
    int verts, edges;   //图的实际顶点数和实际边数
    int maxVertex;      //图顶点的最大可能数量
    verType *verList;   // 保存顶点数据的一维数组
    edgeType **edgeMatrix; //保存邻接矩阵内容的二维数组
    edgeType noEdge;       //无边的标志???????
    bool directed;          //有向图为1，无向图为0

public:
    graph(bool direct, edgeType e){
        int i, j;
        directed = direct;
        noEdge = e;
        verts = 0;
        edges = 0;
        maxVertex = DefaultNumVertex;
        verList = new verType[maxVertex];
        edgeMatrix = new edgeType*[maxVertex];
        for (i = 0; i<maxVertex; i++){
            edgeMatrix[i] = new edgeType[maxVertex];
        }
        for (i=0; i<maxVertex; i++)
            for (j=0; j<maxVertex; j++)
                if (i==j)   edgeMatrix[i][j] = 0;//对角线元素
                else   edgeMatrix[i][j] = noEdge; //无边
    }
    ~graph(){
        int i;
        delete []verList;
        for(i = 0; i < maxVertex; i++){
            delete []edgeMatrix[i];
        }
        delete edgeMatrix;
    }
    int numberOfVertex() const{return verts;};
    int numberOfEdge() const{return edges;}
    int getVertex(verType vertex) const{//返回顶点为vertex值的元素在顶点表中的下标
        for(int i = 0; i<verts; i++)
            if (verList[i] == vertex)
                return i;
        return -1;
    }
    bool existEdge(verType vertex1, verType vertex2) const{//判断某两个顶点是否有边
        int i, j;
        for(i = 0; i < verts; i++){
            if(verList[i] == vertex1)
                break;
        }
        for(j = 0; j < verts; j++){
            if (verList[j] == vertex2)
                break;
        }
        if(i == verts || j == verts) return false;
        if(edgeMatrix[i][j] == noEdge) return false;
        return true;
    }
    void insertVertex(verType vertex){
        int i;
        verList = new verType[maxVertex+1];
        for (i = 0; i<maxVertex; i++){
            edgeMatrix[i] = new edgeType[maxVertex];
        }
    }
    void insertEdge(verType vertex1, verType vertex2, edgeType edge){
        int i, j;
        for(i = 0; i < verts; i++){
            if(verList[i] == vertex1)
                break;
        }
        for(j = 0; j < verts; j++){
            if (verList[j] == vertex2)
                break;
        }
        if(i == verts || j == verts) return;
        edgeMatrix[i][j] = edge;
        if(!directed) edgeMatrix[j][i] = edge;

    }
    void removeVertex(verType vertex){
        int i, j, k;
        for (i=0; i<verts; i++)
            if (verList[i]==vertex)  break;
        if (i==verts) return;  //没有找到要删除的顶点
        for (j=i; j<verts-1; j++)
            verList[j] = verList[j+1];

        //计数删除顶点射出的边,边数减少!!!!!!!!!!!这样可以避免遍历整个矩阵
        for (j=0; j<verts; j++)
            if ( (j!=i) && (edgeMatrix[i][j] != noEdge))
                edges--;
        //如果是有向图，计数删除顶点射入的边,边数减少
        if (directed){
            for (k=0; k<verts; k++)
                if (( (k!=i) && edgeMatrix[k][i]!= noEdge))
                    edges--;
        }
        for (j=i; j<verts-1; j++)
        {   for (k=0; k<verts; k++)
            {   edgeMatrix[j][k] = edgeMatrix[j+1][k];   }
        }
        //第i列之后所有列左移
        //第i列之后所有列前移
        for (j=i; j<verts-1; j++)
        {
            for (k=0; k<verts; k++)
                edgeMatrix[k][j] = edgeMatrix[k][j+1];
        }
        verts--;
    }

    //删除顶点
    void removeEdge(verType vertex1, verType vertex2){
        int i, j;
        for(i = 0; i < verts; i++){
            if(verList[i] == vertex1)
                break;
        }
        for(j = 0; j < verts; j++){
            if (verList[j] == vertex2)
                break;
        }
        if(i == verts || j == verts) return;
        edgeMatrix[i][j] = noEdge;
        if(!directed) edgeMatrix[j][i] = noEdge;
        edges--;
    } //删除边
    int getFirstNeighbor(verType vertex) const {
        int i;
        for (i = 0; i < verts; i++) {
            if (verList[i] == vertex)
                break;
        }
        if (i == verts) {
            return -1; // 顶点不存在
        }

        for (int j = 0; j < verts; j++) {
            if (edgeMatrix[i][j] != noEdge) {
                return j; // 返回第一个邻接点的下标
            }
        }
        return -1; // 没有邻接点
    }

    int getNextNeighbor(verType vertex1, verType vertex2) const {
        int i, j;
        for (i = 0; i < verts; i++) {
            if (verList[i] == vertex1)
                break;
        }
        if (i == verts) {
            return -1; // 顶点1不存在
        }

        for (j = 0; j < verts; j++) {
            if (verList[j] == vertex2)
                break;
        }
        if (j == verts) {
            return -1; // 顶点2不存在
        }

        for (int k = j + 1; k < verts; k++) {
            if (edgeMatrix[i][k] != noEdge) {
                return k; // 返回下一个邻接点的下标
            }
        }
        return -1; // 没有下一个邻接点
    }

   /* void disp() const {
        for (int i = 0; i < verts; i++) {
            for (int j = 0; j < verts; j++) {
                if (edgeMatrix[i][j] == noEdge) {
                    std::cout << "INF\t"; // 表示无边的情况
                } else {
                    std::cout << edgeMatrix[i][j] << "\t"; // 输出边的权值
                }
            }
            std::cout << std::endl;
        }
    }*/
//显示邻接矩阵的值




};


#endif //PICTURE_GRAPH_H

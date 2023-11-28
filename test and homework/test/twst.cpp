#include<iostream>
#include<vector>
using namespace std;
class TREENODE
{
public:
    int father;
    int num_line; //��¼�ýڵ��ص�����;���ڵ����һ���ӽڵ㣩������Զ���Ƚڵ��·��Ȩֵ
    int line_father;                                             //��Զ���Ƚڵ�
    int line_second_father;                                      //��Զ���Ƚڵ�
    int depth;
};
class MAP
{
public:
    vector<pair<int,int> > edge;
};
MAP* map;
TREENODE* tree;
void maketree(int nowpoint,int line_father,int line_second_father,int num_line,int depth)
{
    tree[nowpoint].line_father=line_father;
    tree[nowpoint].line_second_father=line_second_father;
    tree[nowpoint].num_line=num_line;
    tree[nowpoint].depth=depth;
    int size=map[nowpoint].edge.size();
    for(int i=0;i<size;i++)
    {
        if(tree[nowpoint].father==map[nowpoint].edge[i].first)
            continue;
        tree[map[nowpoint].edge[i].first].father=nowpoint;
    }
    if(size==1&&tree[nowpoint].father!=map[nowpoint].edge[0].first)
        maketree(map[nowpoint].edge[0].first,line_father,line_second_father,num_line+map[nowpoint].edge[0].second,depth+1);
    else if(size==2&&tree[nowpoint].father==map[nowpoint].edge[1].first)
        maketree(map[nowpoint].edge[0].first,line_father,line_second_father,num_line+map[nowpoint].edge[0].second,depth+1);
    else if(size==2&&tree[nowpoint].father==map[nowpoint].edge[0].first)
        maketree(map[nowpoint].edge[1].first,line_father,line_second_father,num_line+map[nowpoint].edge[1].second,depth+1);
    else
    {
        for(int i=0;i<size;i++)
        {
            if(tree[nowpoint].father==map[nowpoint].edge[i].first)
                continue;
            maketree(map[nowpoint].edge[i].first,nowpoint,map[nowpoint].edge[i].first,map[nowpoint].edge[i].second,depth+1);
        }
    }
    return ;
}
int search(int u,int v)
{

    int num=0;
    while(u!=v)
    {
        if(tree[u].line_father==tree[v].line_father&&tree[u].line_second_father==tree[v].line_second_father)
            return tree[u].num_line>tree[v].num_line?(num+tree[u].num_line-tree[v].num_line):(num+tree[v].num_line-tree[u].num_line);
        if(tree[u].depth>tree[v].depth)
        {
            num+=tree[u].num_line;
            u=tree[u].line_father;
        }
        else
        {
            num+=tree[v].num_line;
            v=tree[v].line_father;
        }
    }
    return num;
}
void my_getnum(int &a)
{
    a=0;
    char b;
    b=getchar();
    while(b<'0'||b>'9')
        b=getchar();
    while(b>='0'&&b<='9')
    {
        a=a*10+b-'0';
        b=getchar();
    }
    return ;
}
int main()
{
    int n;
    my_getnum(n);
    map=new MAP[n+1];
    tree=new TREENODE[n+1];
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        my_getnum(u);
        my_getnum(v);
        my_getnum(w);
        map[u].edge.push_back(make_pair(v,w));
        map[v].edge.push_back(make_pair(u,w));
    }
    tree[1].father=1;
    maketree(1,1,0,0,0);
    delete[] map;
    my_getnum(n);
    for(int i=1;i<=n;i++)
    {
        my_getnum(u);
        my_getnum(v);
        printf("%d\n",search(u,v));
    }
    delete tree;
    return 0;
}

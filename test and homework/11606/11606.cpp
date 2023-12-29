#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m, n1 = 0, n2 = 0, n3 = 0;
    cin >> n >> m;
    vector<vector<char>> firstMap;
    vector<vector<char>> secondMap;
    for (int i = 0;i<n;i++){//导入数据，将？设为#，并记录.的个数
        vector<char> temp;
        vector<char> temp2;
        for (int j = 0;j<m;j++){
            char tempChar;
            char changed;
            cin >> tempChar;
            changed = tempChar;
            if(tempChar == '?'){
                n1++;
                changed = '#';
            }
            if(tempChar == '.') {
                n2++;
            }
            temp.push_back(tempChar);
            temp2.push_back(changed);
        }
        firstMap.push_back(temp);
        secondMap.push_back(temp2);
    }
    if(n2 == 0){
        cout << "Impossible" << endl;
        return 0;
    }
    pair<int, int> start;
    for(int i = 0; i<n; i++){
        int flag = 0;
        for(int j = 0; j<m; j++){
            if(firstMap[i][j] == '.'){
                flag++;
                start = make_pair(i, j);
                break;
            }
        }
        if(flag == 1) break;
    }
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    q.push(start);
    n2--;
    firstMap[start.first][start.second] = '#';//!!!!!!
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int jj = 0;
        int x = temp.first;
        int y = temp.second;
        if(firstMap[x][y] == '!'){
            jj = 10;
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 检查新位置是否在网格范围内
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (firstMap[nx][ny] == '.') {
                    q.push({nx, ny});
                    firstMap[nx][ny] = '#';
                    n2--;
                    jj++;
                }
                else if (firstMap[nx][ny] == '?') {
                    q2.push({nx, ny});
                    firstMap[nx][ny] = '!';
                    n3++;
                    jj++;
                }
            }
        }
        if(jj == 10) {n3++;}
        if(q.empty() && n2 != 0) {
            if(!q2.empty()) {
                temp = q2.front();
                q2.pop();
                n3--;
                secondMap[temp.first][temp.second] = '.';
                q.push({temp.first, temp.second});
            }
        }
    }
    if(n2!=0) cout<<"Impossible"<<endl;
    if(n2==0&&n3!=0) cout<<"Ambiguous"<<endl;
    if(n2==0&&n3==0)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                cout<<secondMap[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
#include <iostream>
#include "queue"
#include "stack"
using namespace std;
int costs[6][6][5];
int nums[6][6];
int direct[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

class Points{
    public:
    int x;
    int y;
    int state;
    int cost;
    Points(int x,int y,int state,int cost){
        this->x = x;
        this->y = y;
        this->state = state;
        this->cost = cost;
    }
    bool operator<(const Points& p)const{
        return this->cost > p.cost;
    }
    bool less_than(){
        return this->cost < costs[this->x][this->y][this->state];
    }
};

int main () {
    int n;
    cin>>n;
    for(;n>0;n--) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= 4; k++) {
                    costs[i][j][k] = 99999;
                }
            }
        }
        for (auto &num: nums) {
            for (int j = 0; j < 6; j++) {
                cin >> num[j];
            }
        }
        int x, y, x_end, y_end;
        cin >> x >> y >> x_end >> y_end;
        queue<Points> points;
        points.emplace(Points(x, y, 1, 0));
        while (!points.empty()) {
            Points now_point = points.front();
            points.pop();
            if (now_point.less_than()) {
                costs[now_point.x][now_point.y][now_point.state] = now_point.cost;
                if (now_point.x == x_end && now_point.y == y_end) {
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    x = now_point.x + direct[i][0];
                    y = now_point.y + direct[i][1];
                    if (x >= 0 && y >= 0 && x <= 5 && y <= 5) {
                        points.push(Points(x, y, now_point.state * nums[x][y] % 4 + 1,
                                           now_point.state * nums[x][y] + now_point.cost));
                    }
                }
            }

        }
        int ans = 99999;
        for (int i = 1; i <= 4; i++) {
            if (costs[x_end][y_end][i] < ans) {
                ans = costs[x_end][y_end][i];
            }
        }
        cout << ans << endl;
    }
        return 0;
}
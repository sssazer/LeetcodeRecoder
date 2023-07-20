#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0; // x,y记录机器人当前坐标
        int maxDis = 0;
        unordered_map<int, vector<int>> xRow;
        unordered_map<int, vector<int>> yCol;
        for (vector<int>& v : obstacles) {
            if (xRow.find(v[0]) != xRow.end()) {
                xRow[v[0]].push_back(v[1]);
            }
            else {
                xRow[v[0]] = {v[1]};
            }
            if (yCol.find(v[1]) != yCol.end()) {
                yCol[v[1]].push_back(v[0]);
            }
            else {
                yCol[v[1]] = {v[0]};
            }
        }
        int orintation = 0; // 0表示北，1表示东，2表示南，3表示西   北0
                            //                                 西3       东1
                            //                                      南2
        for (int i : commands) {
            if (i > 0) { // 根据当前方向行走
                switch (orintation) {
                case 1: // 往东走
                    if (yCol.find(y) != yCol.end()) { // 如果将要行走的水平道上存在障碍
                        int obstruction = 100000;
                        for (int pos : yCol[y]) {
                            if (pos > x && pos <= x + i) { // 如果障碍正好在本次要经过的路上
                                if (pos < obstruction) { // 还要保证找到离当前位置最近的那个障碍
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // 有障碍的话就停在障碍前一格
                            x = obstruction - 1;
                            break;
                        }
                    }
                    x += i;
                    break;
                case 0: // 往北走
                    if (xRow.find(x) != xRow.end()) { // 如果将要行走的水平道上存在障碍
                        int obstruction = 100000;
                        for (int pos : xRow[x]) {
                            if (pos > y && pos <= y + i) { // 如果障碍正好在本次要经过的路上
                                if (pos < obstruction) { // 还要保证找到离当前位置最近的那个障碍
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // 有障碍的话就停在障碍前一格
                            y = obstruction - 1;
                            break;
                        }
                    }
                    y += i;
                    break;
                case 3: // 往西走
					if (yCol.find(y) != yCol.end()) { // 如果将要行走的竖直道上存在障碍
                        int obstruction = 100000;
                        for (int pos : yCol[y]) {
                            if (pos < x && pos >= x - i) { // 如果障碍正好在本次要经过的路上
                                if (pos < obstruction) { // 还要保证找到离当前位置最近的那个障碍
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // 有障碍的话就停在障碍前一格
                            x = obstruction + 1;
                            break;
                        }
                    }
                    x -= i;
                    break;
                case 2: // 往南走
                    if (xRow.find(x) != xRow.end()) { // 如果将要行走的水平道上存在障碍
                        int obstruction = 100000;
                        for (int pos : xRow[x]) {
                            if (pos < y && pos >= y - i) { // 如果障碍正好在本次要经过的路上
                                if (pos < obstruction) { // 还要保证找到离当前位置最近的那个障碍
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // 有障碍的话就停在障碍前一格
                            y = obstruction + 1;
                            break;
                        }
                    }
                    y -= i;
                    break;
                }
            }
            else { // 转向
                if (i == -1) {
                    orintation = (orintation + 1) % 4;
                }
                else {
                    orintation = (orintation + 3) % 4;
                }
            }
            maxDis = max(maxDis, x * x + y * y);
        }
        return maxDis;
    }
};

int main() {

	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int arrowTimes = 0; // 记录射箭的次数
        sort(points.begin(), points.end(), cmp);
        int i = 0;
        while (i < points.size()) {
            int arrowPos = points[i++][1]; // 确定本次射箭位置，保证能射爆i号气球的前提下尽可能往下射
            arrowTimes++;
            for (; i < points.size(); i++) {
                if (arrowPos >= points[i][0] && arrowPos <= points[i][1]) { 
                    continue;
                }
                break;
            }
        }
        return arrowTimes;
    }
};

int main() {

	return 0;
}
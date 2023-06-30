#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int left = 0 ,right = 0;
        int flag = true; // true表示当前区间是一个不重叠区间的开头
        for (int i = 0; i < intervals.size(); i++) {
            if (flag) {
                left = intervals[i][0], right = intervals[i][1];
                flag = false;
                continue;
            }
            if (intervals[i][0] <= right) { // 如果存在重叠
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            }
            else {
                flag = true;
                i--;
                result.push_back({left, right});
            }
        }
        result.push_back({left, right});
        return result;
    }
};

//int main() {
//
//    Solution s;
//    vector<vector<int>> intervals = {
//        {1,3},
//        {2,6},
//        {8, 10},
//        {15, 18}
//    };
//    s.merge(intervals);
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        if (v1[1] == v2[1]) {
            return v1[0] < v2[0];
        }
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int leftNums = 1; // ��¼�����ڵ���������Ҳ���ǲ��ص�������������
        int lastLeft = 0; // ��һ�����µ������Ǽ�������
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[lastLeft][1]) {
                leftNums++;
                lastLeft = i;
            }
        }
        return intervals.size() - leftNums;
    }
};

//int main() {
//
//	return 0;
//}
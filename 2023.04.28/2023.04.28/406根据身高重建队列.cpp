#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) { // 按身高从大到小排序
        if (v1[0] == v2[0]) {
            return v1[1] < v2[1];
        }
        return v1[0] > v2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;
        for (auto& v : people) {
            result.insert(result.begin() + v[1], v);
        }
        return result;
    }
};

//int main() {
//
//	return 0;
//}
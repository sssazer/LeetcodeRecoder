#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // 暴力，无法ac
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int start = 0; start < cost.size(); start++) { // 遍历起始加油站
            if (gas[start] < cost[start]) {
                continue;
            }
            int leftGas = gas[start] - cost[start]; // 记录剩下的汽油量
            int i;
            for (i = (start + 1) % cost.size(); i != start; i = (i + 1) % cost.size()) {
                leftGas += (gas[i] - cost[i]);
                if (leftGas <= 0) {
                    break;
                }
            }
            if (i == start || ((i + 1) % cost.size() == start && leftGas >= 0)) {
                return start;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> left(gas.size()); // 经过每个加油站后留下的油
        int sumLeft = 0;
        for (int i = 0; i < gas.size(); i++) {
            left[i] = gas[i] - cost[i];
            sumLeft += left[i];
        }
        if (sumLeft < 0) { // 如果加油站的油加起来都不够花费，那肯定走不完
            return -1;
        }
        int start = 0;
        int curLeft = 0;
        for (int i = 0; i < gas.size(); i++) {
            curLeft += left[i];
            if (curLeft < 0) { // 如果从0走到i之后剩的油变成负数，那肯定不能从0~i之间任何一个加油站开始
                start = i + 1;
                curLeft = 0;
            }
        }
        return start;
    }
};

//int main() {
//
//    vector<int> gas = {3,1,1};
//    vector<int> cost = { 1,2,2 };
//    Solution s;
//    s.canCompleteCircuit(gas, cost);
//
//	return 0;
//}
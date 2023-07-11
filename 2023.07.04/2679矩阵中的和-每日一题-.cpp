#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution { // 排序
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score = 0;
        for(vector<int> & v : nums){
            sort(v.begin(), v.end(), greater<int>());
        }
        for(int j = 0; j < nums[0].size(); j++){
            int maxNum = 0;
            for(int i = 0; i < nums.size(); i++){
                maxNum = max(maxNum, nums[i][j]);
            }
            score += maxNum;
        }
        return score;
    }
};

class Solution { // 优先队列（最大堆）
public:
    int matrixSum(vector<vector<int>>& nums) {
        vector<priority_queue<int>> pq(nums.size(), priority_queue<int>());
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                pq[i].push(nums[i][j]);
            }
        }
        int score = 0;
        for(int i = 0; i < nums[0].size(); i++){
            int maxNum = 0;
            for(int j = 0; j < pq.size(); j++){
                maxNum = max(maxNum, pq[j].top());
                pq[j].pop();
            } 
            score += maxNum;
        }
        return score;
    }
};

int main(){

    return 0;
}
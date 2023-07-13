#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution { // 暴力，找到每个元素的左侧最大高度和右侧最大高度，纵向算容量
public:
    int trap(vector<int>& height) {
        vector<vector<int>> vec(height.size(), vector<int>(2, -1)); // 存放每个位置的左侧更大元素的位置和右侧更大元素的位置
        int leftMax = height[0];
        for(int i = 1; i < height.size(); i++){ // 先找到左侧更大元素
            if(leftMax > height[i]){
                vec[i][0] = leftMax;
            }
            leftMax = max(leftMax, height[i]);
        }
        int rightMax = height.back();
        for(int i = height.size() - 2; i >= 0; i--){
            if(rightMax > height[i]){
                vec[i][1] = rightMax;
            }
            rightMax = max(rightMax, height[i]);
        }
        int capacity = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i][0] > 0 && vec[i][1] > 0){
                capacity += min(vec[i][0], vec[i][1]) - height[i];
            }
        }
        return capacity;
    }
};

class Solution {
public:
    int trap(vector<int>& height) { // 单调栈
        stack<int> st;
        int capacity = 0;
    }
};

int main(){

    return 0;
}
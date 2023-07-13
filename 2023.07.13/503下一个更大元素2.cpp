#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; // 单调栈,存储的是元素下标
        vector<int> result(nums.size(), -1);
        for(int i = 0; i < nums.size() * 2 - 1; i++){
            while(!st.empty() && nums[i % nums.size()] > nums[st.top()]){
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return result;
    }
};

int main(){

    return 0;
}
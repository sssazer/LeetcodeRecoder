#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; // 单调栈
        unordered_map<int, int> map; // 存储nums2中每个元素的下一个更大元素
        for(int i = 0; i < nums2.size(); i++){
            map[nums2[i]] = -1;
            while(!st.empty() && nums2[i] > st.top()){
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> result(nums1.size(), 0);
        for(int i = 0; i < nums1.size(); i++){
            result[i] = map[nums1[i]];
        }
        return result;
    }
};

int main(){

    return 0;
}
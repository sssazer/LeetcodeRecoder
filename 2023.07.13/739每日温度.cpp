#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution { // 暴力
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            int j;
            for(j = i + 1; j < temperatures.size() && temperatures[j] <= temperatures[i]; j++){}
            if(j < temperatures.size()){
                res[i] = j - i;
            } 
        }
        return res;
    }
};

class Solution { // 单调栈
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // 单调栈，要求从栈底到栈顶保持非递增,存放的是下标
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

int main(){

    return 0;
}
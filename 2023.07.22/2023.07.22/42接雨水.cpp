#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution { // 单调栈
public:
    int trap(vector<int>& height) {
        int result = 0; // 能接的雨水总量
        stack<int> stk; // 单调栈 ，里面存放的是下标
        if (height[0]) {
            stk.push(0);
        }
        for (int i = 1; i < height.size(); i++) {
            if (stk.empty() && height[i] < height[stk.top()]) {
                stk.push(i);
            }
            else if (height[i] == height[stk.top()]) {
                stk.pop();
                stk.push(i);
            }
            else { // 当前元素比栈顶元素大时，说明出现凹槽
                while (!stk.empty() && height[i] > height[stk.top()]) {
					int bottom = stk.top();
					stk.pop();
                    if (stk.empty()) {
                        break;
                    }
                    // 计算凹槽的宽和高
                    int w = i - stk.top() - 1;
                    int h = min(height[i], height[stk.top()]) - bottom;
                    result += w * h;
                    stk.push(i);
                }
            }
        }
        return result;
    }
};

//int main() {
//
//	return 0;
//}
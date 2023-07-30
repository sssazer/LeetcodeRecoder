#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution { // ����ջ
public:
    int trap(vector<int>& height) {
        int result = 0; // �ܽӵ���ˮ����
        stack<int> stk; // ����ջ �������ŵ����±�
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
            else { // ��ǰԪ�ر�ջ��Ԫ�ش�ʱ��˵�����ְ���
                while (!stk.empty() && height[i] > height[stk.top()]) {
					int bottom = stk.top();
					stk.pop();
                    if (stk.empty()) {
                        break;
                    }
                    // ���㰼�۵Ŀ�͸�
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
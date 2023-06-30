#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3 != 0) {
            return false;
        }
        stack<char> stk;
        for (char c : s) {
            switch (c) {
            case 'a':
                stk.push(c);
                break;
            case 'b':
                stk.push(c);
                break;
            case 'c':
                if (stk.size() > 0 && stk.top() == 'b') {
                    stk.pop();
                }
                else {
                    return false;
                }
                if (stk.size() > 0 && stk.top() == 'a') {
                    stk.pop();
                }
                else {
                    return false;
                }
                break;
            default:
                return false;
                break;
            }
        }
        return stk.size() == 0;
    }
};

//int main() {
//
//    string s = "abccba";
//    Solution sl;
//    cout << sl.isValid(s);
//
//	return 0;
//}

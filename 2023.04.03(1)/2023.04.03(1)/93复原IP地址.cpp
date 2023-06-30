#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:

    vector<string> result;
    vector<int> IPs;
    string nums;

    void traceback(int startIndex) {
        if (IPs.size() == 4 && startIndex < nums.size()) {
            return;
        }
        if (IPs.size() == 4 && startIndex == nums.size()) {
            string I;
            for (int i = 0; i < 4; i++) {
                if (i) {
                    I += ".";
                }
                I += to_string(IPs[i]);
            }
            result.push_back(I);
            return;
        }
        for (int len = 1; len <= 3; len++) { // 数字长度最多为3
            if (nums.size() - len - startIndex > 4 * (4 - IPs.size())) { // 如果选择一个数字后剩下的数字过多，直接跳过此次循环
                continue;
            }
            string temp = nums.substr(startIndex, len);
            int IP = stoi(temp); // 截取字符串并转为数字
            if (!(IP >= 0 && IP <= 255)) { // 如果截取的IP不在0~255之间，直接跳过
                continue;
            }
            IPs.push_back(IP);
            traceback(startIndex + len);
            if (IP == 0) { // 如果IP为0，那以它为首就只能截取一个0，否则如果再往后截取就是以0开头
                len = 4;
            }
            IPs.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        this->nums = s;
        traceback(0);
        return result;
    }
};

int main() {

    Solution s;
    vector<string> res = s.restoreIpAddresses("0000");
    cout << 1 << endl;
	return 0;
}
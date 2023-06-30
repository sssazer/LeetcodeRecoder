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
        for (int len = 1; len <= 3; len++) { // ���ֳ������Ϊ3
            if (nums.size() - len - startIndex > 4 * (4 - IPs.size())) { // ���ѡ��һ�����ֺ�ʣ�µ����ֹ��ֱ࣬�������˴�ѭ��
                continue;
            }
            string temp = nums.substr(startIndex, len);
            int IP = stoi(temp); // ��ȡ�ַ�����תΪ����
            if (!(IP >= 0 && IP <= 255)) { // �����ȡ��IP����0~255֮�䣬ֱ������
                continue;
            }
            IPs.push_back(IP);
            traceback(startIndex + len);
            if (IP == 0) { // ���IPΪ0��������Ϊ�׾�ֻ�ܽ�ȡһ��0����������������ȡ������0��ͷ
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
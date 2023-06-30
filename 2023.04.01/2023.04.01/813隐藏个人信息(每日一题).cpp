#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != -1) { // 电子邮件地址
            for (int i = 0; i < s.size(); i++) {
                // 将大写字母全部变为小写
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] += 32;
                }
            }
            s.replace(1, s.find('@') - 2, "*****");
            return s;
        }
        else { // 处理手机号
            string number;
            number.reserve(13);
            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    number.push_back(s[i]);
                }
            }

            switch (number.size()) {
            case 10: // 国家代码为0
                s = "***-***-" + number.substr(number.size() - 4, 4);
                break;
            case 11: // 国家代码为1
                s = "+*-***-***-" + number.substr(number.size() - 4, 4);
                break;
            case 12: // 国家代码为2
                s = "+**-***-***-" + number.substr(number.size() - 4, 4);
                break;
            case 13: // 国家代码为3
                s = "+***-***-***-" + number.substr(number.size() - 4, 4);
                break;
            }
            return s;
        }
    }
};

//int main() {
//    Solution s;
//    string str = s.maskPII("AB@LeetCode.com");
//    cout << str;
//	return 0;
//}
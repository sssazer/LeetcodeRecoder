#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:


    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (string str : queries) {
            int p = 0, s = 0;
            bool flag = true;
            while (p < pattern.size() && s < str.size()) {
                if (pattern[p] == str[s]) {
                    p++, s++;
                }
                else {
                    if (str[s] >= 'A' && str[s] <= 'Z') {
                        break;
                    }
                    s++;
                }
            }
            flag = p >= pattern.size();
            if (!flag) {
                result.push_back(flag);
                continue;
            }
            while (s < str.size()) {
                if (str[s] >= 'A' && str[s] <= 'Z') {
                    flag = false;
                    break;
                }
                s++;
            }
            result.push_back(flag);
        }
        return result;
    }
};

int main() {

    Solution s;
    vector<string> queries = { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
    string pattern = "FoBaT";
    s.camelMatch(queries, pattern);

	return 0;

}
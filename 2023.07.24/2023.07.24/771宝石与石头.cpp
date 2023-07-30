#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> jewHash(52, 0); // 0~25表示a~z，26~51表示A~Z
        for (char jewel : jewels) {
            if (jewel >= 'a') {
                jewHash[jewel - 'a'] = 1;
            }
            else {
                jewHash[jewel - 'A' + 26] = 1;
            }
        }
        int jewNum = 0;
        for (char stone : stones) {
            if (stone >= 'a') {
                jewNum += jewHash[stone - 'a'];
            }
            else {
                jewNum += jewHash[stone - 'A' + 26];
            }
        }
        return jewNum;
    }

    void func1() {

    }
};

int main() {

    Solution s;
    s.numJewelsInStones("aA", "aAAbbbb");

	return 0;
}
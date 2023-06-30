#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(min(a, b), c);
        int z = max(max(a, b), c);
        int y = a ^ b ^ c ^ x ^ z;
        int minOpt = 0, maxOpt = 0;
        if ((y - x) != 1) {
            minOpt++;
            maxOpt += (y - x - 1);
        }
        if ((z - y) != 1) {
            minOpt++;
            maxOpt += (z - y - 1);
        }
        if ((z - y) == 2 || (y - x) == 2) {
            minOpt = 1;
        }
        return {minOpt, maxOpt};
    }
};

//int main() {
//
//    Solution s;
//    s.numMovesStones(1, 2, 3);
//
//	return 0;
//}
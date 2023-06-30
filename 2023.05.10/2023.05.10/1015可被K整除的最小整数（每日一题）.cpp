#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // ( x * 10 + 1) % k = ( x % k * 10 % k + 1) % k; 
        if (k == 1) {
            return 1;
        }
        int x = 1;
        unordered_set<int> set;
        int len = 1;
        int n = 10 % k;
        while (true) {
            x = ((x % k) * n + 1) % k;
            len++;
            if (x == 0) {
                return len;
            }
            if (!set.insert(x).second) {
                return -1;
            }
        }
        return -1;
    }
};

int main() {

	return 0;
}
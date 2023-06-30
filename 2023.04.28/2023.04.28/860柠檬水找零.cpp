#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveNums = 0, tenNums = 0;
        for (auto& i : bills) {
            if (i == 5) { // 付5美元
                fiveNums++;
            }
            else if (i == 10) { // 付10美元
                tenNums++;
                if (fiveNums > 0) {
                    fiveNums--;
                }
                else { 
                    return false;
                }
            }
            else { // 付20美元
                if (tenNums > 0 && fiveNums > 0) { // 有10块的优先找一张10块和一张5块
                    tenNums--;
                    fiveNums--;
                }
                else if (fiveNums >= 3) { // 没有10块的找3张5块
                    fiveNums -= 3;
                }
                else {
                    return false;
                }
            }
        }
		return true;
    }
};

int main() {

	return 0;
}
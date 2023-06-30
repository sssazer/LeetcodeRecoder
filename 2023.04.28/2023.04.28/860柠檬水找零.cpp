#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveNums = 0, tenNums = 0;
        for (auto& i : bills) {
            if (i == 5) { // ��5��Ԫ
                fiveNums++;
            }
            else if (i == 10) { // ��10��Ԫ
                tenNums++;
                if (fiveNums > 0) {
                    fiveNums--;
                }
                else { 
                    return false;
                }
            }
            else { // ��20��Ԫ
                if (tenNums > 0 && fiveNums > 0) { // ��10���������һ��10���һ��5��
                    tenNums--;
                    fiveNums--;
                }
                else if (fiveNums >= 3) { // û��10�����3��5��
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
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countTime(string time) {
        int nums = 1;
        if (time[0] == '?' && time[1] == '?') {
            nums *= 24;
        }
        else {
			if (time[0] == '?') {
                switch (time[1]) {
                case '0':
                case '1':
                case '2':
                case '3':
                    nums *= 3;
                    break;
                default:
                    nums *= 2;
                    break;
                }
			}
			if (time[1] == '?') {
                if (time[0] == '2') {
					nums *= 4;
                }
                else {
                    nums *= 10;
                }
			}
        }
        if (time[3] == '?' && time[4] == '?') {
            nums *= 60;
        }
        else {
			if (time[3] == '?') {
                nums *= 6;
			}
            if (time[4] == '?') {
                nums *= 10;
            }
        }
        return nums;
    }
};

int main() {

	return 0;
}
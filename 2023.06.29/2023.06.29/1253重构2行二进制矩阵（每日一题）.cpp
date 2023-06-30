#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result(2, vector<int>(colsum.size(), 0));
        int originUpper = upper, originLower = lower;
        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 0) {
                continue;
            }
            else if (colsum[i] == 2) {
                result[0][i] = result[1][i] = 1;
                upper--;
                sum0++;
                lower--;
                sum1++;
            }
            else {
                if (upper > 0 && lower > 0) {
                    if (upper > lower) {
                        result[0][i] = 1;
                        upper--;
                        sum0++;
                    }
                    else {
                        result[1][i] = 1;
                        lower--;
                        sum1++;
                    }
                }
                else if (upper > 0) {
                    result[0][i] = 1;
                    upper--;
                    sum0++;
                }
                else if (lower > 0) {
                    result[1][i] = 1;
                    lower--;
                    sum1++;
                }
                else {
                    return {};
                }
            }
            if (upper < 0 || lower < 0) {
                return {};
            }
        }
        if (sum0 == originUpper && sum1 == originLower) {
            return result;
        }
        else {
            return {};
        }
    }
};

//int main() {
//
//	return 0;
//}
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                }
                else if (j == matrix[i].size() - 1) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                }
                else {
                    matrix[i][j] += min(min(matrix[i - 1][j], matrix[i - 1][j - 1]), matrix[i - 1][j + 1]);
                }
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < matrix[matrix.size() - 1].size(); i++) {
            result = min(result, matrix[matrix.size() - 1][i]);
        }
        return result;
    }
};

//int main() {
//
//	return 0;
//}
#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // �Զ�����ֱ���޸�ԭ����
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        int minmum = INT_MAX;
        for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
            minmum = min(minmum, triangle[triangle.size() - 1][i]);
        }
        return minmum;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) { // �ӵ����ڶ���һֱ���ص���һ��
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

int main() {

	return 0;
}
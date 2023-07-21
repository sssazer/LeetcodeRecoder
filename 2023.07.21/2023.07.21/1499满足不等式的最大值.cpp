#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxVal = INT_MIN;
        int left = 0, right = 0;
        while (right < points.size()) {
            while (points[right][0] - points[left][0] <= k) {
                right++;
            }
            left++;
        }
    }
};

int main() {

	return 0;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double, vector<double>, less<double>> pq;
        double sum = 0;
        for (int num : nums) {
            pq.push(num);
            sum += num;
        }
        float half = sum / 2;
        int step = 0;
        while (sum > half) {
            double head = pq.top();
            pq.pop();
            sum -= head / 2;
            pq.push(head / 2);
            step++;
        }
        return step;
    }
};

int main() {

	return 0;
}
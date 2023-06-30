#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

class Solution1 {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        multimap<int, vector<int>, greater<int>> diffs; // key «reward1[i]-reward2[i]£¨value «{i,reward1[i],reward2[i]}
        for (int i = 0; i < reward1.size(); i++) {
            diffs.insert(pair<int, vector<int>>(reward1[i] - reward2[i], {i, reward1[i], reward2[i]}));
        }
        int count = 0;
        int maxReward = 0;
        for (const pair<int, vector<int>>& p : diffs) {
            if (count < k) {
                maxReward += p.second[1];
            }
            else {
                maxReward += p.second[2];
            }
            count++;
        }
        return maxReward;
    }
};

class Solution2 {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> diffs(reward1.size(), 0);
        int sum = 0;
        for (int i = 0; i < reward1.size(); i++) {
            diffs[i] = reward1[i] - reward2[i];
            sum += reward2[i];
        }
        sort(diffs.begin(), diffs.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            sum += diffs[i];
        }
        return sum;
    }
};

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 0; i < reward1.size(); i++) {
            pq.push(reward1[i] - reward2[i]);
            if (pq.size() > k) {
                pq.pop();
            }
            sum += reward2[i];
        }
        while (pq.size()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};

//int main() {
//    Solution s;
//    vector<int> reward1 = { 1, 1, 3, 4 };
//    vector<int> reward2 = { 4, 4, 1, 1 };
//    s.miceAndCheese(reward1, reward2, 2);
//	return 0;
//}
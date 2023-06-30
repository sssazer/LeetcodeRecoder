#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<queue>

using namespace std;

class MyCmp {
public:
    bool operator() (const pair<int, int> p1, const pair<int, int> p2) const {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

class Solution {
public:

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> map; // 记录每个条码出现的次数
        for (int i : barcodes) {
            map[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq;
        for (const pair<int, int> p : map) {
            pq.push(p);
        }
        vector<int> result(barcodes.size(), 0);
        for (int i = 0; i < result.size(); i++) {
            pair<int, int> topPair = pq.top();
            pq.pop();
            if (i > 0 && topPair.first == result[i - 1]) {
                pair<int, int> temp = topPair;
                topPair = pq.top();
                pq.pop();
                pq.push(temp);
            }
            result[i] = topPair.first;
            if (--topPair.second) {
                pq.push(topPair);
            }
        }
        return result;
    }
};

class Solution1 {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> showTimes; // 统计每个条形码出现的次数
        for (int i : barcodes) {
            showTimes[i]++;
        }
        set<pair<int, int>, MyCmp> s(showTimes.begin(), showTimes.end()); // pair<条形码,条形码出现次数>
        vector<int> result(barcodes.size(), 0); // 开始排列条形码
        for (int i = 0; i < result.size(); i++) {
            set<pair<int, int>, MyCmp>::iterator sit = s.begin();
            pair<int, int> p = *sit;
            if (i > 0 && p.first == result[i - 1]) {
                sit++;
                p = *sit;
            }
            result[i] = p.first; // 优先插入剩余最多的条形码
            s.erase(sit); // 把刚刚插入的条形码的出现次数-1并重新插入到正确位置
            if (--p.second) {
                s.insert(p);
            }
        }
        return result;
    }
};

//int main() {
//
//    vector<int> v = { 1,1,1,1,2,2,3,3 };
//    Solution s;
//    s.rearrangeBarcodes(v);
//
//	return 0;
//}
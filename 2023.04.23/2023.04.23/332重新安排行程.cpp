#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> path;
    bool hasRes = false;
    int pathSize = 0;

    bool traceback(unordered_map<string, map<string, int>> &metric, string cur_city) {
        if (path.size() >= pathSize) {
            result = path;
            return true;
        }
        map<string, int> dests = metric[cur_city];
        for (const pair<string, bool> &temp : dests) {
            if (temp.second > 0) { // 如果这条路还能走
			    path.push_back(temp.first);
                metric[cur_city][temp.first]--;
                if(traceback(metric, temp.first)) return true;
                path.pop_back();
                metric[cur_city][temp.first]++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        this->pathSize = tickets.size() + 1;
        // 建立邻接矩阵
        unordered_map<string, map<string, int>> metric; // unordered_map<出发城市,map<目的城市,该机票剩余使用次数>>
        for (vector<string>& vec : tickets) {
            if (metric.find(vec[0]) == metric.end()) { // 如果出发城市未被收录
                metric[vec[0]] = map<string, int>();
                metric[vec[0]].insert(make_pair(vec[1], 1));
                continue;
            }
            else if(metric[vec[0]].find(vec[1]) == metric[vec[0]].end()){ // 如果出发城市被收录，但是目的地未被收录
                metric[vec[0]].insert(make_pair(vec[1], 1));
                continue;
            }
            metric[vec[0]][vec[1]]++;
        }
        path.push_back("JFK");
        traceback(metric, "JFK");
        return result;
    }
};

//int main() {
//
//    Solution s;
//    vector<vector<string>> tickets1 = { {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"} };
//    vector<vector<string>> tickets = { {"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"} };
//    s.findItinerary(tickets);
//
//	return 0;
//}
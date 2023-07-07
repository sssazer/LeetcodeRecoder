#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
};

class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time)
    {
        unordered_map<int, int> map;                                            // <工人序号，工人的效率>
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> left_wait;  // 河左岸的等待队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> right_wait; // 河右岸的等待队列
        unordered_map<int, int> left_work;                                      // 左岸的工作序列<工人序号，完工的时间>
        unordered_map<int, int> right_work;                                     // 右岸的工作序列<工人序号，完工的时间>
        for (int i = 0; i < time.size(); i++)
        {
            map[i] = time[i][0] + time[i][2];
        }
        for (const pair<int, int> &p : map)
        { // 初始时所有工人在左岸等待
            left_wait.push(p);
        }
        int currentTime = 0;
        int remainBox = n;
        while (remainBox)
        {
            if (!left_work.empty())
            { // 先检查左边有没有工人完成工作，如果有的话加入左岸等待队列
                for (unordered_map<int, int>::iterator lwit = left_work.begin(); lwit != left_work.end();)
                {
                    if (lwit->second <= currentTime)
                    {
                        left_wait.push(make_pair(lwit->first, map[lwit->first]));
                        lwit = left_work.erase(lwit);
                    }
                    else
                    {
                        lwit++;
                    }
                }
            }
            if (!right_work.empty())
            { // 检查右边有没有工人完成工作，如果有的话加入右岸等待队列
                for (unordered_map<int, int>::iterator lwit = right_work.begin(); lwit != right_work.end();)
                {
                    if (lwit->second <= currentTime)
                    {
                        right_wait.push(make_pair(lwit->first, map[lwit->first]));
                        lwit = right_work.erase(lwit);
                        remainBox--; // 从右边搬起一个箱子
                    }
                    else
                    {
                        lwit++;
                    }
                }
            }
            if (!right_wait.empty())
            {                                                   // 优先让桥右边等待的工人过桥
                currentTime += time[right_wait.top().first][2]; // 时间转移到工人过桥后
                // 工人从右边过桥到左边之后直接去左边放箱子
                left_work.insert(make_pair(right_wait.top().first, currentTime + time[right_wait.top().first][3]));
                right_wait.pop();
            }
            else if (remainBox > right_work.size() && !left_wait.empty())
            { // 右边没人过桥并且右边还剩箱子再让左侧的工人过桥
                currentTime += time[left_wait.top().first][0];
                right_work[left_wait.top().first] = currentTime + time[left_wait.top().first][1];
                left_wait.pop();
            }
            else
            {
                // 如果两边都没有工人等待 或者 在右边的工人已经足够把右边仓库搬空(不用工人再从左边过桥到右边)
                // 时间就跳转到所有工人中最早完成工作去等待的那个工人的时间
                int minTime = INT32_MAX;
                for (auto &p : left_work)
                {
                    minTime = min(minTime, p.second);
                }
                for (auto &p : right_work)
                {
                    minTime = min(minTime, p.second);
                }
                currentTime = minTime;
            }
        }
        while (!right_wait.empty())
        { // 当所有箱子都被搬出右边仓库之后，只需要让所有在右边等待队列的工人过河即可
            currentTime += right_wait.top().second;
            right_wait.pop();
        }
        return currentTime;
    }
};

int main(){

    Solution s;
    vector<vector<int>> time = {
        {1,9,1,8},
        {10,10,10,10}
    };
    cout << s.findCrossingTime(3, 2, time);
    return 0;
}
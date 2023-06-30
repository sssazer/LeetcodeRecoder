#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    unordered_map<int, int> pos; // �ֱ��¼ÿ�еĻʺ����ʲôλ��, unordered_map<col, row>

    void traceback(int n, int curRow) { // curRow������Ҫ�ڵڼ��зŻʺ�
        if (curRow >= n) {
            // �ҵ�һ�ַŷ�������pos�������
            vector<string> oneRes(n, "");
            for (const pair<int, int> p : pos) {
                string temp(n, '.');
                temp[p.first] = 'Q';
                oneRes[p.second] = temp;
            }
            result.push_back(oneRes);
            return;
        }
        for (int i = 0; i < n; i++) { // �ڱ����У����ʺ�ֱ����ÿ��λ��
            bool canPut = true; // ��ʾ��λ���ܷ�Żʺ�
            if (pos.find(i) != pos.end()) { // ��������Ѿ���һ���ʺ󣬾Ͳ����ٷŻʺ�
                continue;
            }
            for (const pair<int, int> p : pos) { // ���֮ǰÿһ���еĻʺ󣬿��Ƿ��лʺ��뵱ǰλ����ͬһб����
                if (abs(i - p.first) == abs(curRow - p.second)) { // �������ͬһб���ϣ����λ�þͲ����ٷŻʺ�
                    canPut = false;
                    break;
                }
            }
            if (canPut) { // ������λ���ܷŻʺ�
                unordered_map<int, int>::iterator pit = pos.insert(make_pair(i, curRow)).first;
                traceback(n, curRow + 1);
                pos.erase(pit);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        traceback(n, 0);
        return result;
    }
};

//int main() {
//
//	return 0;
//}
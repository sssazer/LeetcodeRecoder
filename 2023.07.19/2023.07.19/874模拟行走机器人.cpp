#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0; // x,y��¼�����˵�ǰ����
        int maxDis = 0;
        unordered_map<int, vector<int>> xRow;
        unordered_map<int, vector<int>> yCol;
        for (vector<int>& v : obstacles) {
            if (xRow.find(v[0]) != xRow.end()) {
                xRow[v[0]].push_back(v[1]);
            }
            else {
                xRow[v[0]] = {v[1]};
            }
            if (yCol.find(v[1]) != yCol.end()) {
                yCol[v[1]].push_back(v[0]);
            }
            else {
                yCol[v[1]] = {v[0]};
            }
        }
        int orintation = 0; // 0��ʾ����1��ʾ����2��ʾ�ϣ�3��ʾ��   ��0
                            //                                 ��3       ��1
                            //                                      ��2
        for (int i : commands) {
            if (i > 0) { // ���ݵ�ǰ��������
                switch (orintation) {
                case 1: // ������
                    if (yCol.find(y) != yCol.end()) { // �����Ҫ���ߵ�ˮƽ���ϴ����ϰ�
                        int obstruction = 100000;
                        for (int pos : yCol[y]) {
                            if (pos > x && pos <= x + i) { // ����ϰ������ڱ���Ҫ������·��
                                if (pos < obstruction) { // ��Ҫ��֤�ҵ��뵱ǰλ��������Ǹ��ϰ�
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // ���ϰ��Ļ���ͣ���ϰ�ǰһ��
                            x = obstruction - 1;
                            break;
                        }
                    }
                    x += i;
                    break;
                case 0: // ������
                    if (xRow.find(x) != xRow.end()) { // �����Ҫ���ߵ�ˮƽ���ϴ����ϰ�
                        int obstruction = 100000;
                        for (int pos : xRow[x]) {
                            if (pos > y && pos <= y + i) { // ����ϰ������ڱ���Ҫ������·��
                                if (pos < obstruction) { // ��Ҫ��֤�ҵ��뵱ǰλ��������Ǹ��ϰ�
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // ���ϰ��Ļ���ͣ���ϰ�ǰһ��
                            y = obstruction - 1;
                            break;
                        }
                    }
                    y += i;
                    break;
                case 3: // ������
					if (yCol.find(y) != yCol.end()) { // �����Ҫ���ߵ���ֱ���ϴ����ϰ�
                        int obstruction = 100000;
                        for (int pos : yCol[y]) {
                            if (pos < x && pos >= x - i) { // ����ϰ������ڱ���Ҫ������·��
                                if (pos < obstruction) { // ��Ҫ��֤�ҵ��뵱ǰλ��������Ǹ��ϰ�
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // ���ϰ��Ļ���ͣ���ϰ�ǰһ��
                            x = obstruction + 1;
                            break;
                        }
                    }
                    x -= i;
                    break;
                case 2: // ������
                    if (xRow.find(x) != xRow.end()) { // �����Ҫ���ߵ�ˮƽ���ϴ����ϰ�
                        int obstruction = 100000;
                        for (int pos : xRow[x]) {
                            if (pos < y && pos >= y - i) { // ����ϰ������ڱ���Ҫ������·��
                                if (pos < obstruction) { // ��Ҫ��֤�ҵ��뵱ǰλ��������Ǹ��ϰ�
                                    obstruction = pos;
                                }
                            }
                        }
                        if (obstruction != 100000) { // ���ϰ��Ļ���ͣ���ϰ�ǰһ��
                            y = obstruction + 1;
                            break;
                        }
                    }
                    y -= i;
                    break;
                }
            }
            else { // ת��
                if (i == -1) {
                    orintation = (orintation + 1) % 4;
                }
                else {
                    orintation = (orintation + 3) % 4;
                }
            }
            maxDis = max(maxDis, x * x + y * y);
        }
        return maxDis;
    }
};

int main() {

	return 0;
}
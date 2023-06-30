#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int result;
    // ���ص�ǰ�ڵ��״̬��0 --> �޸��� ��1 --> �и��� ��2 --> ������ͷ 
    int lastOrder(TreeNode *root) {
        if (!root) {
            return 1;
        }
        int leftStatus = lastOrder(root->left);
        int rightStatus = lastOrder(root->right);
        if (leftStatus == 0 || rightStatus == 0) { // �����һ������û�б����ǣ����������Ҫ����һ������ͷ
            result++;
            return 2;
        }
        if (leftStatus == 1 && rightStatus == 1) { // ����������Ӷ������ǲ��Ҷ�û������ͷ����������һ��û�б�����
            return 0;
        }
        if (leftStatus == 2 || rightStatus == 2) { // �����һ�����Ӱ�������ͷ���Ǹý��һ��������
            return 1;
        }
        return 100; // ��ʵ�����Ѿ�������������������������һ��return����������

    }
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (lastOrder(root)) result++;
        return result;
    }
};

//int main() {
//
//	return 0;
//}
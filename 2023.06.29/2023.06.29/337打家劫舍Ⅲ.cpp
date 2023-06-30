#include<iostream>
#include<vector>

using namespace std;

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
    int rob(TreeNode* root) {
        vector<int> res = robTest(root);
        return max(res[0], res[1]);
    }
    vector<int> robTest(TreeNode* root) { // ���� {��͵�ýڵ�õ�������͵�ý��õ��������}
        if (!root) {
            return { 0, 0 };
        }
        vector<int> left = robTest(root->left); // ��ȡ��ڵ�͵�벻͵�����ֵ
        vector<int> right = robTest(root->right); // ��ȡ�ҽڵ�͵�벻͵�����ֵ

        int stole = root->val + left[0] + right[0]; // ���͵���ڵ㣬�����Һ��ӽڵ㶼����͵
        int notStole = max(left[0], left[1]) + max(right[0], right[1]); // �����͵���ڵ㣬�����Һ������͵

        return {notStole, stole};
    }
};

//int main() {
//
//	return 0;
//}
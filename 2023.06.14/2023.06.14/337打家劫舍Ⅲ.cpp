#include<iostream>
#include<vector>
#include<unordered_map>

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
    unordered_map<TreeNode*, int> mmap; // ��ʾ��TreeNodeΪ���ڵ�����������͵����Ǯ
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (mmap.find(root) != mmap.end()) {
            return mmap[root];
        }
        int max1 = 0; // ��͵��ǰroot�ڵ�
        max1 = rob(root->left) + rob(root->right);

        int max2 = root->val; // ͵��ǰroot�ڵ�
        if (root->left) max2 += rob(root->left->left) + rob(root->left->right);
        if (root->right) max2 += rob(root->right->left) + rob(root->right->right);

        mmap[root] = max(max1, max2);
        return max(max1, max2);
    }
};

int main() {

	return 0;
}
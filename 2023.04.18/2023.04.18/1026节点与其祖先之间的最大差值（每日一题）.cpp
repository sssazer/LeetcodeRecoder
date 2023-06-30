#include<iostream>
#include<vector>
#include<set>
#include<functional>

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

    multiset<int> ancestorsSmall;
    int maxDiff = 0;
    multiset<int, greater<int>> ancestorsBig;

    void preOrder(TreeNode* root) {
        maxDiff = max(maxDiff, abs(*ancestorsSmall.begin() - root->val));
        maxDiff = max(maxDiff, abs(*ancestorsBig.begin() - root->val));
        multiset<int>::iterator sitS = ancestorsSmall.insert(root->val);
        multiset<int>::iterator sitB = ancestorsBig.insert(root->val);
        if (root->left) {
            preOrder(root->left);
        }
        if (root->right) {
            preOrder(root->right);
        }
        ancestorsSmall.erase(sitS);
        ancestorsBig.erase(sitB);
    }

    int maxAncestorDiff(TreeNode* root) {
        preOrder(root);
        return maxDiff;
    }
};

//int main() {
//
//    TreeNode* root = new TreeNode(1);
//    Solution s;
//    s.maxAncestorDiff(root);
//
//	return 0;
//}
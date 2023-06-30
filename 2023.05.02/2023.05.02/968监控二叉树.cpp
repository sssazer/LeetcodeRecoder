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
    // 返回当前节点的状态：0 --> 无覆盖 ，1 --> 有覆盖 ，2 --> 有摄像头 
    int lastOrder(TreeNode *root) {
        if (!root) {
            return 1;
        }
        int leftStatus = lastOrder(root->left);
        int rightStatus = lastOrder(root->right);
        if (leftStatus == 0 || rightStatus == 0) { // 如果有一个孩子没有被覆盖，那这个结点就要安上一个摄像头
            result++;
            return 2;
        }
        if (leftStatus == 1 && rightStatus == 1) { // 如果两个孩子都被覆盖并且都没安摄像头，那这个结点一定没有被覆盖
            return 0;
        }
        if (leftStatus == 2 || rightStatus == 2) { // 如果有一个孩子安了摄像头，那该结点一定被覆盖
            return 1;
        }
        return 100; // 其实上面已经覆盖了所有情况，但是这里放一个return避免编译错误

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
/**
 * 543. 二叉树的直径
 * 直径：任意两节点间最长路径的边数
 * 核心：直径 = 左子树深度 + 右子树深度，DFS 后序遍历同时维护全局最大值
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        depth(root, ans);
        return ans;
    }

private:
    int depth(TreeNode* node, int& ans) {
        if (!node) return 0;
        int L = depth(node->left, ans);
        int R = depth(node->right, ans);
        ans = max(ans, L + R);  // 当前节点的直径 = 左右深度之和
        return max(L, R) + 1;   // 返回当前节点为根的深度
    }
};

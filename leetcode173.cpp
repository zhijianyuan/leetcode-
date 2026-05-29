#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    // 你需要一个栈来模拟递归的调用栈
    stack<TreeNode*> p;

public:
    BSTIterator(TreeNode* root) {
        // 初始化：沿着根节点的左链走到底，沿途节点全部压栈
        while(root!=nullptr){
            p.push(root);
            root = root->left;
        }
    }
    
    int next() {
        // 1. 弹出栈顶节点，这就是当前要返回的值
        TreeNode*q = p.top();
        p.pop();
        int t = q->val;
        // 2. 把这个节点的右子树的左链全部压栈（为后续做准备）
        q = q->right;
        while(q!=nullptr){
            p.push(q);
            q = q->left;
        }
        // 3. 返回节点值
        return t;
    }
    
    bool hasNext() {
        // 栈非空就说明还有节点
        return !p.empty();
    }
};

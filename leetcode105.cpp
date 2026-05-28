#include <vector>
#include <unordered_map>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * ============ 从前序+中序遍历构造二叉树 ============
 *
 * 【核心信息】
 *   前序 (preorder): 根→左→右  →  第一个元素必是根
 *   中序 (inorder) : 左→根→右  →  根的左侧是左子树，右侧是右子树
 *
 * 【推导步骤】
 *   1. 取 preorder[0] 作为根
 *   2. 在 inorder 中找到根的位置 mid，左边即左子树中序，右边即右子树中序
 *   3. leftSize = mid - inStart          → 左子树有多少个节点
 *   4. 用 leftSize 在 preorder 中切出左右子树的前序
 *
 * 【切分规则】（设 ps=preStart, is=inStart）
 *   ┌──────────┬────────────────────┬─────────────────────────────┐
 *   │          │      左子树         │         右子树               │
 *   ├──────────┼────────────────────┼─────────────────────────────┤
 *   │ preorder │ [ps+1, ps+leftSize] │ [ps+leftSize+1, preEnd]     │
 *   │ inorder  │ [is, mid-1]         │ [mid+1, inEnd]              │
 *   └──────────┴────────────────────┴─────────────────────────────┘
 *
 * 【通用模板】适用于同类题 (106, 889 等)：
 *   ① 明确数组代表哪棵子树的哪种遍历
 *   ② 定位根节点
 *   ③ 在另一数组中切出左右子树大小
 *   ④ 用大小反推另一数组的切分点
 *   ⑤ 递归
 *
 * 时间 O(n)  空间 O(n)（哈希表 + 递归栈）
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                int preStart, int preEnd,
                int inStart, int inEnd, 
                unordered_map<int, int>& mp){
                    if(preStart > preEnd) return nullptr;
                    int rootVal = preorder[preStart];
                    TreeNode* root = new TreeNode(rootVal);
                    
                    int mid = mp[rootVal];
                    int leftSize = mid - inStart;

                    root->left = build(preorder,inorder,preStart+1,preStart+leftSize,inStart,mid-1,mp);
                    root->right = build(preorder,inorder,preStart+leftSize+1,preEnd,mid+1,inEnd,mp);
                    
                    return root;
                }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
    }
};
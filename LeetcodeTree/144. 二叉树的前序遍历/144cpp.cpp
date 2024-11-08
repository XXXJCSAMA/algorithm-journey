#include <bits/stdc++.h>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 动态规划思路
    // 定义：输入一个节点，返回以该节点为根的二叉树的前序遍历结果
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        // 前序遍历结果特点：第一个是根节点的值，接着是左子树，最后是右子树
        res.push_back(root->val);
        
        // 递归处理左子树和右子树
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        // 合并左子树和右子树的遍历结果
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
};

// 这里是一个简单的树构造函数，你可以根据需要修改输入输出的方式
TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // 读取左子节点
        cin >> val;
        if (val != -1) {
            node->left = new TreeNode(val);
            q.push(node->left);
        }

        // 读取右子节点
        cin >> val;
        if (val != -1) {
            node->right = new TreeNode(val);
            q.push(node->right);
        }
    }

    return root;
}

int main() {
    Solution solution;

    // 构建树
    TreeNode* root = buildTree();

    // 获取前序遍历结果
    vector<int> result = solution.preorderTraversal(root);

    // 输出前序遍历结果
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}


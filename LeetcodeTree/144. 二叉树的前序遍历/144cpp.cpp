#include <bits/stdc++.h>
using namespace std;

// ����������ڵ�
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
    // ��̬�滮˼·
    // ���壺����һ���ڵ㣬�����Ըýڵ�Ϊ���Ķ�������ǰ��������
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        // ǰ���������ص㣺��һ���Ǹ��ڵ��ֵ���������������������������
        res.push_back(root->val);
        
        // �ݹ鴦����������������
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        // �ϲ����������������ı������
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
};

// ������һ���򵥵������캯��������Ը�����Ҫ�޸���������ķ�ʽ
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

        // ��ȡ���ӽڵ�
        cin >> val;
        if (val != -1) {
            node->left = new TreeNode(val);
            q.push(node->left);
        }

        // ��ȡ���ӽڵ�
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

    // ������
    TreeNode* root = buildTree();

    // ��ȡǰ��������
    vector<int> result = solution.preorderTraversal(root);

    // ���ǰ��������
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}


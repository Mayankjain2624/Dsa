/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "#";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                s += "#,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

 
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;

        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

      
            if (getline(ss, val, ',')) {
                if (val != "#") {
                    current->left = new TreeNode(stoi(val));
                    q.push(current->left);
                }
            }

            if (getline(ss, val, ',')) {
                if (val != "#") {
                    current->right = new TreeNode(stoi(val));
                    q.push(current->right);
                }
            }
        }

        return root;
    }
};

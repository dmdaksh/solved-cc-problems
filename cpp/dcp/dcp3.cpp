#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "null";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserialize_ss(ss);
    }
    
    TreeNode* deserialize_ss(istringstream &ss) {
        string s_val;
        ss>>s_val;
        if(s_val == "null") return NULL;
        
        TreeNode* node = new TreeNode(stoi(s_val));
        node->left = deserialize_ss(ss);
        node->right = deserialize_ss(ss);
        
        return node;
    }
};

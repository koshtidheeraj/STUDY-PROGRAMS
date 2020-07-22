int main() {
    // Pass root node to "balanced_Tree" function. 
    bool is_tree_balanced = balanced_tree(root);
}

balanced_Tree(node* root) {
    if(root == nullptr) {
        cout << "tree does not exist" << endl;
        return false;
    }
    left_height = height(root->left);
    right_height = height(root->right);
    if (left_height != right_height) {
        cout << "not balanced tree" << endl;
        return false;
    } else {
        cout << "balanced tree" << endl;
        return true;
    }
}

int height (node* cur_node) {
    if(cur_node = nullptr)
        return 0;
    else {
        left_height = height(cur_node->left);
        right_height = height(cur_node->right);
        if (left_height > right_height) {
            return (1+left_height);
        } else {
            return (1+right_height);
        }
    }
}
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
// void solve(Node* root , vector<int>& arr){

//     if(root == NULL){
//         return ;
//     }


//     arr.push_back(root->val);

//     for(Node* child : root->children){
//         solve(child , arr);
//     }
// }
    vector<int> preorder(Node* root) {
        // vector<int> arr;
        // solve(root, arr);

        // return arr;

         vector<int> ans;
        stack<Node*> st;
        st.push(root);
        if (root == nullptr)
            return ans;

        while (!st.empty()) {
            root = st.top();
            ans.push_back(root->val);
            st.pop();
            for (int i = root->children.size() - 1; i >= 0; i--) {
                st.push(root->children[i]);
            }
        }
        return ans;
    }
};

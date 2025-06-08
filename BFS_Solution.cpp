/**
 * Definition for a binary tree node.
 */
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
    // Maps each node to its neighbors (undirected graph), collects leaf nodes
    void mapping(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& mp, unordered_set<TreeNode*>& leafnodes) {
        if (!root) return;

        // Create bidirectional connections between parent and children
        if (root->left) {
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
            mapping(root->left, mp, leafnodes);
        }
        if (root->right) {
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
            mapping(root->right, mp, leafnodes);
        }

        // If node is a leaf, add to leaf set
        if (!root->left && !root->right) {
            leafnodes.insert(root);
        }
    }

    // Counts valid leaf node pairs within given distance using BFS
    int paircalculation(TreeNode* root, int& distance, unordered_map<TreeNode*, vector<TreeNode*>>& mp, unordered_set<TreeNode*>& leafnodes, int& pairs) {
        for (auto p = leafnodes.begin(); p != leafnodes.end(); p++) {
            TreeNode* source = *p;
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;

            visited.insert(source);
            q.push(source);
            int level = 1;

            // Perform BFS from current leaf node
            while (!q.empty()) {
                int n = q.size();
                while (n--) {
                    TreeNode* top = q.front();
                    q.pop();

                    for (TreeNode* neighbor : mp[top]) {
                        if (visited.count(neighbor)) continue;

                        q.push(neighbor);
                        visited.insert(neighbor);

                        // If neighbor is a different leaf node within distance
                        if (leafnodes.count(neighbor) && neighbor != *p) {
                            pairs++;
                        }
                    }
                }
                level++;
                if (level > distance) break;
            }
        }
        return pairs;
    }

    // Main function to count valid leaf node pairs
    int countPairs(TreeNode* root, int& distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        unordered_set<TreeNode*> leafnodes;
        int pairs = 0;

        // Build undirected graph and collect leaf nodes
        mapping(root, mp, leafnodes);

        // Count valid pairs (each counted twice, hence divide by 2)
        int totalPairs = paircalculation(root, distance, mp, leafnodes, pairs);
        return totalPairs / 2;
    }
};

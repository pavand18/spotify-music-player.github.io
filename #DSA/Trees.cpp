#include<bits/stdc++.h>
using namespace std; 

// ************************************************************************

// FREE KA TREE SERIES ...

// ************************************************************************

// >>> Binary Tree Representation in cpp <<<

Struct Node{
    int data;
    Struct Node *left;
    Struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main(){
    Struct Node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
}

// ************************************************************************

// >>> BT traversals ..<<<

1. dfs : pre , inorder , post ...
2. bfs : level wise traversal ...

// ************************************************************************

>>> preorder traversal <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* node, vector<int> &ans)
    {
        if(node==NULL) return;

        ans.push_back(node->val);
        func(node->left,ans);
        func(node->right,ans);
    }
  
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root,ans);
        return ans;
    }
};

// ************************************************************************

>>> inorder traversal <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode *node, vector<int> &ans)
    {
        if(node==NULL) return;

        func(node->left,ans);
        ans.push_back(node->val);
        func(node->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root,ans);
        return ans;
    }
};


// ************************************************************************

>>> L7.postorder traversal <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursion

class Solution {
public:
    
    void func(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL) return;
        
        func(root->left,ans);
        func(root->right,ans);
        ans.push_back(root->val);

    }
        
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root,ans);
        return ans;
    }
};

// ************************************************************************

>>> L8. bfs : level order traversal <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            for(int i=0;i<sz;++i)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }           
};

// ************************************************************************
>> ###. ITERATIVE TRAVERSALS <<
// ************************************************************************

>>> L9.PREORDER <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==NULL) return ans;

        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);

            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left); 
        }
        return ans;
    }
};

// ************************************************************************

>>> L10.inorder <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==NULL) return ans;

        while(1)
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                if(st.empty()) break;
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};

// ************************************************************************

>>> L11.postorder : 2 stack <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<int> ans;
        if(root==NULL) return ans;

        st1.push(root);
        while(!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL) st1.push(root->left);
            if(root->right != NULL) st1.push(root->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

// ************************************************************************

>>> L12.postorder : 1 stack <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        TreeNode* curr = root;
        TreeNode* temp;
        if(root==NULL) return ans;
        while(curr!=NULL || !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                temp=st.top()->right;
                if(temp==NULL)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty()&&temp==st.top()->right)
                    {
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    curr=temp;
                }
            }
        }
        return ans;
    }
};

// ************************************************************************

>>> L13.All in one traversals <<<

#include <bits/stdc++.h> 
/**
    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> in,pre,post;
    
    if(root==NULL) return ans;
    stack<pair<BinaryTreeNode<int>*,int>> st;
    st.push({root,1});
    
    while(!st.empty())
    {
        if(st.top().second==1)
        {
            pre.push_back(st.top().first->data);
            BinaryTreeNode<int> *node = st.top().first;
            st.pop();
            st.push({node,2});
            if(node->left!=NULL) st.push({node->left,1});
        }
        if(st.top().second==2)
        {
            in.push_back(st.top().first->data);
            BinaryTreeNode<int> *node = st.top().first;
            st.pop();
            st.push({node,3});
            if(node->right!=NULL) st.push({node->right,1});
        }
        if(st.top().second==3)
        {
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
    
}

// ************************************************************************

>>> L14.max Depth <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }
};

// ************************************************************************

>>> L15. balanced bt <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(root==NULL) return 0;

        int lh = maxDepth(root->left);
        if(lh==-1) return -1;
        int rh = maxDepth(root->right);
        if(rh==-1) return -1;

        if(abs(lh-rh) > 1 ) return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        if(maxDepth(root)==-1) return false;
        return true;
    }
};

// ************************************************************************

>>> L16.Diameter of bt <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int func(TreeNode* root,int &maxi)
    {
        if(root==NULL) return 0;

        int lh = func(root->left,maxi);
        int rh = func(root->right,maxi);

        // it keeps record of max. of height of all traverse node...
        maxi = max(maxi,lh+rh);
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        func(root,maxi);
        return maxi;
    }
};

// ************************************************************************

>>> L17.Maximum path sum <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root,int &maxi)
    {
        if(root==NULL) return 0;

        int lh = max(0,maxDepth(root->left,maxi));
        int rh = max(0,maxDepth(root->right,maxi));

        maxi = max(maxi, root->val+lh+rh); 
        return root->val + max(lh,rh);
    }    

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxDepth(root,maxi);
        return maxi;
    }
};

// ************************************************************************

>>> L18.Same Tree <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL^q==NULL) return false;
        if(p==NULL && q==NULL) return true;
        
        if(p->val != q->val) return false;

        if(isSameTree(p->left,q->left) != true) return false;
        if(isSameTree(p->right,q->right) != true) return false;

        return true;
    }
};

// ************************************************************************

>>> L19.zig zig traversal in bt <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        
        q.push(root);
        int z=1;

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            z=z^1;  //z==0;
            for(int i=0;i<sz;++i)
            {
                root = q.front();
                q.pop();
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL) q.push(root->right);
                level.push_back(root->val);
            } 
            if(z==1) reverse(level.begin(),level.end()); 
            ans.push_back(level);
        }

        return ans;
    }
};

// ************************************************************************

>>> L20.Boundary level traversal in bt <<<

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* node)
{
    if(!node->right&&!node->left) return true;
    return false;
}

void Left(TreeNode<int>* root, vector<int> &ans)
{
    TreeNode<int>* curr = root->left;
    while(curr)
    {
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}
void Right(TreeNode<int>* root,vector<int>& ans)
{
    TreeNode<int>* curr = root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;--i)
    {
        ans.push_back(temp[i]);
    }
}

void Leaf(TreeNode<int>* root,vector<int>& ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left) Leaf(root->left,ans);
    if(root->right) Leaf(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    Left(root,ans);
    Leaf(root,ans);
    Right(root,ans);
    return ans;
}

// ************************************************************/

>>> L21.Vertical order Traversal <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
// this gives all nodes at x,y in sorted order...
            nodes[x][y].insert(node->val);
            if(node->left) 
            {
                q.push({node->left,{x-1,y+1}});
            } 
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans; 
        for(auto p:nodes)
        {
            vector<int> temp;
            for(auto it:p.second)
            {
                for(auto itt:it.second)
                {
                    temp.push_back(itt);
                }
            } 
            ans.push_back(temp);  
        }
        return ans;
    }
};

// ************************************************************/

>>> L22.Top View of bt <<<

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
simpler version of vertical order traversal ...

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,map<int,multiset<int>>> nodes; //vert. level. node...
    queue<pair<TreeNode<int>*,pair<int,int>>> q; //node..vert(x)..level(y)..
    
    vector<int> fans;
    if(root==NULL) return fans;
    q.push({root,{0,0}});
    
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int>* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val); //inserting values in multiset...
        
        if(node->left) q.push({node->left,{x-1,y+1}});
        if(node->right) q.push({node->right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto p:nodes)
    {
        //searching in verticals...
        vector<int> temp;
        for(auto q:p.second)
        {
            for(auto it:q.second) //multiset..
            {
                temp.push_back(it);
            }
        }
        ans.push_back(temp);
    }
    
    
    for(auto it:ans)
    {
        if(it.size()>0) fans.push_back(it[0]);
    }
    return fans;
}

// ************************************************************/

>>> L23.Bottom view of bt <<<

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    map<int,int>mp;
    if(root==NULL) return  ans;
    q.push({root,0});
    
    while(!q.empty())
    {
        auto xx = q.front();
        q.pop();
        BinaryTreeNode<int>* node = xx.first;
        int vert = xx.second;
        mp[vert] = node->data;
        
        if(node->left) q.push({node->left,vert-1});
        if(node->right) q.push({node->right,vert+1});
    } 
    
    for(auto it:mp)
    {
        ans.push_back(it.second);
    } 
    return ans;
}

// ************************************************************/

>>> L24. Left or right view of bt <<<

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<vector<int>> ans;
    vector<int> fans;
    queue<TreeNode<int>*> q;
    if(!root) return fans;
    q.push(root);
    
    while(!q.empty())
    {
        int sz = q.size();
        vector<int> lvl;
        for(int i=0;i<sz;++i)
        {
            TreeNode<int>* node = q.front();
            q.pop();
            lvl.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(lvl);
    }
    for(auto it:ans)
    {
        if(it.size()>0) fans.push_back(it[0]);
    }
    return fans;
}

// ************************************************************/

>>> L25. check for symetrical bt <<<

$$$ using simple bfs and checking 
if each level are symetric or not ...

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool bfs(TreeNode* root)
    {
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> lvl;
            for(int i=0;i<sz;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node==NULL) lvl.push_back(INT_MIN);
                else
                {
                    lvl.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            for(auto it:lvl) cout<<it<<" ";
            cout<<endl;

            if(lvl.size()!=1&&lvl.size()%2==1) return false;

            for(int i=0;i<lvl.size()/2;++i)
            {
                if(lvl[i]==lvl[lvl.size()-1-i]) continue;
                else return false;
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(bfs(root)) return true;
        return false;
    }
};

$$$$ MENTOS APPROACH .. : not able to 
execute the code ...

// ************************************************************/

>>> L26.print path : from root to given node <<<

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool func(TreeNode* root,vector<int>& ans,int x)
{
    if(!root) return ans;
    ans.push_back(root->val);

    if(root->val==x) return true;

    if(func(root->left,ans,x)) return true;
    if(func(root->right,ans,x)) return true;

    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL) return ans;
    func(A,ans,B);  //once it has return any value...
    // then this functionn will be terminated and 
    // next line will  be executed...
    return ans;
}

// ************************************************************/

>>> L27.LCA in bt <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool ffunc(TreeNode* root,TreeNode* p,vector<TreeNode*> &fans)
    {
        if(root==NULL) return false;
        fans.push_back(root);
        if(root->val==p->val) return true;

        if(ffunc(root->left,p,fans)) return true;
        if(ffunc(root->right,p,fans)) return true;

        fans.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> fans,sans;
        ffunc(root,p,fans);
        ffunc(root,q,sans);
        // for(auto it:fans) cout<<it<<" "; cout<<endl;
        // for(auto it:sans) cout<<it<<" "; cout<<endl;
        // return root;
        TreeNode* node;
        for(int i=0;i<min(fans.size(),sans.size());++i)
        {
            if(fans[i]==sans[i])
            {
                node = fans[i];
            }
            else break;
        }
        return node;
    }
};
 
$$$$ Mentos Approach $$$$

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;  
    }
};

// ************************************************************/

>>> L28.maximum width of bt <<<
12:14 - 1:04

$$$$ brute force : $$$$
// difficult to implement ...

$$$$ mentos approach : $$$$

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        if(root==NULL) return 0;
        q.push({root,0});
        long long ans =0;

        while(!q.empty())
        {
            int sz = q.size();
            long long mini = q.front().second;
            // long long 
            long long  first=0,last=0;
            for(int i=0;i<sz;++i)
            {
                long long currlvl = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = currlvl;
                if(i==sz-1) last = currlvl;
                if(node->left) q.push({node->left,2*currlvl+1ll});
                if(node->right) q.push({node->right,2*currlvl+2ll});

                
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};

// ************************************************************/

>>> L29.children sum property in bt <<<

1:04 - 2:04

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL) return;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    
    if(child>=root->data) root->data = child;
    else
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int tot = 0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left||root->right) root->data = tot;
    
}  

// ************************************************************/

>>> L30.All nodes at distance k <<<

3:45 - 6:45..

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(unordered_map<TreeNode*,TreeNode*> &par,TreeNode* root,TreeNode* target)
    {
        if(root==NULL) return;
        if(root->left) 
        {
            par[root->left]=root;
        }
        if(root->right) 
        {
            par[root->right]=root;
        }

        parent(par,root->left,target);
        parent(par,root->right,target);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        parent(par,root,target);
        vector<int> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int lvl=0;

        while(!q.empty())
        {
            int sz=q.size();
            if(lvl==k) break;
            ++lvl;
            for(int i=0;i<sz;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left&&vis.count(node->left)==0) 
                {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right&&vis.count(node->right)==0)  
                {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(par[node]&&vis.count(par[node])==0)          
                {                                       
                    q.push(par[node]);
                    vis.insert(par[node]);
                } 
            }
        }
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        } 
        return ans;
    }
};

// ************************************************************/

>>> L31.Min time required to burn the bt <<<

rewatch the video again then reattempt the q...

// ************************************************************/

>>> L32.count total nodes in complete bt <<<

8:20 - 10:20

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int lhght(TreeNode* node)
    {
        int hght=0;
        while(node)
        {
            ++hght;
            node=node->left;
        }
        return hght;
    }
    int rhght(TreeNode* node)
    {
        int hght=0;
        while(node)
        {
            ++hght;
            node=node->right;
        }
        return hght;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh = lhght(root);
        int rh = rhght(root);

        if(rh==lh) return (1<<lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// ************************************************************/

>>> L33.Req. needed to construct a unique bt <<<

*inorder and postorder are not enough....
**inorder and preorder are enought to make a unique bt...


























// ************************************************************/

!!!!!!!  BINARY SEARCH TREE ...... !!!!!!

>>> L39.Intro to bst <<<

// ************************************************************/

>>> L40.search in bst <<<

tc : log2(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL&&val!=root->val)
        {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};

// ************************************************************/

>>> L41.Ceil of bst <<<

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil=-1;
    
    while(node)
    {
        if(node->data==x)
        {
            ceil = node->data;
            return ceil;
        }
        if(x > node->data)
        {
            node=node->right;
        }
        else
        {
            ceil=node->data;
            node=node->left;
        }
    }
    return ceil;
}

// ************************************************************/

>>> L42.floor in bst <<<

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor=-1;
    while(root)
    {
//         cout<<floor<<" ** "<<endl;
        if(X == root->val)
        {
            floor=root->val;
            return floor;
        }
        else if(X > root->val)
        {
            floor=root->val;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return floor;
}

// ************************************************************/

>>> L43.Insert a node in bst <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr = root;

        while(1)
        {
            if(curr->val <= val)
            {
                if(curr->right!=NULL) curr=curr->right;
                else
                {
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(curr->left!=NULL) curr=curr->left;
                else
                {
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

// ************************************************************/
4:54 - 
1/1

>>> L44.Delete a node in bst <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findLr(TreeNode* root)
    {
        if(root->right==NULL) return root;
        return findLr(root->right);
    }

    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        else
        {
            TreeNode* lastRight = findLr(root->left);
            TreeNode* rightchild = root->right;
            lastRight->right = rightchild;
            return root->left;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);

        TreeNode* dummy = root;
        while(root)
        {
            if(root->val > key)
            {
                if(root->left && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root=root->left;
                }
            }
            else
            {
                if(root->right && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else root=root->right;
            }
        } 
        return dummy;
    }  
};

// ************************************************************/
11:22 - 5:59...took enough time to understand recursion...

>>> L45.Kth smallest element in bst <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(TreeNode* root,int &k)
    {
        if(root==NULL)
        return NULL;
        
        TreeNode* left=func(root->left,k);
        if(left!=NULL) return left;

        k--;

        if(k==0) return root;
        
        return func(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* fans = func(root,k);
        return fans->val;
        // return NULL;
    }
};

// ************************************************************/

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
<
<
<
<
< stand on recursionn....
< take time to understand how to approach recursion..
< whether to backtrack everytime..
< or to go with instincts that come thru practice...
<
<
<
<
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// ************************************************************/

6:03 - 7:28

>>> L46. Check if a tree is a BST or BT <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* root,long mini,long maxi)
    {
        if(root==NULL) return true;
        
        if(root->val >= maxi||root->val <= mini) return false;

        return (func(root->left,mini,root->val) && func(root->right,root->val,maxi)) ;

    }

    bool isValidBST(TreeNode* root) {
        long long mini = INT_MIN - 5ll;
        long long maxi = INT_MAX + 5ll; 
        return func(root,mini,maxi);
    }
};

// ************************************************************/

>>> L47.Lca in bst <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr = root->val;

        if(p->val > curr && q->val > curr) return lowestCommonAncestor(root->right,p,q);
        if(p->val < curr && q->val < curr) return lowestCommonAncestor(root->left,p,q);

        return root;
    }
};

// ************************************************************/
 
>>> L48.construct a bst using preorder traversall <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }   
    TreeNode* build(vector<int> a,int& i,int bound)
    {
        if(i==a.size()||a[i]>bound) return NULL;
        TreeNode* root = new TreeNode(a[i++]);
        root->left = build(a,i,root->val);
        root->right = build(a,i,bound);
        return root;
    }
};

// ************************************************************/

>>> L49.successor and predecessor in bst <<<

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void func(BinaryTreeNode<int>* node,vector<int>& trav)
{
    if(node==NULL) return;
    
    func(node->left,trav);
    trav.push_back(node->data);
    func(node->right,trav);
    
    return;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    vector<int> trav;
    func(root,trav);
    int n = trav.size();
    int x;
    for(int i=0;i<n;++i)
    {
        if(trav[i]==key) 
        {
            x=i;
            break;
        }
    }
    int a,b;
    if(n==1) 
    {
        a=-1;
        b=-1;
    }
    else if(x==0)
    {
        a=-1;
        b=trav[x+1];
    }
    else if(x==n-1)
    {
        a=trav[x-1];
        b=-1;
    }
    else
    {
        a=trav[x-1];
        b=trav[x+1];
    }
    pair<int,int> it = {a,b};
    return it;
    
}

// ************************************************************/

-->>>> other approach >>>>

**** using approach of floor and ceil...

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int fp(BinaryTreeNode<int>* root,int k)
{
    int floor = -1;
    while(root)
    {
        if(root->data == k)
        {
            floor = root->data;
            return floor;
        }
        else if(root->data > k)
        {
            root=root->left;
        }
        else
        {
            floor=root->data;
            root=root->right;
        }
    }
    return floor;
}
int fs(BinaryTreeNode<int>* root,int k)
{
    int ceil = -1;
    while(root)
    {
        if(root->data == k)
        {
            ceil = root->data;
            return ceil;
        }
        else if(root->data > k)
        {
            ceil = root->data;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return ceil;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int nodeP = fp(root,key-1);
    int nodeS = fs(root,key+1);
    pair<int,int> ans = {nodeP,nodeS};
    return ans;
}

// ************************************************************/

>>> L50.bst iterator <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushall(TreeNode* root)
    {
        if(root==NULL) return;
        st.push(root);
        pushall(root->left);
        return;
    }

    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(node->right) pushall(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// ************************************************************/

>>> L51.Two sum in bst <<<

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size();
        int i=0,j=n-1;
        while(i<j)
        {
            int sum = ans[i]+ans[j];
            if(sum==k) return true;
            if(sum<k) ++i;
            if(sum>k) --j;
        }
        return false;




    }
};

// ************************************************************/
>>>>>>>> optimal approach ........
attempt strivers optimal codde ...

// ************************************************************/
            5:31 - 6:35
>>> L52. Recover bst <<<

code running is left...

// ************************************************************/

>>> L53.
















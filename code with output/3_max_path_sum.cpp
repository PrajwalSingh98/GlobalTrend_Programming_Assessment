#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        val=0;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int x, TreeNode* l, TreeNode* r){
        val=x;
        left=l;
        right=r;
    }
};
void levelOrder(TreeNode* root)
{
    if (root == NULL)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) 
    {
        if(q.front()==NULL)
        {
            cout<<"NULL ";
            q.pop();
            continue;
        }
        cout << q.front()->val << " ";
        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }
}
/// Here is the actual code ---------------------//

int maximum=0;
int recur(TreeNode* root){
    if(root==NULL)
    {
        cout<<"@";
        return 0;
    }
    int a1=0;
    int a2=0;
    if(root->left!=NULL)
    a1=recur(root->left);
    if(root->right!=NULL)
    a2=recur(root->right);
    int ans=max(a1,a2);
    ans=max(root->val,ans+root->val);
    int a21=max(ans,a1+root->val+a2);
    maximum=max(maximum,a21);
    return ans;
}
int maxPathSum(TreeNode* root) {
    maximum = root->val;
    int x=recur(root);
    return maximum;
}

//------------------------------------------------------------//

int main()
{

    
    // The array is in level order traversal
    vector<int> a={-10,9,20,NULL,NULL,9,7}; //root should not be NULL which is a[0]
    //------------------------------//


    int n=a.size(); 
    TreeNode* root=new TreeNode(a[0]);
    queue<TreeNode*> q;
    q.push(root);
    for(int i=1;i<n;i+=2)
    {
        if(a[i]!=NULL)//left
        {
            TreeNode* temp=new TreeNode(a[i]);
            q.front()->left=temp;
            q.push(temp);
        }
        if(i+1<n && a[i+1]!=NULL)
        {
            TreeNode* temp=new TreeNode(a[i+1]);
            q.front()->right=temp;
            q.push(temp);
        }
        q.pop();
    }
    cout<<"Tree in level order Traversal"<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<"Max path sum: "<<maxPathSum(root);
}
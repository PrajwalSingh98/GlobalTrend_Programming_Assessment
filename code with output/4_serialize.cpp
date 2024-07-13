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
    cout<<endl;
}
/// Here is the actual code ---------------------//
void serialize(TreeNode* root,FILE* fp)
{
    if(root==NULL)
    {
        fprintf(fp,"%d ",-1);
        return;
    }

    fprintf(fp,"%d ",root->val);
    serialize(root->left,fp);
    serialize(root->right,fp);
}
void deserialize(TreeNode*& root,FILE* fp)
{
    int val;
    if(!(fscanf(fp,"%d ",&val)) || val==-1)
    {
        return;
    }
    root=new TreeNode(val);
    deserialize(root->left,fp);
    deserialize(root->right,fp);
}

//------------------------------------------------------------//

int main()
{

    
    // The array is in level order traversal and only positive integer, as we use -1 as marker for NULL in tree
    vector<int> a={10,9,20,NULL,NULL,9,7}; //root should not be NULL which is a[0]
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
    cout<<"Given Tree in level order Traversal"<<endl;
    levelOrder(root);

    //file open to serialize the tree 
    // 4_data.txt should be there in the current directory
    FILE* fp = fopen("4_data.txt", "w");
    if (fp == NULL) {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    //deserialize tree from the file
    TreeNode* root1 = NULL;
    fp = fopen("4_data.txt", "r");
    deserialize(root1, fp);
 
    cout<<"Level Traversal of the tree constructed from file:\n";
    levelOrder(root1);
    fclose(fp);
}
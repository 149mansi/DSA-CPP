// kth ancesstor
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


Node* buildTree(){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if (data==-1)
    {
        return NULL;
    }
    // step A,B,C
    Node* root = new Node(data);
    cout<<"Enter data for left part of"<<data<<"node"<<endl;
    root->left=buildTree();
    cout<<"Enter data for right part of"<<data<<"node"<<endl;
    root->right=buildTree();
    return root;

    
}

bool kthAncestor(Node *root, int &k, int p)
{
    // base case
    if (root == NULL)

        return false;

    if (root->data == p)
    {
        return true;
    }
    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    // wapse aa rahe ho thb minuns minus larn hai
    // check left ya right me answer mila ya nhi
    if (leftAns || rightAns)
    {
        k--;
    }
    if (k==0)
    {
        cout<<"Answer: "<<root->data<<endl;
        k=-1;
    }

    return leftAns || rightAns;
    

}

int main()
{
Node* root=NULL;
root = buildTree();
int k=1;
int p=4;

bool found=kthAncestor(root,k,p);

}
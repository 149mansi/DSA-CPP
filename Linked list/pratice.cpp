/*Merge sort linked list*/

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;

    }

};
void print(Node*head){
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
    
}

Node*merge(Node*left, Node*right){
    if (left==NULL)

        return right;

        if (right==NULL)
       return left;

       Node*ans=new Node(-1);
       Node*temp=ans;
    //    merge 2 sorted linked list
    while (left!=NULL && right!=NULL)
    {
        if (left->data<right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;

        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
        
    }
    while (left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;

    }
    while (right!=NULL)
    {
        temp->next=right;
        temp=right;
        right-right->next;
    }
    ans=ans->next;
    return ans;

    
}

Node* mergeSort(Node* head){
    // base case
    if (head==NULL || head->next==NULL)
    {
       return head;
    }
    // break linked list in two halves after finding
    Node*mid = findMid(head);
    Node*left=head;
    
}
int main(){

}
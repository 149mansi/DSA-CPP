// Find middle of linked list for odd sequence
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next=NULL;
    }

};
void print(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;

    }
    cout<<endl;
}
Node* getMiddle(Node* &head){
// if NUll
if (head == NULL)
{
    cout<<"LL is empty"<<endl;
    return head;

}
if (head->next == NULL)
{
    // only 1 node in LL
    return head;

}
// LL have > 1 node
Node*slow = head;
// Node* fast = head->next;
Node* fast = head;
while (slow!= NULL && fast != NULL)
{
    fast = fast->next;
    if (fast != NULL)
    {
        fast = fast ->next;
        slow = slow ->next;
    }
    
}
return slow;

}
int main(){
    Node* head= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);
    Node* fifth= new Node(50);
    Node* sixth= new Node(60);

head->next = second;
second->next=third;
third->next=fourth;
fourth->next=fifth;
fifth->next= sixth ;
sixth->next=NULL;

print(head);
cout<<"print middle node is:"<<getMiddle(head)->data<<endl;
}
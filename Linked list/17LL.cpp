// sort 0s 1s and 2s
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
void print(Node* head){
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void setZerosOneTwo(Node* head){
    // step1: count 0,1,2
    int zero=0;
    int one=0;
    int two=0;

    Node*temp=head;
    
        while(temp != NULL) {
                if(temp -> data == 0)
                        zero++;
                else if(temp -> data == 1)
                        one++;
                else if(temp -> data == 2)
                        two++;
                temp = temp -> next;
        }
        // step2: fill 0,1,2s in the original LL

        temp=head;
        
            // fill zeros
        while (zero--)
        {
            temp->data=0;
            temp=temp->next;

        }
        // fill ones
        while (one--)
        {
            temp->data=1;
            temp=temp->next;
        }
        while (two--)
        {
            temp->data=2;
            temp=temp->next;
        }
        // temp=temp->next;
        
        }
        
        
    
    



int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(2);
    Node* fourth=new Node(1);
    Node* fifth=new Node(0);
Node* sixth=new Node(0);

head->next=second;
second->next=third;
third->next=fourth;
fourth->next=fifth;
fifth->next=sixth;

cout<<"Input LL:";
print(head);

setZerosOneTwo(head);
cout<<"output LL: ";
print(head);
return 0;
}
// add two linked list
// #include<iostream>
// using namespace std;
// class Node{
// public:
// int data;
// Node* next;
// Node(int data){
//     this->data=data;
//     this->next=NULL;
// }
// };

// void print(Node* head) {
//         Node* temp = head;
//         while(temp != NULL) {
//                 cout << temp -> data << " ";
//                 temp = temp -> next;
//         }
//         cout << endl;
// }

// Node* reverse(Node* head){
//     Node*prev =NULL;
//     Node*curr=head;
//     Node*next=NULL;
//     while (curr!=NULL)
//     {
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     return prev;
// }
// Node* solve(Node* &head1, Node* &head2){
//     // step1:reverse the lknked list
// head1=reverse(head1);
// head2=reverse(head2);

//     // step2:add both linked list
// Node* ansHead=NULL;
// Node* ansTail=NULL;
// int carry =0;
// while (head1!=NULL && head2!=NULL)
// {
//     int sum=carry+ head1->data+head2->data;
//     int digit=sum%10;
//     carry=sum/10;
//     // create a new node for the digit
//     Node* newNode = new Node(digit);
// // attach the newNode into the answer wali linked list
//     if (ansHead == NULL)
//     {
//         /* fisrt node insert kre ho*/
//         ansHead=newNode;
//         ansTail=newNode;


//     }
//     else
//     {
//         ansTail->next=newNode;
// ansTail=newNode;
//     }
//     head1=head1->next;
//     head2=head2->next;
    
    
// }
// // jab head1 list l=ki length head2 list se jada hogi
// while (head1!=NULL)
// {
//     int sum=carry+head1->data;
// int digit = sum %10;
// carry=sum/10;
// Node* newNode = new Node(digit);
// ansTail->next=newNode;
// ansTail=newNode;
// head1=head1->next;
// }
// // jab head2 list ki length head1 list se jada hogi
// while (head2!=NULL)
// {
//     int sum=carry+head1->data;
// int digit = sum %10;
// carry=sum/10;
// Node* newNode = new Node(digit);
// ansTail->next=newNode;
// ansTail=newNode;
// head2=head2->next;
// }

// // handel carry ko alag se
// while (carry!=0)
// {
//     int sum=carry;
//     int digit=sum%10;
//     carry=sum/10;
//     Node* newNode = new Node(digit);
// ansTail->next=newNode;
// ansTail=newNode;
// head2=head2->next;
// }

//     // step3:reverse the ans linked list
// ansHead= reverse(ansHead);
// return ansHead;

// }
// int main(){
// Node* head1=new Node(2);
// Node* second1=new Node(4);
// head1->next=second1;

// Node* head2= new Node(2);
// Node* second2=new Node(3);
// Node* third2=new Node(4);

// head2->next=second2;
// second2->next=third2;

// Node* ans= solve(head1, head2);
// print(ans);
// return 0;

// }



#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL; // Initialize next here
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* solve(Node* &head1, Node* &head2) {
    if (head1==NULL)
    
        return head2;
    if (head2==NULL)
    return head1;
    
    
    // Step 1: Reverse the linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    // Step 2: Add both linked lists
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    
    while (head1 != NULL && head2 != NULL) {
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        carry = sum / 10;
        
        // Create a new node for the digit
        Node* newNode = new Node(digit);
        // Attach the newNode into the answer linked list
        if (ansHead == NULL) {
            ansHead = newNode; // First node
            ansTail = newNode;
        } else {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // When head1 is longer than head2
    while (head1 != NULL) {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }

    // When head2 is longer than head1
    while (head2 != NULL) {
        int sum = carry + head2->data; // Change head1 to head2
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next; // This line is fine
    }

    // Handle carry separately
    while (carry != 0) {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // Step 3: Reverse the answer linked list
    ansHead = reverse(ansHead);
    return ansHead;
}

int main() {
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1->next = second1;

    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2 = new Node(4);
    head2->next = second2;
    second2->next = third2;

    Node* ans = solve(head1, head2);
    print(ans); // This should now print the correct output
    return 0;
}
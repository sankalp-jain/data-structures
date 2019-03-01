#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

void push(struct node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    node* new_node = new node(new_data); 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
   
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node; 
} 

node* reverse(node* head){
    if(head -> next == NULL)
        return head;

    node* temp = reverse(head -> next);
    node* temp1 = temp;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = head;
    head -> next = NULL;
    head = temp1;
    cout << temp1 ->  data << endl;
    cout << head ->  data << endl;
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head = new node(0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    print(head);
    node* head1 = reverse(head);
    print(head1);
    return 0;
}


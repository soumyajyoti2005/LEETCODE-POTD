#include<iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int val){
            this->val = val;
            this->next = NULL;
        }
};


ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL){
            return head;
        }
    int l = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    
    if(k>l){
        k=k%l;
    }
    // step 2 building connection or cycle with first node
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp=head;
    // step 3 traverse to l-k-1 node and l-k node's adress head and giving Null in (l-k-1 Node)->next=NULL
    for (int i = 0; i < l - k - 1 ; i++)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    return head;
     }


int main(){
    int n;
    cin>>n;
    ListNode* head = new ListNode(0);
    int x;
    ListNode* temp = head;

    for(int i=1;i<=n;i++){
         cin>>x;
         ListNode* node = new ListNode(x);
         temp->next = node;
         temp = temp->next;
    }

    int k;
    cin>>k;

    ListNode* newhead = rotateRight(head,k);

    while(newhead){
        cout<<newhead->val;
        newhead = newhead -> next;
    }

}
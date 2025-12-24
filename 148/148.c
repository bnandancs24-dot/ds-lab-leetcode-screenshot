/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergesort(struct ListNode* left,struct ListNode* right){
    if(!left)
        return right;
    if(!right)
        return left;

    struct ListNode*res=NULL;
    if(left->val<right->val)
    {
        res=left;
        res->next=mergesort(left->next,right);
    }else{
        res=right;
        res->next=mergesort(left,right->next);
    }
    return res;
}
struct ListNode* middle(struct ListNode* head){
    struct ListNode*slow=head;
    struct ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
struct ListNode* sort(struct ListNode*head){
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* mid=middle(head);
    struct ListNode* righthalf=mid->next;
    mid->next=NULL;
    struct ListNode* left=sort(head);
    struct ListNode* right=sort(righthalf);
    return mergesort(left,right);
}
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* ans=sort(head);
    return ans;
}

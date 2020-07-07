/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
    	ListNode *newHead = new ListNode(0);     //虚拟节点
    	newHead->next = head;
    	ListNode *pp = newHead;
        ListNode *pre = head;
        ListNode *suc = head->next;

        while(pre != NULL && suc != NULL){
        	//交换
        	pre->next = suc->next;
        	suc->next = pre;
        	pp->next = suc;

        	//指针后移
            if(!pre->next)
                break;
        	pp = pre;
        	suc = pre->next->next;
            pre = pre->next;
        }
        return newHead->next;
    }
};
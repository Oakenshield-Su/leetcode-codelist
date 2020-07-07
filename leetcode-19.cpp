/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 题解：删除链表的倒数第N个节点
 * 基本思想：滑动窗口
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       //构造头结点
    	ListNode* h = head;
    	ListNode *fast= head, *slow = head;
    	
    	while(n > 0){
    		fast = fast->next;
    		n--;
    	}
    	if (!fast)      // 1->2->3  n=3时的情况
    		return h->next;

    	while(fast->next){
			slow = slow->next;
    		fast = fast->next;
    	}

    	//删除slow节点
    	slow->next = slow->next->next;
    	return h;
    }
};
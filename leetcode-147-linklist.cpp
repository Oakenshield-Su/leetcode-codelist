/**
 * 147 对链表进行插入排序
 * 
 **/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = head;
        ListNode *q;
        ListNode *p;
        ListNode *temp;

        while(cur != nullptr){
            p = dummy;
            while(p->next != nullptr && cur->val > p->next->val){
                p = p->next;
            }
            temp = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = temp;
        }

        return dummy->next;
    }

    //维护有序表版
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(0);     //哑结点
        dummy->next = head;
        ListNode* lastOrdered = head;          //有序表最后一个元素
        ListNode* cur = head->next;             //原链表工作节点
        ListNode* pre;                 //有序表工作节点

        while(cur != nullptr){
            if (lastOrdered->val <= cur->val){
                lastOrdered = lastOrdered->next;     //有序表尾结点后移
            }else{
                pre = dummy;
                //为什么不判断pre是否超出有序表？因为前边已经判断当前节点值小于有序表尾结点,所以pre不会超过尾结点
                while(pre->next->val <= cur->val){    //寻找有序表中的插入点
                    pre = pre->next;
                }
                lastOrdered->next = cur->next;        //有序表尾结点后移
                //插入操作
                cur->next = pre->next;               
                pre->next = cur;
            } 
            cur = lastOrdered->next;
        }

        return dummy->next;
    }
};
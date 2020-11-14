/**
 * 328.奇偶链表
 * 难点：范围定义
 * 思想：定义奇偶对，每次以奇偶对的形式进行遍历
 **/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* even_head = even;  //保留偶数链表头
        while (even != nullptr && even->next != nullptr)   //even->next为空表示奇偶对后面没有元素
        {
            odd->next = even->next;                 //当前奇偶对指向下一个奇偶对
            even->next = even->next->next;

            odd = odd->next;                        //奇偶对后移
            even = even->next;
        }
        odd->next = even_head;                      //偶数链连接到奇数链
        return head;
    }
};
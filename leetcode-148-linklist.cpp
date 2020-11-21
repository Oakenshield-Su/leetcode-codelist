/**
 * 148 排序链表
 * 时间复杂度O(nlogn)
 * 思路：归并排序
 **/
class Solution {
public:
     ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);  //构造哑结点
        ListNode* s = head;
        int length = 0;
        //统计链表长度
        while(s){
            length++;
            s = s->next;
        }

        //主逻辑 断链->合并
        for (int subLength = 1; subLength < length; subLength <<= 1)
        {
            ListNode* cur = dummy->next;     //未断链的子链的头结点，每一次循环都从头开始
            ListNode* tail = dummy;          //断链后合并后子链表的尾结点
            while (cur)
            {
                ListNode* left = cur;  //left->@->@->@->@->@.....
                ListNode* right = cut(left, subLength); //left->@->@->null right->@->@->@....
                cur = cut(right, subLength);  //left->@->@->null right->@->@..  cur->@....

                tail->next = merge(left, right);     //合并操作,返回子链的头结点
                while (tail->next) tail = tail->next;      //更新断链后合并后子链表的尾结点
            }
        }
        return dummy->next;
    }

    ListNode* cut(ListNode* head, int subLength){
        ListNode* p = head; //暗含一次移动
        while(--subLength > 0 && p){
            p = p->next;
        }
        if (!p) return nullptr; //切割链长度不够，所以后序为空
        ListNode* next_head = p->next;
        p->next = nullptr;       //断链
        return next_head;         //返回尾结点
    }


    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (left && right)
        {
            if(left->val < right->val){
                p->next = left;     //连接操作
                left = left->next;
            }else{
                p->next = right;     //连接操作
                right = right->next;
            }
            p = p->next;     //工作节点后移
        }
        
        //如果有一个链未遍历结束
        p->next = (left != nullptr) ? left : right;
        return dummy->next;
    } 

};

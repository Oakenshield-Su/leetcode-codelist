class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next = nullptr) return head;

        //创建哑结点
        ListNode* dummpy = new ListNode();
        ListNode* d_cur = dummpy;

        //重复区间[start, end]
        ListNode* start = head;
        ListNode* end = head;

        //工作指针      
        ListNode* cur = head->next;

        //为什么使用重复区间而不是简单的前驱指针，因为只使用前驱指针的情况下你可以skip重复元素但是在区间末尾元素和当前元素不同时
        //不好处理，当然你可以用一个flag标志位。
        while(cur){
            if(cur->val == end->val){    //当前元素和区间末尾元素相同时区间向外扩展一个元素
                end = cur;
            }else{                      //当前元素和区间末尾元素不相同时考虑是插入非重复元素还是跳过重复元素
                if(start == end){       //区间内只有一个元素时插入元素
                    d_cur->next = start;
                    d_cur = d_cur->next;
                    d_cur->next = nullptr;
                }
                start = cur;              //暗含跳过重复元素的操作
                end = cur;
            }
            cur = cur->next;              //工作指针后移
        }
        
        if(start == end){             //后处理，因为重复区间[start, end]在cur前一位，但是cur为null时重复区间还未插入或者跳过
            d_cur->next = start;
            d_cur = d_cur->next;
        }

        return dummpy->next;
    }
};
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

/**
 *
**/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* dummpy = new ListNode();
        dummpy->next = head;
        ListNode* pre = dummpy;
        ListNode* cur = head;

        while(cur && cur->next){
            if(cur->val != cur->next->val){
                pre->next = cur;
                pre = pre->next;
            }
            cur = cur->next;
        }
        if(cur)
            pre->next = cur;

        return dummpy->next;
    }
};



class Solution {
public:
    //迭代法：定义函数deleteDuplicates为删除重复数，返回值是去重后的头结点
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  //当前链表只有0个或1个元素，所以不存在重复
            return head;
        head->next = deleteDuplicates(head->next);    //逻辑上删除head结点以后的重复元素
        if(head->val == head->next->val)             //删除重复元素
            head = head->next;
        return head;
    }
};
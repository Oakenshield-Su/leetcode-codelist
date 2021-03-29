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
 * 206.反转链表
**/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode *dummy = new ListNode(0, head); 
        ListNode *cur = head;
        ListNode *pre = dummy;

        //头插法
        cur = pre->next;
        while(cur->next){
            ListNode *tmp = cur->next->next;   //保存当前插入节点之后的元素
            cur->next->next = pre->next;      //当前插入节点连接前驱节点的下一个节点
            pre->next = cur->next;            //前驱节点的连接当前插入节点
            cur->next = tmp;                  //cur节点连接当前插入节点之后的元素
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
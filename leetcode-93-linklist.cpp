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
 * 92.反转链表（二）
**/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right) return head;
        
        ListNode *dummy = new ListNode(0, head); 
        ListNode *start = head;
        ListNode *pre = dummy;

        //寻找开始节点的前驱
        for(int i = 1; i < left; i++){
            pre = pre->next;
        }

        //头插法
        start = pre->next;
        for(int i = left; i < right; i++){
            ListNode *tmp = start->next->next;   //保存当前插入节点之后的元素
            start->next->next = pre->next;      //当前插入节点连接前驱节点的下一个节点
            pre->next = start->next;            //前驱节点的连接当前插入节点
            start->next = tmp;                  //start节点连接当前插入节点之后的元素
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
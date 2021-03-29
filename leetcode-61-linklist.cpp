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
 * 61 旋转链表
 * 头尾相接法
**/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

        //统计链表中节点个数，并找到链表结尾
        int n = 1;
        ListNode *cur = head;
        while(cur->next){
            cur = cur->next;
            n++;
        }

        //链表首尾相连
        cur->next = head;
        
        //头结点移动n-k位
        //int new_k = k % n; 如果k大于n的情况下，旋转n位等价于未旋转所以取模
       
        for(int i = (n - k % n); i > 0; i--){
            head = head->next;
            cur = cur->next;
        }
        cur->next = nullptr;

        return head;
    }
};
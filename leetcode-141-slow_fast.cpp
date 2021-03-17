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
 * 快慢指针
 * 基本思路：如果存在环则两指针必定相遇，如果不存在则快指针率先指向nullptr
 * 总而言之，只要指针遇到空指针的情况都不可能成环
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next){   //不成环条件
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)     //成环条件
                return true;
        }
        return false;
    }
};
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
    ListNode *sum_l(ListNode *l1, ListNode *l2, int add)
    {
        if (l1 == nullptr && l2 == nullptr && add == 0)
            return nullptr;
        int cur_val = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + add;
        ListNode* res = new ListNode(cur_val % 10);
        res->next = sum_l( (l1 == nullptr ? l1 : l1->next),(l2 == nullptr ? l2 : l2->next) , cur_val/10);
        return res;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return sum_l(l1, l2, 0);
    }


};
// @lc code=end

/**
 * 1. 判断边界并退出
 * 2. 计算和并取模
 * 3. 递归下一个,并加上前者的十位数.赋值给next指针
 */
#ifndef __LEETCODE_H__
#define __LEETCODE_H__

#include <time.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <deque>
#include <optional>
#include <unordered_map>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};

    static ListNode *from_string(std::string str)
    {
        if (std::empty(str))
            return nullptr;
        if (std::size(str) < 2)
            return nullptr;
        if (str[0] != '[' && str.back() != ']')
            return nullptr;

        // spilit
        std::vector<int> nums;
        for (auto i = 1; i < std::size(str) - 1;)
        {
            int j = i;
            while (str[j] != ',' && j < std::size(str) - 1)
                ++j;
            std::string num_str = str.substr(i, j - i);
            nums.push_back(std::stoi(num_str));
            i = j + 1;
        }

        // build list
        ListNode *head = nullptr;
        ListNode *tail = head;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (head == nullptr)
            {
                head = new ListNode(nums[i]);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(nums[i]);
                tail = tail->next;
            }
        }

        return head;
    }
};

bool equal(ListNode* l1, ListNode* l2){
    if(l1 == nullptr && l2 != nullptr)return false;
    if(l1 != nullptr && l2 == nullptr)return false;
    if(l1 == nullptr && l2 == nullptr)return true;
    if(l1->val != l2->val)return false;
    return equal(l1->next, l2->next);
}

#endif // __LEETCODE_H__
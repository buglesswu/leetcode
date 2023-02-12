#include "leetcode.hpp"

#include <memory>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        int carry_value = 0;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while(l1 != nullptr || l2 != nullptr){

            int l1_value = l1 != nullptr ? l1->val : 0;
            int l2_value = l2 != nullptr ? l2->val : 0;
            int temp_val = l1_value + l2_value + carry_value;

            ListNode* temp_node = new ListNode(temp_val);

            if(temp_val > 9){
                temp_node->val -= 10;
                carry_value = 1;
            }else{
                carry_value = 0;
            }

            tail->next = temp_node;
            tail = tail->next;

            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }

        if(carry_value){
            tail->next = new ListNode(carry_value);
        }

        return head->next;
    }
};

TEST_CASE("add-two-numbers-1")
{
    auto* l1 = ListNode::from_string("[2,4,3]");
    auto* l2 = ListNode::from_string("[5,6,4]");

    auto* expect = Solution().addTwoNumbers(l1, l2);
    CHECK(equal(expect, ListNode::from_string("[7,0,8]")));
}

TEST_CASE("add-two-numbers-2")
{
    auto* l1 = ListNode::from_string("[0]");
    auto* l2 = ListNode::from_string("[0]");

    auto* expect = Solution().addTwoNumbers(l1, l2);
    CHECK(equal(expect, ListNode::from_string("[0]")));
}

TEST_CASE("add-two-numbers-3")
{
    auto* l1 = ListNode::from_string("[9,9,9,9,9,9,9]");
    auto* l2 = ListNode::from_string("[9,9,9,9]");

    auto* expect = Solution().addTwoNumbers(l1, l2);
    CHECK(equal(expect, ListNode::from_string("[8,9,9,9,0,0,0,1]")));
}



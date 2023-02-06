#include "leetcode.hpp"

#include <unordered_map>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int,int> kv;
        for(auto i = 0; i < nums.size(); i++){
            if(kv.find(target - nums[i]) != kv.end()){
                return {kv[target - nums[i]], i};
            }else{
                kv[nums[i]] = i;
            }
        }

        return {}; // should not reach here
    }
};

TEST_CASE("two-sum-1")
{
    vector<int> v = {2, 7, 11, 15};
    vector<int> expect = {0, 1};
    auto solution = new Solution();
    CHECK(solution->twoSum(v, 9) == expect);

    delete solution;
}

TEST_CASE("two-sum-2")
{
    vector<int> v = {3, 2, 4};
    vector<int> expect = {1, 2};
    auto solution = new Solution();
    CHECK(solution->twoSum(v, 6) == expect);

    delete solution;
}

TEST_CASE("two-sum-3")
{
    vector<int> v = {3, 3};
    vector<int> expect = {0, 1};
    auto solution = new Solution();
    CHECK(solution->twoSum(v, 6) == expect);

    delete solution;
}
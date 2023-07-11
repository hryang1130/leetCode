//
// Created by kevin on 2023/7/11.
//

#ifndef LEETCODEGITHUB_SOLUTION1911_HPP
#define LEETCODEGITHUB_SOLUTION1911_HPP

#include <vector>
using namespace std;

//https://leetcode.cn/problems/maximum-alternating-subsequence-sum/
class Solution {
public:
long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    long long odd=0,even=nums[0];
    for(int i=1;i<n;i++){
        even = max(even,odd+nums[i]);
        odd = max(odd,even-nums[i]);
    }
    return even;
}
};



#endif //LEETCODEGITHUB_SOLUTION1911_H

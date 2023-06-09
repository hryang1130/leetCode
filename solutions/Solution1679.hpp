//
// Created by kevin on 2023/6/9.
//

#ifndef LEETCODEGITHUB_SOLUTION1679_HPP
#define LEETCODEGITHUB_SOLUTION1679_HPP


//https://leetcode.cn/problems/max-number-of-k-sum-pairs/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int res=0;
        while(l<r){
            if(k==(nums[l]+nums[r])){
                l++;r--;res++;
            }else if(k>(nums[l]+nums[r])){
                l++;
            }else{
                r--;
            }
        }
        return res;

    }
};

#endif //LEETCODEGITHUB_SOLUTION1679_H

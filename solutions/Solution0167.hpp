//
// Created by kevin on 2023/7/8.
//

#ifndef LEETCODEGITHUB_SOLUTION0167_H
#define LEETCODEGITHUB_SOLUTION0167_H


//https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left=0,right=numbers.size()-1;
        while(left < right){
            if(target==numbers[left]+numbers[right]){
                res.push_back(left+1);res.push_back(right+1);
                break;
            }else if(target < numbers[left]+numbers[right]){
                right--;
            }else{
                left++;
            }
        }
        return res;

    }
};

#endif //LEETCODEGITHUB_SOLUTION0167_H

//
// Created by kevin on 2023/7/6.
//

#ifndef LEETCODEGITHUB_SOLUTION2178_HPP
#define LEETCODEGITHUB_SOLUTION2178_HPP
#include <vector>
using namespace std;

//https://leetcode.cn/problems/maximum-split-of-positive-even-integers/

class Solution {
public:
    vector<long long> res;
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2==1){
            return res;
        }
        for(int i=2;i<=finalSum;i+=2){
            res.push_back(i);
            finalSum-=i;
        }
        res.back() += finalSum;
        return res;

    }
};

#endif //LEETCODEGITHUB_SOLUTION2178_H

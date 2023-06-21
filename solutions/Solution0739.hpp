//
// Created by kevin on 2023/6/21.
//

#ifndef LEETCODEGITHUB_SOLUTION0739_HPP
#define LEETCODEGITHUB_SOLUTION0739_HPP

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> lastIdx;
        for(int i=0;i<n;i++){
            while(!lastIdx.empty() && temperatures[i] > temperatures[lastIdx.top()]){
                auto t = lastIdx.top();lastIdx.pop();
                res[t]=i-t;
            }
            lastIdx.push(i);
        }
        return res;
    }
};

#endif //LEETCODEGITHUB_SOLUTION0739_H

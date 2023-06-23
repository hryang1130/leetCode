//
// Created by kevin on 2023/6/23.
//

#ifndef LEETCODEGITHUB_SOLUTION2496_HPP
#define LEETCODEGITHUB_SOLUTION2496_HPP
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int val=0;
        for(auto str:strs){
            bool isNum=true;
            for(auto ch:str){
                if(!isdigit(ch)){
                    val=val>str.size() ? val:str.size();
                    isNum=false;
                    break;
                }
            }
            if(isNum){
                int num = atoi(str.c_str());
                val = val > num ? val:num;
            }
        }

        return val;
    }
};

#endif //LEETCODEGITHUB_SOLUTION2496_H

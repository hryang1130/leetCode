//
// Created by kevin on 2023/6/5.
//

#ifndef LEETCODEGITEE_SOLUTION1768_HPP
#define LEETCODEGITEE_SOLUTION1768_HPP
#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i,j=0;
        while(i<word1.size() || j<word2.size()){
            if(i<word1.size()){
                ans+=word1[i++];
            }
            if(j<word2.size()){
                ans+=word2[j++];
            }
        }
        return ans;
    }
};

#endif //LEETCODEGITEE_SOLUTION1768_HPP

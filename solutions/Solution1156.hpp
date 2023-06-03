//
// Created by kevin on 2023/6/3.
//

#ifndef LEETCODEGITEE_SOLUTION1156_HPP
#define LEETCODEGITEE_SOLUTION1156_HPP

#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char,int> cnts;
        for(auto ch:text){
            if(cnts.count(ch)==0){
                cnts[ch]=1;
            }else{
                cnts[ch]++;
            }
        }
        int res=1;
        for(int i=0;i<text.size();){
            int j=i;
            while(j<text.size() && text[j]==text[i]){
                ++j;
            }
            int left=j-i;
            int k=j+1;
            while(k<text.size() && text[k]==text[i]){
                k++;
            }
            int right=k-(j+1);
            res=max(res,min(k-i,cnts[text[i]]));
            i=j;
        }
        return res;
    }
};

#endif //LEETCODEGITEE_SOLUTION1156_HPP

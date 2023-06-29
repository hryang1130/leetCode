//
// Created by kevin on 2023/6/30.
//

#ifndef LEETCODEGITHUB_SOLUTION2390_HPP
#define LEETCODEGITHUB_SOLUTION2390_HPP

//https://leetcode.cn/problems/circular-sentence/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence[0]!=sentence[n-1]){
            return false;
        }
        stack<int> se;
        for(int i=0;i<n;i++){
            if(i+1 < n && sentence[i+1]==' '){
                se.push(sentence[i]);
            }
            if(i>0 && sentence[i-1]==' '){
                if(sentence[i]==se.top()){
                    se.pop();
                }else{
                    return false;
                }
            }
        }

        return true;

    }
};

#endif //LEETCODEGITHUB_SOLUTION2390_H

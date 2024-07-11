//ques - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int left=0,right=0;
        int maxlen=0;
        while(right<n){
            if(mpp.find(s[right])!=mpp.end()){
                int idx=mpp[s[right]];
                if(idx>=left){
                    maxlen=max(maxlen,right-left);
                    left=idx+1;
                }
            }
            mpp[s[right]]=right;
            right++;
        }
        maxlen=max(maxlen,n-left);
        return maxlen;
    }
};
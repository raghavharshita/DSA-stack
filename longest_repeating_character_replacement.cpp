// ques-https://leetcode.com/problems/longest-repeating-character-replacement/
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int characterReplacement(string s,int k){
        int maxlen=0;
        int maxfreq=0;
        int hash[26]={0};
        int left=0;
        int right=0;
        while(right<s.size()){
            hash[s[right]-'A']++;
            maxfreq=max(maxfreq,hash[s[right]-'A']);
            if(right-left+1-maxfreq>k){
                hash[s[left]-'A']--;
                left++;
            }
            if(right-left+1<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
    }
};
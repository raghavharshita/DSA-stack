#include<bits/stdc++.h>
using namespace std;

class LRUCache1 {
public:
    unordered_map<int,int>mpp;
    deque<int>dq;
    int s;
    LRUCache1(int capacity) {
        s=capacity;
    }
    
    int get(int key) { 
        if(mpp.find(key)!=mpp.end()){
            auto it=find(dq.begin(),dq.end(),key);
            if(it!=dq.end()){
                dq.erase(it);
            }
            dq.push_back(key);
            return mpp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.size() >= s && mpp.find(key) == mpp.end()) {
            int lruKey = dq.front();
            dq.pop_front();
            mpp.erase(lruKey);
        }
        auto it=find(dq.begin(),dq.end(),key);
        if(it!=dq.end()){
            dq.erase(it);
        }
        dq.push_back(key);
        mpp[key] = value;
    }
};



class LRUcache2
{
    public:
    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mpp;
    int s;
    LRUcache2(int capacity) {
        s=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            dll.erase(mpp[key].first);
            dll.push_front(key);
            mpp[key].first=dll.begin();
            return mpp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            dll.erase(mpp[key].first);
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
        }
        else{
            if(mpp.size()>=s){
                int t=dll.back();
                dll.pop_back();
                mpp.erase(t);
            }
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
        }
    }
};
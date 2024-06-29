#include<bits/stdc++.h>
using namespace std;
vector<int>nextsmaller(vector<int>height,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 && height[st.top()]>=height[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int>prevsmaller(vector<int>height,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(st.top()!=-1 && height[st.top()]>=height[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
int largestrectanglearea(vector<int>height){
    int n=height.size();
    vector<int>next=nextsmaller(height,n);
    vector<int>prev=prevsmaller(height,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int l=height[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        area=max(area,l*b);
    }
    return area;
}
int main(){
    vector<int>height={2,1,5,6,2,3};
    int t=largestrectanglearea(height);
    cout<<t<<endl;
}
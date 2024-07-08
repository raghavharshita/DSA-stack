//The clelebrity problem https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVJUMmEwS1RsQkphcTVoNGRqQk5iRG9WeHR2UXxBQ3Jtc0ttdi1McHFRX0lOb2lGUWhuV0NIX3V3ZDF2VW1VNnRpeVNtNUIxMFBpRmpLZ2hOZW56R0QxQWNaYmZTdjRUM3JYenlKZngtMWpKTExrX19xQWNRUXR3ME9XVU1CM3A3X1ZlR1lubFFLNXBJMGptZHpuOA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fthe-celebrity-problem%2F1%2F&v=9u2BJfmWNEg
#include<bits/stdc++.h>
using namespace std;
class Solution1
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        for(int i=0;i<n;i++){
            //row check
            bool flagrow=true;
            for(int j=0;j<n;j++){
                if(M[i][j]==1)flagrow=false;
            }
            //column check
            bool flagcol=true;
            for(int j=0;j<n;j++){
                if(i!=j && M[j][i]==0)flagcol=false;
            }
            if(flagrow && flagcol){
                return i;
            }
        }
        return -1;
    }
};
class solution2
{
    public:
    int celebrity(vector<vector<int> >& M, int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(a!=b && M[a][b]==1){
                st.push(b);
            }
            else if(a!=b && M[b][a]==1){
                st.push(a);
            }
        }
        int t=st.top();
        //row check
        for(int i=0;i<n;i++){
            if(M[t][i]==1)return -1;
        }
        //column check
        for(int i=0;i<n;i++){
            if(i!=t && M[i][t]==0)return -1;
        }
        return t;
    }
};

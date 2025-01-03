// Problem Statement:
// There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

// Note: Start the array with positive elements.
#include<iostream>
#include<vector>
using namespace std;
vector<int>RearrangebySign(vector<int>A,int n){
    vector<int>pos;
    vector<int>neg;
    for (int i = 0; i < n; i++)
    {
        if (A[i]>0)
        
            pos.push_back(A[i]);
            else neg.push_back(A[i]);
        
        
    }
    if (pos.size()<neg.size())
    {
        for (int i = 0; i < pos.size(); i++)
        {
            A[2*i]=pos[i];
            A[2*i+1]=neg[i];
        }
        int index = pos.size()*2;
        for( int i = pos.size(); i < neg.size(); i++)
        {
            A[index]=neg[i];
            index++;
        }
        
        
    }
    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            A[2*i]=pos[i];
            A[2*i+1]=neg[i];
        }
        int index = neg.size()*2;
        for( int i = neg.size(); i < pos.size(); i++)
        {
            A[index]=pos[i];
            index++;
        }
        
    }
    
    return A;
    
}
int main(){
    int n=6;
    vector<int> A{1,2,-4,-5,3,4};
    vector<int> ans=RearrangebySign(A,n);
for (int i = 0; i < ans.size(); i++)
{
    cout<<ans[i]<<" ";
}
return 0;
    
}
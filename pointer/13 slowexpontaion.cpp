// 5^4
#include<iostream>
using namespace std;
int slowExponentiation(int a,int b){
    int ans=1;
    for (int i = 0; i <b; ++i)
    {
       ans*=a; 
    }
    return ans;
}//time complexity O(b)
int main(){
    cout<<slowExponentiation(5,4)<<endl;
    return 0;
}
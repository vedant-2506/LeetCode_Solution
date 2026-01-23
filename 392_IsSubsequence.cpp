#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz1 = s.size() , sz2=t.size() ;
        int n= sz1;

        int i=0,j=0;
        while(i<sz1  &&  j<sz2){
            if(s[i] == t[j]){
                i++,j++;
                n--;
            }
            else{
                j++;
            }
        }

        return (n<=0) ? true : false;
        
    }
};

int main(){
    string s , t;

    cout<<"Enter two strings to check if first is subsequence of second :"<<endl;
    cin>>s>>t;

    Solution sol;

    bool result = sol.isSubsequence(s,t);

    if(result){
        cout<<"Yes, first string is subsequence of second string"<<endl;
    }
    else{
        cout<<"No, first string is not subsequence of second string"<<endl;
    }

    return 0;
}
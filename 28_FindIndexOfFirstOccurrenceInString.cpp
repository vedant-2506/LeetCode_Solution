#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        ////1st solution 2pointer TC = O(m*n) SC = O(1)
        // int i=0;
        // while(i<haystack.size()){
            
        //     int j=0,k=i;
        //     while(j<needle.size() && haystack[k] == needle[j] ){
        //         j++;
        //         k++;
                
        //     }

        //     if(j == needle.size() ) return i;

        //     i++;
        // }

        // return -1;
    


    //2nd solution substr TC = O(m*n) SC = O(n)

    for(int i=0;i<haystack.size();i++){
        string S1 = haystack.substr(i, needle.size());
        if(S1 == needle) return i;
    }

    return -1;

    }
};

int main(){
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout<<s.strStr(haystack, needle)<<endl;
}
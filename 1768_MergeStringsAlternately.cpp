#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        // //two pointer using same loop 
        // // TC=O(m+n) SC=(m+n)
        // string ans="";
        // int k=0;

        // while(k<word1.size() || k<word2.size() ){
        //     if(k<word1.size() ){
        //         ans+=word1[k];
        //     }
        //     if(k<word2.size()){
        //         ans+=word2[k];
        //     }
        //     k++;
        // }

        // return ans;

        //Two pointer using multiple loop 
        //TC=O(m+n SC=O(m+n)
        string ans="";
        int i=0 , j=0;
        while(i<word1.size() && j<word2.size()){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        while(i<word1.size()){
            ans+=word1[i++];
        }
        while(j<word2.size()){
            ans+=word2[j++];
        }
        return ans;
        
    }
};

int main() {

    Solution sol;
    string word1, word2;

    cout << "Enter the first string : ";
    cin >> word1;

    cout << "Enter the second string: ";
    cin >> word2;

    string result = sol.mergeAlternately(word1, word2);

    cout << "\nMerged String: " << result << endl;

    return 0;
}
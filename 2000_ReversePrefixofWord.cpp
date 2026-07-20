#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        // //Prefix Reconstruction (Manual Prefix Reversal)
        // //TC=O(n) SC=O(n)
        // int count=-1;;
        // for(int i=0; i<word.size(); i++){
        //     if(word[i] == ch){ 
        //         count=i;
        //         break;
        //     }
        // }
        // if(count == -1) return word;

        // string ans="";
        // for(int i=count; i>=0; i--){
        //     ans+=word[i];
        // }
        // for(int i=count+1; i<word.size(); i++){
        //     ans+=word[i];
        // }
        // return ans;

        //In-place Two Pointer Prefix Reversal
        //TC=O(n) SC=O(1) 
        int pos=word.find(ch);
        if(pos == string::npos) return word;
        int i=0 , j=pos;
        while(i<j){
            swap( word[i] , word[j] );
            i++;
            j--;
        }
        return word;

    }
};

int main() {

    Solution sol;
    string word;
    char ch;

    cout << "Enter the word: ";
    cin >> word;

    cout << "Enter the character to reverse the prefix up to: ";
    cin >> ch;

    string result = sol.reversePrefix(word, ch);

    cout << "\nResult after reversing the prefix: " << result << endl;

    return 0;
}
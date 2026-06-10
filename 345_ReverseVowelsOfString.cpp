#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i =0;
        int j = s.size()-1;

        while(i<j){
            while(i<j && !isVowel(s[i])) { i++; }
            while(i<j && !isVowel(s[j])) { j--; }
            swap(s[i] , s[j]);
            i++,j--;
        }
        return s;
    }

    bool isVowel(char s){
        if(s=='a' || s=='e' || s=='i'|| s=='o'|| s=='u'|| s=='A'|| s=='E'|| s=='I'|| s=='O'|| s=='U') return true;
        else{
            return false;
        }
    }
};

int main(){
    Solution s;
    string str = "hello";
    cout<<s.reverseVowels(str)<<endl;
    return 0;
}

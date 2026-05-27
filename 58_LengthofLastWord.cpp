#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size();

        int j=0;
        int i=sz-1;
        int count=0;

        while( i>= 0 && s[i] == ' '){
            i--;
        }

        while( i>= 0 && s[i] != ' '){
            count++;
            i--;
        }
        

     
        return count;
        
    }
};

int main(){
    Solution s;
    string str = "Hello World";
    int result = s.lengthOfLastWord(str);
    cout<<result<<endl;
    return 0;
}
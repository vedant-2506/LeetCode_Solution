#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans;
        int sz1 = word1.size();
        int sz2 = word2.size();

        int i=0,j=0;
        while(i<sz1 && j<sz2) {
           ans   += word1[i];
           ans   += word2[j];

            i++,j++;
        }

        if(i<sz1){
        while(i<sz1){
            ans += word1[i];
            i++;
        }
        }
        else{
        while(j<sz2){
            ans += word2[j];
            j++;
        }
        }
        
        
        return ans;
    }
};


int main(){
    string word1 , word2;

    cout<<"Enter two words  to merge them alternately :"<<endl;
    cin>>word1>>word2;

    Solution sol;

    string result = sol.mergeAlternately(word1,word2);

    return 0;
}
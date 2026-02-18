#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        for(int i=sz-1;i>=0;i--){

            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    Solution s;
    vector<int> digits = {9,9,9};
    vector<int> res = s.plusOne(digits);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
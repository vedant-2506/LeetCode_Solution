#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<stack>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {


        // //1st solution :  using sorting  TC=O(nlogn) ,SC=O(1)
        // int n=nums.size();

        // sort(nums.begin() , nums.end());

        // int ans=0;
        // for(int i=0; i<n; i++){
        //     if(nums[i] != i){
        //         return i;
        //     }
        // }
        // return n;


        //2nd sol: using hash table TC O(n) , SC=O(n)

        unordered_map<int ,int>un;

        for(int i=0; i<nums.size(); i++){
            un[ nums[i] ] = 1;
        }

        for(int j=0; j<nums.size(); j++){
            if( un.find( j ) == un.end()) return j;
        }

        return nums.size();


    }
};

int main(){
    Solution s;
    vector<int>nums={3,0,1};
    cout<<s.missingNumber(nums)<<endl;
    return 0;
}
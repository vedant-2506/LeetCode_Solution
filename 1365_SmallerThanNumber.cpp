#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        int n=nums.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){

                if( j != i  &&   nums[j] < nums[i]  ){

                    count++;
                }
            }
            ans[i]= count;
        }

        return ans;
        
    }
};

int main(){
    cout<<"Smaller than the current number"<<endl;

    vector<int>nums={6,5,4,8};

    Solution sol;
    vector<int>result;

    result = sol.smallerNumbersThanCurrent(nums);

    for(int i=0; i<nums.size(); i++){
        cout<<result[i]<<" " ;
    }

    return 0;


}
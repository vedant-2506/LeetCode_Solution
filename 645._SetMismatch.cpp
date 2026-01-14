#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>


using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int sz=nums.size();
        vector<int>ans(2);

        sort(nums.begin(), nums.end());
        for(int i=0;i<sz-1;i++){

            if(nums[i] == nums[i+1]){
                ans[0]= nums[i];
            }

            int sum = sz*(sz+1)/2;
            int sum_c=0;

            for(int j=0;j<sz;j++){
                sum_c += nums[j];
            }

            ans[1] = sum -(sum_c - ans[0]);

        }

        return ans;
        
    }
};

int main(){

    cout<<"Missing and Repeating Number"<<endl;

    vector<int>heights={1,2,3,3,5, 6,7};

    Solution sol;
    vector<int>result= sol.findErrorNums(heights);
    cout<<"["<<result[0]<<" , "<< result[1]<<"]"<<endl;
    
    return 0;
}
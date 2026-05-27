#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz=nums.size();
        set<vector<int>>st;

        sort(nums.begin() , nums.end());

        for(int i=0; i<sz; i++){
            int j=i+1 , k=sz-1 ;

            while( j<k ){
                int sum = nums[i] + nums[j] + nums[k] ;
                if( sum == 0){
                    vector<int> temp = { nums[i] , nums[j] , nums[k] };
                    st.insert(temp);
                    j++;
                    k--;
                }

                else if(sum < 0 ) j++;

                else k--;
            }
        }

        vector<vector<int>> ans( st.begin() , st.end() );
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);
    for(const auto& triplet : result){
        for(int val : triplet){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
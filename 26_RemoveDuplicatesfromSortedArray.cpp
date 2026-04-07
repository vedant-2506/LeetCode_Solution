#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            if(ans.empty() || ans.back() != nums[i]){
                ans.push_back(nums[i]); 
            }
        }

        for(int k=0; k<ans.size(); k++)
        {
            nums[k] = ans[k];
        }

       return ans.size();
    }
};


int main(){
    Solution s;
    vector<int>nums = {1,1,2,2,3,4,4,5};
    int newLength = s.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
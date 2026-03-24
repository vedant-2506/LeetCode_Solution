#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int , int>un;
        int sz=nums.size();

        for(int i=0; i<sz; i++){
            un[nums[i]] = 1;
        }

        vector<int>ans;
        for(int j=1; j<=sz; j++){
            if(un.find(j) == un.end() ){
                ans.push_back(j);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = sol.findDisappearedNumbers(nums);

    cout << "Disappeared numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
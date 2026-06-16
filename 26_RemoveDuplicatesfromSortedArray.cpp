#include<iostream>
#include<vector>
#include<set>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    //    //1st 2pointer approch TC = O(n) SC = O(1)
    //     int sz = nums.size();

    //     if(sz == 0 )return 0;

    //     int j=0;
    //     for(int i=1; i<sz; i++){
    //         if(nums[i] != nums[j]){
    //             j++;
    //             nums[j] = nums[i];
    //         }
    //     }

    //     return j+1;
        
    
    // //2nd extra array approch TC = O(n) SC = O(n)

    // int sz = nums.size();
    // vector<int>temp;
    // temp.push_back(nums[0]);
    
    // for(int i=1; i<sz; i++){
    //     if(nums[i] != nums[i-1]){
    //         temp.push_back(nums[i]);
    //     }
    // }

    // for(int j=0; j<temp.size(); j++){
    //     nums[j] = temp[j];
    // }

    // return temp.size();

    //3rd approch using set TC = O(nlogn) SC = O(n)
    set<int>st(nums.begin() , nums.end());
    
    int i=0;
    for(int x :st){
        nums[i++] = x;
    }

    return st.size();
    }
};
int main() {
    Solution s;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int newLength = s.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;

    cout << "Modified array: ";
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
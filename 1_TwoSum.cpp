#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       
    //    //*A two point approach TC = O(n^2)  SC = O(1) 
    //    //1)take i strt from 0 to n
    //    //2)take j strt from 1+1 to n 
    //    //3) check nums[i] + nums[j] == target 
    //    //4)if yes push in ans array i and j
    //    //5return ans array 
    //     int sz = nums.size();
    //     vector<int>ans(2);

    //     for(int i =0; i<sz; i++){
    //         for(int j=i+1; j<sz; j++){
    //             if(nums[i] + nums[j] == target ){
    //                 ans[0] = i;
    //                 ans[1] = j;
    //             }
    //         }
    //     }
    //     return ans;

        // //Using Hash table TC = O(n) SC = O(n)
        // //1)Take a loop of i 0 to n 
        // //2) under loop take x = target - nums[i]
        // //3)find x in hash table 
        // //4)if x in hastable ans[0] = i , ans[1] = um.[x]
        // //  else un[nums[i]] = i
        // //5)return ans arry 
        // int sz = nums.size();
        // unordered_map<int , int>un;
        // vector<int>ans(2); 

        // for(int i=0; i<sz; i++){
        //     int x = 0;
        //     x = target - nums[i];
        //     if(un.find( x ) != un.end() ){
        //         ans[0] = i;
        //         ans[1] = un[x];
        //     }
        //     else{
        //         un[nums[i]] = i;
        //     }
        // } 
        // return ans;



        //sorting + 2 pointer  TC = O(nlogn) SC = O(n)
        //1)Store 
        //2)Use two pointers i = 0 j = n-1
        //3) sum = nums[i] + nums[j] 
        //   if sum == target  ans[0] = i ans[1]=j
        //4)if sum < target  i++  if sum > target j--
       //5)return ans array 

        int n = nums.size();

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i}); // value, original index
        }

        sort(arr.begin(), arr.end());

        int i = 0;
        int j = n - 1;

        while(i < j) {

            int sum = arr[i].first + arr[j].first;

            if(sum == target) {
                return {arr[i].second, arr[j].second};
            }
            else if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {};

    }
};


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements in array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target value: ";
    cin >> target;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices are: ";
    cout << result[0] << " " << result[1] << endl;

    

    return 0;
}

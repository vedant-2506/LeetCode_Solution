#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //Hash Map + Max Heap TC=O(nlogn) SC=O(n)
        int sz=nums.size();
        if(sz == 1) return nums;

        unordered_map<int , int>un;
        for(auto i : nums){
            un[i]++;
        }
        priority_queue<pair<int , int>>heap;
        for(auto j : un){
            heap.push( {j.second , j.first});
        }
        vector<int>ans;
        while(k>0){
           ans.push_back(heap.top().second);
            heap.pop();
            k--;
        }
        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution s;
    vector<int> result = s.topKFrequent(nums, k);

    cout << "The top " << k << " frequent elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        //using sort fuction TC=(n^2 logn) SC=O(1)
        while(stones.size() >1){
            sort(stones.begin() , stones.end());
            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();
            stones.push_back(a-b);
        }
        if(stones.empty()) return 0;
        return stones[0];

        // //max heap TC=O(nlogn) SC=O(n)
        // priority_queue<int>heap(stones.begin() , stones.end() );
        // while(heap.size() > 1){
        //     int a = heap.top();
        //     heap.pop();
        //     int b = heap.top();
        //     heap.pop();
        //     heap.push(a-b);
        // }
        // return heap.top();

    }
};

int main() {
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;

    vector<int> stones(n);
    cout << "Enter the weights of the stones:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Weight of stone " << i + 1 << ": ";
        cin >> stones[i];
    }

    Solution s;
    int result = s.lastStoneWeight(stones);
    cout << "The weight of the last remaining stone is: " << result << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> aList(numCourses);

        // Create adjacency list
        for (auto p : prerequisites) {
            aList[p[1]].push_back(p[0]);
        }

        // Calculate indegree
        vector<int> inDegree(numCourses, 0);

        for (auto c : aList) {
            for (int i = 0; i < c.size(); i++) {
                inDegree[c[i]]++;
            }
        }

        // Push courses with indegree 0
        queue<int> q;

        for (int l = 0; l < numCourses; l++) {
            if (inDegree[l] == 0) {
                q.push(l);
            }
        }

        vector<int> ans;

        // BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(u);

            for (auto i : aList[u]) {
                inDegree[i]--;

                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        // If all courses are completed, return answer
        if (ans.size() == numCourses) {
            return ans;
        }

        // Cycle exists
        return vector<int>{};
    }
};

int main() {

    Solution obj;

    int numCourses;
    int numPrerequisites;

  

    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of prerequisite pairs: ";
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(
        numPrerequisites,
        vector<int>(2)
    );

    cout << "\nEnter prerequisite pairs [course prerequisite]:\n";
    cout << "Example: 1 0 means course 0 must be completed before course 1.\n\n";

    for (int i = 0; i < numPrerequisites; i++) {
        cout << "Pair " << i + 1 << ": ";
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> result = obj.findOrder(numCourses, prerequisites);

   

    if (result.empty()) {
        cout << "No valid course order exists.\n";
        cout << "A cycle exists in the prerequisites.\n";
    }
    else {
        cout << "Valid Course Order: ";

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;
    }

   

    return 0;
}
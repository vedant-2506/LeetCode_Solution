#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,  vector<string>& wordList) {

        // TC = O(N * L * 26 * L), SC = O(N * L)
        // N = number of words, L = word length
        unordered_set<string> dist(wordList.begin(), wordList.end());

        if (!dist.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                string original = word;
                for (int i = 0; i < word.size(); i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (word[i] == original[i]) continue;

                        if (dist.count(word)) {
                            q.push(word);
                            dist.erase(word);
                        }
                    }
                    word = original;
                }
            }
            level++;
        }

        return 0;
    }
};

int main() {
    Solution obj;

    string beginWord, endWord;
    int n;

    cout << "Enter begin word: ";
    cin >> beginWord;

    cout << "Enter end word: ";
    cin >> endWord;

    cout << "Enter number of words in word list: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of words!\n";
        return 0;
    }

    vector<string> wordList(n);

    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    int result = obj.ladderLength(beginWord, endWord, wordList);

    cout << "\nShortest transformation length: "
         << result << endl;

    return 0;
}

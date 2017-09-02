class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> distance;
        for (string& word : wordList) {
            distance[word] = -1;
        }
        if (distance.find(endWord) == distance.end()) return vector<vector<string>>();
        distance[beginWord] = 0;
        unordered_map<string, vector<string>> prev;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            if (word == endWord) break;
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (int j = 0; j < 26; ++j) {
                    if ('a' + j == word[i]) continue;
                    newWord[i] = 'a' + j;
                    if (distance.find(newWord) == distance.end()) continue;
                    if (distance[newWord] == -1) {
                        distance[newWord] = distance[word] + 1;
                        prev[newWord].push_back(word);
                        q.push(newWord);
                    } else if (distance[newWord] == distance[word] + 1) {
                        prev[newWord].push_back(word);
                    }
                }
            }
        }
        vector<vector<string>> paths;
        if (distance[endWord] == -1) return paths;
        vector<string> path;
        builder(paths, path, prev, endWord);
        return paths;
    }
private:
    void builder(vector<vector<string>>& paths, vector<string>& path, unordered_map<string, vector<string>>& prev, string& word) {
        path.push_back(word);
        if (prev[word].empty()) {
            vector<string> rpath = path;
            reverse(rpath.begin(), rpath.end());
            paths.push_back(rpath);
        } else {
            for (string& next : prev[word]) {
                builder(paths, path, prev, next);
            }
        }
        path.pop_back();
    }
};
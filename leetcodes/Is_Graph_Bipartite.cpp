class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> set(graph.size(), -1);
        vector<bool> visited(graph.size(), false);
        queue<int> q;
        for (int j = 0; j < graph.size(); j++) {
            if (visited[j])
                continue;
            q.push(j);
            set[j] = 1;
            int tog = 0;

            while (!q.empty()) {
                int n = q.size();

                while (n--) {
                    auto ele = q.front();
                    q.pop();
                    visited[ele] = true;
                    for (int i = 0; i < graph[ele].size(); i++) {
                        if (visited[graph[ele][i]]) {
                            if (set[graph[ele][i]] == tog) {
                                continue;
                            } else {
                                return false;
                            }
                        } else {
                            q.push(graph[ele][i]);
                            set[graph[ele][i]] = tog;
                        }
                    }
                }
                tog = !tog;
            }
        }
        return true;
    }
};
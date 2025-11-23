class Solution {
public:
    struct Segment {
        char ch;     
        bool star;   
    };

    vector<Segment> segments;
    string s;

    bool dfs(int i, int j, vector<vector<int>> &memo) {
        if (memo[i][j] != -1) return memo[i][j];

        if (j == segments.size())
            return memo[i][j] = (i == s.size());

        Segment seg = segments[j];

        if (!seg.star) {
            if (i < s.size() && (s[i] == seg.ch || seg.ch == '.')) {
                return memo[i][j] = dfs(i+1, j+1, memo);
            }
            return memo[i][j] = false;
        }

        if (dfs(i, j+1, memo))
            return memo[i][j] = true;

        if (i < s.size() && (s[i] == seg.ch || seg.ch == '.')) {
            if (dfs(i+1, j, memo))
                return memo[i][j] = true;
        }

        return memo[i][j] = false;
    }

    bool isMatch(string sInput, string p) {
        s = sInput;
        segments.clear();
        for (int i = 0; i < p.size(); i++) {
            if (i+1 < p.size() && p[i+1] == '*') {
                segments.push_back({p[i], true});
                i++;  
            } else {
                segments.push_back({p[i], false});
            }
        }
        vector<vector<int>> memo(s.size()+1, vector<int>(segments.size()+1, -1));

        return dfs(0, 0, memo);
    }
};

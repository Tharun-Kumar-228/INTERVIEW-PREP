class Solution {
public:
    long long minMoves(vector<int>& balance) {
        
        vector<int> arrs = balance;

        int n = arrs.size();
        long long total = 0;
        int negIdx = -1;

        for (int i = 0; i < n; i++) {
            total += arrs[i];
            if (arrs[i] < 0) negIdx = i;
        }

        
        if (total < 0) return -1;

        
        if (negIdx == -1) return 0;

        long long need = -arrs[negIdx];

        
        vector<pair<int, long long>> donors;

        for (int i = 0; i < n; i++) {
            if (i == negIdx || arrs[i] <= 0) continue;

            int dist = abs(i - negIdx);
            dist = min(dist, n - dist); 

            donors.push_back({dist, arrs[i]});
        }

        
        sort(donors.begin(), donors.end());

        long long moves = 0;

        for (auto &[dist, units] : donors) {
            if (need == 0) break;

            long long take = min(need, units);
            moves += take * dist;
            need -= take;
        }

        return (need == 0) ? moves : -1;
    }
};

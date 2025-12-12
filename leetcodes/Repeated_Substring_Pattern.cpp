class Solution {
public:
    
bool repeatedSubstringPattern(string s) {
    int n = s.size();

    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) { 
            string part = s.substr(0, len);
            bool ok = true;

            
            for (int i = len; i < n; i += len) {
                if (s.substr(i, len) != part) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;  
        }
    }

    return false;
}


};
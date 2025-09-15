class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rect) {
        map<long double,int> mp;
        long long count=0;
        for(int i=0;i<rect.size();i++){
            long double x = (long double) rect[i][0]/rect[i][1];
            mp[x]+=1; 
        }
        for(pair<long double,int> p:mp){
            long long b = p.second;
            count+= (b*(b-1)/2);
        }
    return count;
    }
};
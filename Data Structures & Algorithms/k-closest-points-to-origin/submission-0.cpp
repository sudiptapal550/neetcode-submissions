typedef pair<int,pair<int,int>> ipair;
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
        for(int i=0;i<points.size();i++){
            int a = points[i][0];
            int b = points[i][1];
            pq.push({(a*a) + (b*b),{a,b}});
        }
        vector<vector<int>>ans;
        while(k--){
            ipair pr = pq.top();
            pq.pop();
            ans.push_back({pr.second.first,pr.second.second});
        }
        return ans;
        
    }
};
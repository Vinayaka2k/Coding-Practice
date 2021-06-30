class Solution {
public:
    int getLeader(vector<int>& parent, int i){
        while(parent[i] != -1)
            i = parent[i];
        return i;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> res;
        vector<int> parent(n+1, -1);
        int i;
        for(i=0; i<edges.size(); ++i){
            int x = getLeader(parent, edges[i][0]);
            int y = getLeader(parent, edges[i][1]);
            if(x != y)
                parent[x] = y;
            else
                break;
        }
        res.push_back(edges[i][0]);
        res.push_back(edges[i][1]);
        return res;
    }
};
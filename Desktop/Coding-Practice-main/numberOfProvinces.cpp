class Solution {
public:
    int findLeader(vector<int>& parent, int i){
        while(parent[i] != -1)
            i = parent[i];
        return i;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n,-1);
        int x,y;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(isConnected[i][j]){
                    x = findLeader(parent, i);
                    y = findLeader(parent, j);
                    if(x != y)
                        parent[x] = y;
                }
            }
        }
        
        unordered_set<int> s;
        for(int i=0; i<n; ++i)
        {
            s.insert(findLeader(parent, i));
            cout << parent[i] << " ";
        }
        return s.size();
    }
};
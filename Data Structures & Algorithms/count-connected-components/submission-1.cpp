class Solution {
public:

    void dfs(int node,vector<int> &visited,vector<vector<int>> adj){
        visited[node]=1;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        
        }

        vector<int> visited(n,0);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                comp++;
                dfs(i,visited,adj);
            }
        }
        return comp;
    }
};

class Solution {
public:
    bool dfs(int node,int parent, vector<int> &visited, vector<vector<int>>& adj){
        visited[node]=true;

        for(int neighbour : adj[node]) {

            // Ignore the edge we came from
            if(neighbour == parent) {
                continue;
            }

            // Already visited -> cycle
            if(visited[neighbour]) {
                return false;
            }

            if(!dfs(neighbour, node, visited,adj)) {
                return false;
            }
        }
        return true;



    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n,0);

        if(!dfs(0,-1,visited,adj)){
            return false;
        }

        //check if all visited
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }
};

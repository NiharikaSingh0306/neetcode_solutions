class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=find(parent[x]);
    }
    //merging the gruops
    void Union(int u,int v){
        int rootU=find(u);
        int rootV=find(v);

        parent[rootU]=rootV;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(find(u)==find(v)){
                return {u,v};
            }
            Union(u,v);


        }
        return {};


    }
};

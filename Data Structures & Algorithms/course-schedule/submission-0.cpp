class Solution {
public:
    bool dfs(int course,vector<vector<int>>&adj,vector<int>&state){
        //cycle found
        if(state[course]==1){
            return false;
        }
        if(state[course]==2){
            return true;//alreadt checked
        }

        state[course]=1;//currentlr visitinf
        for(int nex:adj[course]){
            if(!dfs(nex,adj,state)){
                return false;
            }
        }
        state[course]=2;
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int p=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<p;i++){
            int u=prerequisites[i][0];//course
            int v=prerequisites[i][1];//prereq

            adj[v].push_back(u);
        }

        vector<int> state(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(!dfs(i,adj ,state)){
                    return false;
                }
            }
        }
        return true;



        
        
    }
};

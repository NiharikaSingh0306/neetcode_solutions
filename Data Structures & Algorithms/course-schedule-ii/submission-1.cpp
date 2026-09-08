class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int p=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);
        for(int i=0;i<p;i++){
            int u=prerequisites[i][0];//course
            int v=prerequisites[i][1];//prereq

            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int>q;
        vector<int> ans;

        //course with no prereq
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int course=q.front();
            q.pop();
            ans.push_back(course);

            for(int i:adj[course]){
                indeg[i]--;

                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};//cycle exist
        }

        return ans;

    }
};

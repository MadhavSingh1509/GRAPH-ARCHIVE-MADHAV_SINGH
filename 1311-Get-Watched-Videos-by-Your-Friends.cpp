class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
            map<string,int>m;

            int n=friends.size();
            vector<bool>vis(n,false);
            vis[id]=1;
            queue<int>q;
            q.push(id);
            int lvl=0;
            while(!q.empty()){
           int sz=q.size();
           if(lvl==level){
             while(sz--){
                auto node=q.front();
                q.pop();
                for(auto movie:watchedVideos[node])m[movie]++;
      

             }
             break;
           }
           while(sz--){auto u=q.front();
           q.pop();
           for(auto v:friends[u]){
            if(vis[v]==false){vis[v]=true;
            q.push(v);
            }

           }     }
           lvl++;
            }
        map<int,set<string>>m2;
        vector<string>ans;
        for(auto it:m){string m=it.first;
        int f=it.second;
        m2[f].insert(m);
        }
        for(auto it:m2){
            for(auto mov:it.second)ans.push_back(mov);
        }
return ans;
    }
};
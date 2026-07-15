class Solution {
public:
//this was a really good graph question
//a hard problem among hard ones
    int minOperations(string s, int k) {
        int n=s.size();
        // z zero hai,n-z one hai,i can choose k ze
        set<int>e;
        set<int>o;
        int z=0;
        for(auto c:s)if(c=='0')z++;
        if(z==0)return 0;
        queue<int>q;
        q.push(z);
        vector<int>op(n+1,-1);
        op[z]=0;
        for(int i=0;i<=n;i++){
            if(i%2==0)e.insert(i);
            else o.insert(i);
        }
        while(!q.empty()){
            auto currz=q.front();
            q.pop();
            int minz=currz+k-2*min(k,currz);
            int maxz=currz+k-2*max(0,k-n+currz);
            set<int>&st=minz%2==0?e:o;
            auto it=st.lower_bound(minz);
            while(it!=st.end()&&*it<=maxz){
                int newz=*it;
                if(newz==0)return op[currz]+1;
                if(op[newz]==-1){op[newz]=op[currz]+1;
                
                q.push(newz);}
                it=st.erase(it);
            }
        }
        return -1;
    }
};
class Solution {
public:
vector<int>ans;
int lim;
void f(int x){

if(x>lim)return;
ans.push_back(x);
 for(int j=0;j<=9;j++){
        int newx=x*10+j;
        
        f(newx);
    }
}
    vector<int> lexicalOrder(int n) {
        lim=n;
        for(int j=1;j<=9;j++)f(j);
        return ans;
    }
};
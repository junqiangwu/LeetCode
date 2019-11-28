#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        int res = 0;
        if(n <= 0) return 0;

        queue< pair<int,int> > q;
        vector<bool> visited(n+1,false);
        q.push(make_pair(n,0));

        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i=0; ; i++){
                int a = num - i*i;
                if(a<0) break;
                if (a==0) return step+1;
                if (!visited[a]){
                    q.push( make_pair(a,step+1));
                    visited[a]=true;
                }
            }
        }
        return res;
    }


    int numSquares2(int n) {
        int dp[n+1];
        memset(dp,0,n+1);
        for(int i=1; i<=n; i++){
            int minval = INT_MAX;
            for(int j =1; j*j<=i ;j++){
                int a = j*j;

                minval = min(minval,dp[i-j*j]);
            }
            dp[i] = minval+1;
        }
        return dp[n];
    }


};


int main() {

    int res = Solution().numSquares2(1);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
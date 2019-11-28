#include <iostream>
#include <vector>

using namespace std;

void Print_vec(vector<int> v){
    cout<<"[";
    for(auto i:v)
        cout<<i<<" ";
    cout<<"]"<<endl;
}

class Solution {
public:

    int maxProfit_v1(vector<int>& prices) {
        int len = prices.size();
        if(len<2) return 0;
        int res=0,tmp=0;
        for(int i=1;i<len;i++){
            tmp = max(tmp,0);
            tmp += prices[i] - prices[i-1];
            res = max(res,tmp);
        }
        return res;
    }

    int maxProfit_v2(vector<int>& prices) {
        int len = prices.size();
        if(len<2) return 0;
        int res=0,tmp=0;
        for(int i=1;i<len;i++){
            tmp = prices[i] - prices[i-1];
            if(tmp>0){
                cout<<tmp<<" ";
                res+= tmp;
            }
                cout<<endl;
        }
        return res;
    }

    int maxProfit_v3(vector<int>& prices) {
        int len = prices.size();
        if(len<2) return 0;
        vector<int> res;
        int tmp=0;
        for(int i=1;i<len;i++){
            tmp = prices[i] - prices[i-1];
            if(tmp>0){
                res.push_back(tmp);
            }
        }
        Print_vec(res);
        int res2;
        sort(res.begin(),res.end());
        Print_vec(res);

        int cnt=0;
        for(int i=res.size()-1; i>=0; i--){
            cout<<i<<" "<<res[i]<<" "<<res2<<endl;
            res2 += res[i];
            cnt+=1;
            if(cnt>=2) return res2;
        }
        return res2;
    }
};

int main() {
    vector<int> prices = {1,2,3,4,5};
    vector<int> prices_1 = {7,1,5,3,6,4};

    printf("v1: %d \n",Solution().maxProfit_v1(prices_1));
    printf("v2: %d \n",Solution().maxProfit_v2(prices_1));

    int result = Solution().maxProfit_v3(prices);

    cout<<result<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
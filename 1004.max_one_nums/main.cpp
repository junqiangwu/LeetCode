#include <iostream>

#include <vector>
using  namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        cout<<len<<endl;
        int l=0,r=-1;
        int res = 0;
        int count=0;

        while(l<len && r+1<len){

            if(A[++r]==0)
                count+=1;

            while(count >= K ){
                while(r+1<len && A[r+1]!=0){
                    r++;
                    std::cout << l <<' '<< r << std::endl;
                }
                res = max(res,r-l+1);
                if(A[l++]==0)
                    count-=1;
            }

        }
        return res;
    }
};

int main() {

    vector<int> A= {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int res = Solution().longestOnes(A,3);

    std::cout << res << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
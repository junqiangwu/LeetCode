#include <iostream>

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int mp[numCourses][numCourses];
        int in_degrees[numCourses];

        for(int i=0;i<numCourses;i++){
            for(int j=0;j<numCourses;j++)
                mp[i][j] = 0;
            in_degrees[i]=0;
        }

        for(int i=0;i<prerequisites.size();i++){
            int tar = prerequisites[i][0];
            int pre = prerequisites[i][1];
            in_degrees[tar] += 1;
            mp[pre][tar] = 1;
        }

        queue<int> head;
        for(int i=0;i<numCourses;i++){
            if(in_degrees[i] == 0)
                head.push(i);
        }

        int count=0;
        while(!head.empty()){
            int top = head.front();
            head.pop();
            count+=1;
            for(int i=0;i<numCourses;i++){
                if(mp[top][i]==1){
                    in_degrees[i] -= 1;
                    if(in_degrees[i] == 0)
                        head.push(i);
                }
            }
        }
        return count==numCourses;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int mp[numCourses][numCourses];
        int in_degrees[numCourses];
        vector<int> res;

        for(int i=0;i<numCourses;i++){
            for(int j=0;j<numCourses;j++)
                mp[i][j] = 0;
            in_degrees[i]=0;
        }

        for(int i=0;i<prerequisites.size();i++){
            int tar = prerequisites[i][0];
            int pre = prerequisites[i][1];
            in_degrees[tar] += 1;
            mp[pre][tar] = 1;
        }

        queue<int> head;
        for(int i=0;i<numCourses;i++){
            if(in_degrees[i] == 0)
                head.push(i);
        }

        int count=0;
        while(!head.empty()){
            int top = head.front();
            head.pop();
            count+=1;
            res.push_back(top);
            for(int i=0;i<numCourses;i++){
                if(mp[top][i]==1){
                    in_degrees[i] -= 1;
                    if(in_degrees[i] == 0)
                        head.push(i);
                }
            }
        }
        if (count == numCourses) return res;
        return vector<int> {};
    }

};



int main() {
//    vector<vector<int>> v = {{1,0},{2,0}};
    // [1,0],[2,0],[3,1],[3,2]
    vector<vector<int>> v = {{1,0},{2,0},{3,1},{3,2}};
    Solution solution;

    bool res = solution.canFinish(4,v);

    cout<<res<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
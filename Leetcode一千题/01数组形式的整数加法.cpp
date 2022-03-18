#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
        vector<int> res;
        int n = A.size();
        for (int i = n - 1; i >= 0; --i) {
            int sum = A[i] + K % 10;
            K /= 10;
            if (sum >= 10) {
                K++;
                sum -= 10;
            }
            res.push_back(sum);
        }
        for (; K > 0; K /= 10) {
            res.push_back(K % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
};

int main()
{
    vector<int> A, result;
    A.push_back(1);
    A.push_back(2);
    A.push_back(0);
    A.push_back(0);

    int K = 34;



    Solution s;
    result = s.addToArrayForm(A, K);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

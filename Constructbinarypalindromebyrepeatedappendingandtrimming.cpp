// No Graph Needed
// Trivial approach : O(n)
// For N = 8 and K=3
// 1. Initialize array of length N with 0's (by default in some languages). ------- [0,0,0,0,0,0,0,0]
// 2. Assign value '1' to 1st and multiple of K length apart elements from source. --------- [1,0,0,1,0,0,1,0]
// 3. Make all element '1' which are mirror reflection of element of array assigned '1' ----------- [1,1,0,1,1,0,1,1]
// 4. The resultant array is the answer
class Solution{
public:
    string binaryPalindrome(int n,int k)
    {
       // Complete the function
       string answer(n,'0');
       for(int i=0;i<n;i=i+k)
       {
           answer[i]=answer[n-i-1]='1';
       }
       return answer;
    }
};

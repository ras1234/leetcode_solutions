/*  Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
  */

  class Solution {
public:
    int numTrees(int n) {
       vector<int> countTrees(n+1);
       countTrees[0]=1;
       countTrees[1]=1;
       countTrees[2]=2;
       countTrees[3]=5;
       if(n<=3)
            return countTrees[n];
       int sum=0;
       int leftcount=0,rightcount=0;
       for(int i=4;i<=n;i++)
       {
          for(int j=1;j<=i;j++)
          {
                cout<<"j="<<j<<endl;
                leftcount=j-1;
                rightcount=i-j;
                sum=sum+(countTrees[leftcount]*countTrees[rightcount]);
          }
          countTrees[i]=sum;
          sum=0;
          
       }
       
       
       return countTrees[n]; 
    }
};
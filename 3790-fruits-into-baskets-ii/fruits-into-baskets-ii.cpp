class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
       int n=fruits.size();
       int cnt=0;
       for(int i=0;i<n;i++)
       {   bool place=false;
           for(int j=0;j<n;j++)
           {
              if(baskets[j]>=fruits[i])
              {
                place=true;
                baskets[j]=-1;
                break;
              }
             
           }
        if(!place)cnt++;
           
       }
       return cnt;
    }
};
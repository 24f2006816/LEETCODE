class Solution {
    public int maxArea(int[] height) {
        int left, right, m;
        m = height.length;
        left = 0;
        right = m-1;

        int maxWater = 0;
        while (left < right){
            int width = right-left;
            int containerHeight = Math.min(height[left], height[right]);

            int area = width * containerHeight;

            maxWater = Math.max(maxWater, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWater;
    }
}
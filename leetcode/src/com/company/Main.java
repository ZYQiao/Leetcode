package com.company;
import java.util.ArrayList;
import java.util.List;

class Solution{
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();

        if(numRows == 0){
            return list;
        }
        List<Integer> subList = new ArrayList<>();
        subList.add(1);
        list.add(subList);
        for(int i = 1; i < numRows; i++){
            subList = new ArrayList<>();
            subList.add(1);
            for(int j = 1; j < i; j++){
                subList.add(list.get(i-1).get(j-1)+list.get(i-1).get(j));
            }
            subList.add(1);
            list.add(subList);
        }
        return list;
    }
    public int removeDuplicates(int[] nums) {
        int len = 0;
        int j = 1;
        if(nums.length<= 1)return nums.length;
        while (j<nums.length){
            if (nums[len] != nums[j]) {
                nums[++len] = nums[j];
            }
            j++;
        }
        return len+1;
    }
    public int maxProfit(int[] prices) {
        int sum = 0;
        for(int i = 0; i+1 < prices.length; i++){
            if(prices[i]<prices[i+1]) sum+=prices[i+1]-prices[i];
        }
        return sum;
    }
}

public class Main {


    public static void main(String[] args) {
	// write your code here
        Solution s = new Solution();
//        List<List<Integer>> lists = s.generate(1);
//        for(List<Integer> list : lists){
//            for(int i : list){
//                System.out.print(i+" ");
//            }
//            System.out.println();
//        }

//        int[] nums = {0,0,1,1,1,2,2,3,3,4};
//        int len = s.removeDuplicates(nums);
//        for(int i = 0; i < len;i++){
//            System.out.println(nums[i]);
//        }

        int[] prices = {1,2,3,4,5};
        int profit = s.maxProfit(prices);
        System.out.println(profit);
    }
}

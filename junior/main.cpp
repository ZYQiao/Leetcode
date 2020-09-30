#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {

public:

    /**
     * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
     * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
     * @param nums
     * @return
     */
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){ return n;}
        int i = 0;
        for(int j = 1; j < n; j++){
            while(nums[i] == nums[j] && j < n-1) j++;
            if(j == n-1 && nums[i] == nums[j]) return ++i;
            nums[++i] = nums[j];
        }
        return i+1;
    }
    /**
     * 给你一个数组 nums和一个值 val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
     * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
     * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
     * @param nums
     * @param val
     * @return
     */
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n <= 0) return 0;
        if(n == 1 && nums[0] == val) return 0;
        int i = 0;
        for(int j = 0; j < n; i++,j++){
            if(nums[i] == val){
                while(nums[j] == val && j< n-1) j++;
                if(j == n-1 && nums[i] == nums[j]) return i;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return i;
    }
    /**
     * 给定一个haystack 字符串和一个 needle 字符串，
     * 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
     * 如果不存在，则返回 -1。
     */
    int strStr(string haystack, string needle) {
        int nn = needle.size(), nh = haystack.size();
        if(nh < nn) return -1;
        if(nn == 0) return 0;
        int i = 0;
        while(nh-i >= nn){
            if(haystack[i] == needle[0]){
                int tmp = i;
                for(int j = 0; j < nn; i++,j++) if(haystack[i] != needle[j]) break;
                if(i == tmp+nn) return tmp;
                i = tmp;
            }
            i++;
        }
        return -1;
    }
    /**
     * 给定两个整数，被除数dividend和除数divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
     * 返回被除数dividend除以除数divisor得到的商。
     * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
     */
    int divide(int dividend, int divisor) {
        bool sign = false;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) sign = true;
        int ans;
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        ans = div(dividend,divisor);
        if(sign){
            if(ans <= INT_MIN) return INT_MAX;
            return -ans;
        }
        return ans;

    }

    int div(int dividend, int divisor){
        if(dividend > divisor) return 0;
        int count = -1;
        int t = divisor;
        while(dividend - t <= t){
            t += t;
            count += count;
        }
        return count += div(dividend - t, divisor);
    }
    /**
     * 给定一个数组，它的第i 个元素是一支给定股票第 i 天的价格。
     * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
     * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
     */
    int maxProfit(vector<int>& prices) {
        int ans;
        for(int i = 0; i < prices.size()-1 ; i++){
            int k = prices[i+1] - prices[i];
            k>0?ans+=k:ans;
        }
        return ans;
    }
    /**
     * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
     * 输入: [1,2,3,4,5,6,7] 和 k = 3
     * 输出: [5,6,7,1,2,3,4]
     */
//    void rotate(vector<int>& nums, int k) {
//        int n = nums.size();
//        k%=n;
//        if(n <= 1|| k == 0) return ;
//        int *tmp = new int[k];
//        for(int i = n-k; i < n; i++)  tmp[i-n+k] = nums[i];
//        for(int i = n-1; i >= k; i--)    nums[i] = nums[i-k];
//        for(int i = 0; i < k; i++)  nums[i] = tmp[i];
//    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        if(n <= 1|| k == 0) return ;
        int tmp1 = 0, tmp2, init = 0;//tmp1 当前位置 tmp2 +k位置
        int rep, orig= nums[tmp1];//rep 用来保存+k位置的元素 orig 当前位置的元素
        for(int i = 0 ; i < n; i++){
            tmp2 = (tmp1+k)%n;
            rep = nums[tmp2];
            nums[tmp2] = orig;
            tmp1 = tmp2;//更新当前位置
            if(init == tmp1){//已经转换一轮了
                init = ++tmp1;
                orig = nums[tmp1];
            } else  orig = rep;//更新当前位置的元素
        }
    }
    /**
     * 给定一个整数数组，判断是否存在重复元素。
     * 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
     * 输入: [1,2,3,4]
     * 输出: false
     */
    bool containsDuplicate(vector<int>& nums) {
//        set<int> s;
//        for(int num:nums) s.insert(num);
//        return nums.size() != s.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }

};

int main() {

    //class Solution s;
    Solution s;
    vector<int> nums = {1,2,3,4,5,6};

    s.rotate(nums,3);
    for (int num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}

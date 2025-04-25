public class Solution {
    public double CalculateTax(int[][] brackets, int income) {
        var l = brackets.Length;
        int a = 0;
        double ans = 0;
        if (income == 0) return (double)0;
        for (int i = 0; i < l; i++) {
            var u  = brackets[i][0];
            var p = brackets[i][1];
            var r = (i == 0) ? u: brackets[i][0] - brackets[i -1][0];
            //if upper is bigger than the income just gonna tax all the money left
            if (u >= income) { //check if greater or equal is good
                ans += (income - a) * (p / (double)100);
                return ans;
            }
            else{
                ans += (r) * (p / (double)100);
                a += r;
            }
        }
        return ans;
    }
}
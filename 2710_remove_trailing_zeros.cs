public class Solution {
    public string RemoveTrailingZeros(string num) {
        /*
        string ans = ""; // ans = "454" 7
        string ans2 = "";
        var s = num.Length;
        bool band = false;
        for (int i = s-1; i > -1; i--){
            band = (num[i] == '0' && !band) ? false: true;
            ans += (band) ? num[i] : "";
        }
        s = ans.Length;
        for (int i = s-1; i >= 0; i--){
            ans2 += ans[i]; 
        }
        return ans2;
        var s = num.Length;
        int end = 0;
        for (int i = s - 1; i >= 0; i--) {
            if (num[i] != '0') {
                end = s - i - 1;
                break;
            }
        }
        var numt = BigInteger.Parse(num) / (BigInteger)Math.Pow(10,end);// 500 / 100 = 5
        return numt.ToString();
        var n = BigInteger.Parse(num);
        while (true) {
            if (n % 10 != 0) break;
            else{
                n = n / 10;
            }
        }
        return n.ToString();
        StringBuilder sb = new StringBuilder();
        StringBuilder ans2 = new StringBuilder();
        var s = num.Length;
        bool isZeros = true;
        for (int i = s - 1; i >= 0; i--) {
            isZeros = (num[i] == '0' && isZeros) ? true : false;
            sb.Append( (!isZeros) ? num[i] : "");
        }
        s = sb.Length;
        for (int i = s -1; i >= 0; i--) {
            ans2.Append(sb[i]);
        }
        return ans2.ToString();*/
        // XXXXXXXXXXXXXXXXXXXXXX0XXXXXXXXXXXXXXXXXXXXXXXXXXX
        StringBuilder sb = new StringBuilder();
        int i = num.Length - 1;
        
        // Skip trailing zeros
        while (i >= 0 && num[i] == '0') {
            i--;
        }
        
        // Append the remaining digits in the correct order
        for (int j = 0; j <= i; j++) {
            sb.Append(num[j]);
        }

        return sb.ToString();
    }
}
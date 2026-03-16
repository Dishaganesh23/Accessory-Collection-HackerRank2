import java.util.*;

public class Solution {

    static long sumRange(long a, long b) {
        long res1 = (b * (b + 1)) / 2;
        long res2 = (a * (a - 1)) / 2;
        return res1 - res2;
    }

    static long process(long L, long A, long N, long D) {

        if (A < D) return -1;

        if (D == 1) return L * A;

        long upperlimit = (N - 1) / (D - 1);
        long result = 0;

        for (long x = 1; x <= upperlimit; x++) {

            long extra = ((N - 1) - (D - 1) * x);

            if (extra + A * x < L) continue;

            long temp = extra * A;

            long num = (L - extra) / x;

            long subtotal = sumRange(A - num + 1, A);

            temp += subtotal * x;

            if ((L - extra) % x != 0) {
                long last = (L - extra) % x;
                temp += last * (A - num);
            }

            result = Math.max(result, temp);
        }

        if (result == 0) return -1;

        return result;
    }

    static String acessoryCollection(int L, int A, int N, int D) {

        long ans = process(L, A, N, D);

        if (ans == -1) return "SAD";

        return Long.toString(ans);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {

            int L = sc.nextInt();
            int A = sc.nextInt();
            int N = sc.nextInt();
            int D = sc.nextInt();

            String result = acessoryCollection(L, A, N, D);

            System.out.println(result);
        }

        sc.close();
    }
}

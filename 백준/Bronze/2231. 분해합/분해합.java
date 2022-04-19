import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int len, i, temp;
        int sum = 0;
        for (i = 1; i < n + 1; i++) {
            sum = i;
            temp = i;
            for (len = 0; len < (int) (Math.log10(i) + 1); len++) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == n) {
                System.out.println(i);
                scan.close();
                return;
            }
        }
        System.out.println(0);
        scan.close();
    }
}
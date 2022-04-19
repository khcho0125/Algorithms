import java.util.Scanner;

public class Main {

    private static int[] arr;

    public Main(int n) {
        arr = new int[n + 1];
    }

    public static void main(String[] args) throws InterruptedException {

        Scanner scan = new Scanner(System.in);

        int m = scan.nextInt();
        int n = scan.nextInt();
        int num, sum;
        new Main(n);
        arr[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            if (arr[i] != 1) {
                num = i;
                sum = num * 2;
                while (sum <= n) {
                    arr[sum] = 1;
                    sum += num;
                }
            }
        }
        for (int i = m; i < n + 1; i++) {
            if (arr[i] != 1)
                System.out.println(i);
        }
        scan.close();
    }
}
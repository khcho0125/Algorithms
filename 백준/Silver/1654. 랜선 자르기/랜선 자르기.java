import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();
        long count = 0;
        long mid = 0;
        long end = 0;
        long start = 1;
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
            if (end < arr[i])
                end = arr[i];
        }
        while (start <= end) {
            mid = (start + end) / 2;

            for (int i = 0; i < n; i++) {
                count += arr[i] / mid;
            }

            if (count < m) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            count = 0;
        }
        System.out.println(end);

        scan.close();
    }
}
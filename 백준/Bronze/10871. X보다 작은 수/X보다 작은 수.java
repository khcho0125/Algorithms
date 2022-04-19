import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int x = scan.nextInt();
        int num;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            num = scan.nextInt();
            arr[i] = num;
        }
        for (int i : arr) {
            if (i < x) {
                System.out.print(i + " ");
            }
        }
        scan.close();
    }
}
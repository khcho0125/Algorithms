import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int num;
        int max = 0;
        double result = 0;
        for (int i = 0; i < n; i++) {
            num = scan.nextInt();
            if (max < num) {
                max = num;
            }
            result += num;
        }

        System.out.println((result / max * 100) / n);
        scan.close();
    }
}
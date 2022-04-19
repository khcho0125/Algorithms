import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int g, k, result = 1;
        for (int i = 0; i < n; i++) {
            g = scan.nextInt();
            k = scan.nextInt();
            if (g == result || k == result) {
                result = (g == result) ? k : g;
            }
        }
        System.out.println(result);
        scan.close();
    }
}

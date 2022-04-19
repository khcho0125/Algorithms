import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int num, num2;
        for (int i = 0; i < n; i++) {
            num = scan.nextInt();
            num2 = scan.nextInt();
            System.out.println(num + num2);
        }
        scan.close();
    }
}
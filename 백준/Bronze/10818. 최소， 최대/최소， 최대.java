import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int num, max = 0, min = 0;
        for (int i = 0; i < n; i++) {
            num = scan.nextInt();
            if (i == 0) {
                min = num;
                max = num;
            }
            if (max < num)
                max = num;
            if (min > num)
                min = num;
        }
        System.out.println(min + " " + max);
        scan.close();
    }
}
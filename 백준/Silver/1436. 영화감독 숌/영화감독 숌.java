import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int i = 1;
        int result = 666;
        int test, six = 0;
        int count = 0;
        while (i != n) {
            result++;
            test = result;
            count = 0;
            while (test != 0) {
                six = test % 10;
                if (six == 6) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= 3) {
                    i++;
                    break;
                }
                test /= 10;
            }
        }

        System.out.println(result);

        scan.close();
    }
}
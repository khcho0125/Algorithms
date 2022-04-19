import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int result = 0;
        int num;
        for(int i = 0; i < 5; i++) {
            num = scan.nextInt();
            result += Math.pow(num, 2);
        }
        System.out.println(result % 10);
        scan.close();
    }
}
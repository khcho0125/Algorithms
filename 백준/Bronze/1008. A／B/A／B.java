import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        double a = scan.nextInt();
        double b = scan.nextInt();

        System.out.println(a / b);

        scan.close();
    }
}
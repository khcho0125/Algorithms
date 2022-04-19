import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int p = scan.nextInt();
        int q = scan.nextInt();
        if (p < 51 && q < 11) {
            System.out.println("White");
        } else if (q > 30) {
            System.out.println("Red");
        } else {
            System.out.println("Yellow");
        }
    }
}

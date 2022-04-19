import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        if(60 <= n && n <= 69) {
            System.out.println("D");
        }
        else if(70 <= n && n <= 79) {
            System.out.println("C");
        }
        else if(80 <= n && n <= 89) {
            System.out.println("B");
        }
        else if(90 <= n && n <= 100) {
            System.out.println("A");
        }
        else {
            System.out.println("F");
        }
        scan.close();
    }
}
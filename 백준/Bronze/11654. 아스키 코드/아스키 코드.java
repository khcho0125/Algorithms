import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        int n = str.charAt(0);
        System.out.println(n);
        scan.close();
    }
}
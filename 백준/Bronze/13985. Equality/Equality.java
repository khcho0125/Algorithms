import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        Scanner scan = new Scanner(System.in);
        String[] str = scan.nextLine().split(" ");
        if(Integer.parseInt(str[0]) + Integer.parseInt(str[2]) == Integer.parseInt(str[4])) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        scan.close();
    }
}
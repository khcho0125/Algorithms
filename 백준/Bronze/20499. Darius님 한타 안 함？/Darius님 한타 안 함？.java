import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] arr = new int[3];
        String[] str = scan.nextLine().split("/");
        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }
        if (arr[0] + arr[2] >= arr[1] && arr[1] != 0) {
            System.out.println("gosu");
        } else {
            System.out.println("hasu");
        }
        scan.close();
    }
}

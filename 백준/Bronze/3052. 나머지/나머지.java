import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] arr = new int[42];
        int n;
        int result = 0;
        for(int i = 0; i < 10; i++) {
            n = scan.nextInt();
            if(arr[n % 42] != 1) {
                result++;
                arr[n % 42] = 1;
            }
        }
        System.out.println(result);
        scan.close();
    }
}
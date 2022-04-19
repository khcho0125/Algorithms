import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int temp, idx, i;
        String tempstr;
        String[] str = new String[N + 1];
        int[] arr = new int[N + 1];
        for (i = 1; i < N + 1; i++) {
            arr[i] = scan.nextInt();
            str[i] = scan.nextLine();
        }
        for(i = 1; i < N + 1; i++) {
            
            temp = arr[i];
            tempstr = str[i];
            for(idx = i; arr[idx - 1] > temp; idx--) {
                arr[idx] = arr[idx - 1];
                str[idx] = str[idx - 1];
            }
            arr[idx] = temp;
            str[idx] = tempstr;
        }
        
        for (i = 1; i < N + 1; i++) {
            System.out.println(arr[i] + str[i]);
        }
    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        String[] str = scan.nextLine().split("");
        int[] arr = new int[26];
        int num;
        for(int i = 0; i < str.length; i++) {
            num = str[i].charAt(0) - 97;
            if(arr[num] == 0) {
                arr[num] = i + 1;
            }
        }
        for(int i : arr) {
            System.out.println(i - 1);
        }
        
        scan.close();
    }
}
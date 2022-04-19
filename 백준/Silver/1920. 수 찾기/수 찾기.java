import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int[] arr = new int[n];
        int min, max, dum, result;
        int arrMax = 0;
        for(int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
            if(arr[i] > arrMax) {
                arrMax = arr[i];
            }
        }
        Arrays.sort(arr);
        int m = scan.nextInt();
        int[] find = new int[m];
        for(int i = 0; i < m; i++) {
            find[i] = scan.nextInt();
            result = 0;
            if(find[i] <= arrMax) {
                max = n;
                min = 1;
                while(min <= max) {
                    dum = (min + max) / 2;
                    if(arr[dum - 1] == find[i]) {
                        result = 1;
                        break;
                    } else if(arr[dum - 1] > find[i]) {
                        max = dum - 1;
                    } else if(arr[dum - 1] < find[i]) {
                        min = dum + 1;
                    }
                }
            }
            find[i] = result;
        }

        for(int i = 0; i < m; i++) {
            System.out.println(find[i]);
        }
        
        scan.close();
    }
}
import java.util.Scanner;
public class Solution10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.close();
        int a = sc.nextInt();
        int b = sc.nextInt();
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        System.out.println(a);
    }
}
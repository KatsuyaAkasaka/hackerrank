import java.util.Scanner;
import java.math.BigDecimal;

class ExtraLongFactorials {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        BigDecimal big = new BigDecimal("1");
        while(x > 0){
            big = big.multiply(BigDecimal.valueOf(x));
            x--;
        }
        System.out.println(big);

    }
}

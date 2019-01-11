// Steven Kester Yuwono - UVa 748
/*
Lo resolvi usando bigInteger 
engorrosisisimo 
probe muhciisimo y le movi un buen hasta que jalo 
usar bigdecimal cuando me hablen de flotantes!!


*/
import java.util.*;
import java.io.*;
import java.math.BigDecimal;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		double r; int n;
		while(cin.hasNext()) {
			r = cin.nextDouble();
			n = cin.nextInt();
			BigDecimal bd = BigDecimal.valueOf(r);
			bd = bd.pow(n).stripTrailingZeros();
			String ans = bd.toPlainString();
			if (ans.charAt(0) == '0') ans = ans.substring(1);
			System.out.println(ans);
		}
	}
}
import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNext()){
			String n1,n2, op;
			n1 = sc.next();
			op = sc.next();			
			n2 = sc.next();
			BigInteger b1, b2;
			b1 = new BigInteger(n1);
			b2 = new BigInteger(n2);
			if(op.equals("/"))
				b1 = b1.divide(b2);
			else
				b1 = b1.mod(b2);
			System.out.println(b1);
		}
	}
}
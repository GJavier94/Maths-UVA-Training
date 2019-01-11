/*
Conversion de base 16 a base 2 y 10

*/


// import java.util.*;
// import java.math.*;

// class Main{
// 	public static void main(String[] args) {
// 		Scanner sc = new Scanner(System.in);
// 		StringBuilder sb = new StringBuilder();
// 		Integer n1, n2, nres;
// 		int cases = sc.nextInt();
// 		while(cases-- > 0 ){
// 			n1 = Integer.parseInt(sc.next(), 16);
// 			char op = sc.next().charAt(0);
// 			n2 = Integer.parseInt(sc.next(), 16);
// 			if(op == '+') nres = n1 + n2;
// 			else nres = n1 - n2;
// 			String b1,b2,bres;
// 			b1 = n1.toString(n1, 2);
// 			b2 = n2.toString(n2, 2);
// 			int l1, l2;
// 			l1 = b1.length();
// 			l2 = b2.length();
// 			for(int i = l1; i < 13; i++ ) sb.append("0");
// 			sb.append(b1);
// 			if(op == '+') sb.append(" + ");
// 			else sb.append(" - ");
			
// 			for(int i = l2; i < 13; i++ ) sb.append("0");
// 			sb.append(b2 + " = ");

// 			bres = nres.toString(nres, 10);
// 			sb.append(bres + "\n");
// 		}
// 		System.out.print(sb);
// 	}
// }


import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int cases = sc.nextInt();
		while(cases-- > 0 ){
			String n1, n2, op, n3;
			n1 = sc.next();
			op = sc.next();
			n2 = sc.next();
			Integer a1,a2,a3;
			a1 = Integer.parseInt(n1, 16);
			a2 = Integer.parseInt(n2, 16);
			if(op.equals("+")) a3 = a1 + a2;
			else a3 = a1 -  a2;
			String s1, s2 ,s3;
			s1 = a1.toString(a1, 2);
			s2 = a2.toString(a2, 2);
			int l1, l2;
			l1 = s1.length();
			l2 = s2.length();
			for(int i = l1; i < 13; i++) sb.append("0");
			sb.append(s1);
			sb.append(" "+ op + " ");
			for(int i = l2; i < 13; i++) sb.append("0");
			sb.append(s2 + " = ");

			s3 = a3.toString(a3, 10 );
			sb.append(s3 + "\n");
		}
		System.out.println(sb);
	}
}

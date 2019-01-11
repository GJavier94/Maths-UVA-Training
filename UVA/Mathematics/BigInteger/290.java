import java.util.*;
import java.math.*;

class Main{
	static boolean palindrome(String n){
		if(n.length() == 1) return true;
		int i = 0, j = n.length() - 1 , cont = n.length() / 2;
		while(n.charAt(i) == n.charAt(j) && cont != 0 ){ cont--;i++;j--;}
		if(cont == 0) return true;
		return false;
	}
	static int minBase(String n ){
		char maxChar = 0; int base;
		for(int i = 0 ; i < n.length(); i++)if(maxChar < n.charAt(i)) maxChar = n.charAt(i);
		if(Character.isDigit(maxChar)) base = (int)maxChar - '0';
		else base = (int)maxChar - 'A' + 10;
		return ++base;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String n;
		while(sc.hasNext()){
			boolean flag = true;
			n = sc.next();			
			String n1, n2, n3;
			BigInteger b1, b2, b3;
			for(int i = 15; i >= 2; i--){
				if(flag) flag = false;
				else  sb.append(" ");
				int steps = 0; n1 = n;
				if(i < minBase(n1)){
					sb.append("?");
					continue;
				}
				if(palindrome(n1)){sb.append(steps);continue;}
				do{					
					b1 = new BigInteger(n1, i);
					n2 = new StringBuffer(n1).reverse().toString();
					b2 = new  BigInteger(n2, i);
					b3 = b1.add(b2);
					n3 = b3.toString(i);
					n1 = n3;
					steps++;					
				}while(!palindrome(n3));				
				sb.append(steps);
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}
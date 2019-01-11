import java.util.*;
import java.math.*;

class ain{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String n;
		while(true){
			n = sc.next();
			if(n.charAt(0) == '-') break;
			Integer num = Integer.parseInt(n, 10);
			String res =  num.toString(num, 3);
			sb.append(res +'\n');
		}
		System.out.print(sb);
	}
}
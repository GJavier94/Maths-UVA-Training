import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String word;
		while(sc.hasNext()){
			word = sc.next();
			int sum = 0;
			for(int i = 0; i < word.length(); i++){
				if(Character.isUpperCase(word.charAt(i)))
					sum += (int)word.charAt(i) - 'A' + 27;
				else 
					sum += (int)word.charAt(i) - 'a' + 1;

				BigInteger b1 = new BigInteger.valueOf(sum);

				if(b1.isProbablePrime(10))
					sb.append("It is a prime word.\n");
				else
					sb.append("It is not a prime word.\n");
			}
		}
	}
}




















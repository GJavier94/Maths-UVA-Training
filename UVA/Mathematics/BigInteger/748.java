import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String n, p;
			n = sc.next();
			p = sc.next();
			int ind = n.length()-1;
			while(n.charAt(ind) == '0')ind--;
			int size = ind - n.indexOf('.');						

			int numdec =  (size) * Integer.parseInt(p);			
			String n1 = n.substring(0, n.indexOf('.'));
			String n2 = n.substring(n.indexOf('.') + 1, ind + 1);
			String n3 = n1 + n2;			
			BigInteger b1 = new BigInteger(n3);
			b1 = b1.pow(Integer.parseInt(p));
			String res = b1.toString();			
			String realres = "";

			if(n1.equals("0")){				
				int dif = Math.abs(numdec - res.length() ) ;				
				for(int i = 0; i< dif; i++) realres += '0';				
				System.out.print("."+realres);
				System.out.println(res);
			}else{

				for(int i = 0; i < res.length() -  numdec; i++){
					realres += res.charAt(i);
				}
				//System.out.println(realres);
				realres += ".";
				for(int i = res.length() -  numdec;  i < res.length(); i++ ){
					realres += res.charAt(i);				
				}
				System.out.println(realres);
			}

		}
	}
}
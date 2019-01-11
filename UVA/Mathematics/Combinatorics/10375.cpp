/*
lo tuve que subir en c porque en c++ me daba wrong answer
no tengo la menor idea de porque.

PROBLEMA obtner dos coeficientes binomiales y dividir osea c(p,q) / c(r,s)
 pero al hace la division puedo haber overflow

SOLUCION: 

c_pq = p.(p-1)...(p - q + 1)/ q!
c_rs = p.(p-1)...(r - s + 1) / s!

ans = c_pq /c_rs ( overflow)
hay que utilizar logaritmos

ans = e^log(c_pq/c_rs) donde log(c_pq/c_rs) = log(c_pq) - log(c_rs)
donde 
log(c_pq) = log(p.(p-1)...(p - q + 1)/q!) = log(p.(p-1)...(p - q + 1)/1.2...q) = log(p/1) + ... log(1/q) = log(p) -log(1) + ... log(1) -log(q)
log(c_rs) = log(p.(p-1)...(r - s + 1)/s!) = log(p.(p-1)...(r - s + 1)/1.2....s) = log(r/1) + ... log(1/s) = log(r)- log(1) +... log(1) -log(s)

todos esos logaritmos se tienen que tener precalculados
peroooooooo como los numeros valen hasta 10,000 solo hay que caluclar esos 

da wa en c++ (supongo deber haber un problema con la funcion log(1))
lo hago en C
	NUNCAAAAA OLVIDAR PONERLE RETURN  0 !!!!
	NUNCAAAAAA OLVIDAR HACER If(k > n -k ) k = n -k;  eso hace mas eficiente;
*/

#include <stdio.h>
#include <math.h>
#define SIZE 10001
long double a[SIZE];

int main(){
	int i, p, q, r, s;
	for(i = 1 ; i <= SIZE ; i++ ) a[i] = log(i);
	while(scanf("%d %d %d %d",&p, &q, &r, &s) == 4){	
		long double ans = 0;		
		if(q > p - q ) q = p - q;
		if(s > r - s ) s = r - s;
		for(i = 0; i < q; i++)
			ans += a[(p - i)] - a[(i + 1)];
		for(i = 0; i < s; i++)
			ans += -a[(r - i )] + a[(i + 1)];  	
		printf("%.5lf\n", exp(ans));
	}
	return 0;
}
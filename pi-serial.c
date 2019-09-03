#include <stdio.h>
#include <math.h>

// integrate $\sqrt{1-x^2}$ for $x \in (a,b)$ with $n$ sub-intervals.
double integrate_semicircle(double a, double b, int n) {
	double sum = 0.0;
	double h = (b-a) / n;
	double x0 = a + h/2.0;

	for (int i = 0; i < n; i++) {
		double x = x0 + i*h;
		sum += sqrt(1-x*x);
	}

	
	return sum * h;
}

int main() {
	double pi = 2 * integrate_semicircle(-1, 1, 1000*1000*100);
	printf("pi = %g\n", pi);
}

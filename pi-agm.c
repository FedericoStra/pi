#include <stdio.h>
#include <mpfr.h>

void pi_agm(mpfr_t pi, mpfr_prec_t prec, int niter) {
	mpfr_t a, b, an, bn, c, M, S;
	mpfr_inits2(prec, a, b, an, bn, c, M, S, (mpfr_ptr) 0);

	// a = 1
	mpfr_set_ui(a, 1, MPFR_RNDN);

	// b = 1/sqrt(2)
	mpfr_set_ui(b, 2, MPFR_RNDN);
	mpfr_rec_sqrt(b, b, MPFR_RNDN);

	// S = 1/4
	mpfr_set_ui_2exp(S, 1, -2, MPFR_RNDN);

	for (int i = 0; i < niter; i++) {
		// an = (a+b) / 2
		mpfr_add(an, a, b, MPFR_RNDN);
		mpfr_div_ui(an, an, 2, MPFR_RNDN);

		// bn = sqrt(a*b)
		mpfr_mul(bn, a, b, MPFR_RNDN);
		mpfr_sqrt(bn, bn, MPFR_RNDN);

		// mpfr_sub(c, bn, an, MPFR_RNDN);
		// 
		// printf("bn - an = ");
		// mpfr_out_str(stdout, 10, 0, c, MPFR_RNDN);
		// puts("");

		mpfr_sub(c, an, a, MPFR_RNDN);
		
		/* printf("c = "); */
		/* mpfr_out_str(stdout, 10, 0, c, MPFR_RNDN); */
		/* printf("\n"); */

		if (mpfr_zero_p(c)) {
			printf("break at i = %d\n", i);
			break;
		}

		mpfr_sqr(c, c, MPFR_RNDN);
		mpfr_mul_2si(c, c, i, MPFR_RNDN);

		mpfr_sub(S, S, c, MPFR_RNDN);

		mpfr_set(a, an, MPFR_RNDN);
		mpfr_set(b, bn, MPFR_RNDN);
	}

	mpfr_sqr(pi, a, MPFR_RNDN);
	mpfr_div(pi, pi, S, MPFR_RNDN);

	mpfr_clears(a, b, an, bn, c, M, S, (mpfr_ptr) 0);
}

int main() {
	mpfr_prec_t prec = 1000;
	int niter = 100;
	mpfr_t pi;
	mpfr_init2(pi, prec);

	pi_agm(pi, prec, niter);

	printf("pi = ");
	mpfr_out_str(stdout, 10, 0, pi, MPFR_RNDN);
	printf("\n");

	mpfr_clear(pi);
}

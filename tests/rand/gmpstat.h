/* gmpstat.h */

/* This file requires the following header files: gmp.h */

#ifndef	__GMPSTAT_H__
#define	__GMPSTAT_H__

/* Global debug flag.  FIXME: Remove. */
extern int g_debug;

/* Max number of dimensions in spectral test.  FIXME: Makw dynamic. */
#define GMP_SPECT_MAXT 10

void
mpf_freqt (mpf_t Kp,
	   mpf_t Km,
	   mpf_t X[],
	   const unsigned long int n);
unsigned long int
mpz_freqt (mpf_t V,
	   mpz_t X[],
	   unsigned int imax,
	   const unsigned long int n);

/* Low level functions. */
void
ks (mpf_t Kp,
    mpf_t Km,
    mpf_t X[],
    void (P) (mpf_t, mpf_t),
    const unsigned long int n);

void
ks_table (mpf_t p, mpf_t val, const unsigned int n);

void
x2_table (double t[],
	  unsigned int v);

void
spectral_test (mpf_t rop[], unsigned int T, mpz_t a, mpz_t m);
void
vz_dot (mpz_t rop, mpz_t V1[], mpz_t V2[], unsigned int n);
void
f_floor (mpf_t rop, mpf_t op);

void
merit (mpf_t rop, unsigned int t, mpf_t v, mpz_t m);
double
merit_u (unsigned int t, mpf_t v, mpz_t m);

/* From separate source files: */
void zdiv_round (mpz_t rop, mpz_t n, mpz_t d);

#endif /* !__GMPSTAT_H__ */

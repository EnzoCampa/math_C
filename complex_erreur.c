
#include <stdio.h>
#include <math.h>

/*foncntion x*/
struct complex_t
{
	double a;
	double b;
};

double complex_real(struct complex_t x2)
{
	return x2.a;
}
double complex_imag(struct complex_t x2)
{
	return x2.b;
}

int complex_div( struct complex_t* R, struct complex_t x, struct complex_t y ) {
	
	if ( (y.a == 0 ) && ( y.b == 0 ) ) {
		return -1 ;
	}
	
	R->a = ( x.a * y.a + x.b * y.b ) / ( pow(y.a,2.0) + pow(y.b,2.0) ) ;
	R->b = ( x.b * y.a - x.a * y.b ) / ( pow(y.a,2.0) + pow(y.b,2.0) ) ;
	
	return 0 ;
}



/*main*/

int main()
{	
	struct complex_t x1;
	struct complex_t y1;
	struct complex_t div;
	int erreur ;
	
	x1.a=2;
	x1.b=2;

	y1.a=2;
	y1.b=0;

	erreur = complex_div( &div, x1,y1) ;
	if ( erreur == 0 )
		printf("le resultat de la division est : %lf + %lfi\n",div.a,div.b);
	else
		printf("Division par zero\n") ;

	return 0;
}


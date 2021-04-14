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

/*addition de y+x*/

struct complex_t complex_add(struct complex_t x2, struct complex_t y2)
{
	struct complex_t r ;
	r.a = x2.a + y2.a ;
	r.b = x2.b + y2.b ;
	return r ;
}
/*multiplication de y+x*/

struct complex_t complex_mul(struct complex_t x2, struct complex_t y2)
{
	struct complex_t r_m ;
	r_m.a = x2.a * y2.a - x2.b * y2.b ;
	r_m.b = x2.a * y2.b + x2.b * y2.a ;
	return r_m ;
}

/*division de y+x*/

struct complex_t complex_div( struct complex_t x, struct complex_t y ) {
	struct complex_t r ;
	r.a = ( x.a * y.a + x.b * y.b ) / ( pow(y.a,2.0) + pow(y.b,2.0) ) ;
	r.b = ( x.b * y.a - x.a * y.b ) / ( pow(y.a,2.0) + pow(y.b,2.0) ) ;
	return r ;
}

/*module de x*/

double complex_module(struct complex_t x2)
{
	double mod = sqrt(pow(x2.a,2.0)+pow(x2.b,2.0)) ;
	return mod ;
}

/*main*/

int main()
{
	
struct complex_t x1;
x1.a=2;
x1.b=2;
struct complex_t y1;
y1.a=1;
y1.b=-3;
struct complex_t add;
struct complex_t mul;
struct complex_t div;
printf("le resultat est : %lf + %lfi\n",x1.a,x1.b);
printf("le resultat réel est : %lf \n", complex_real(x1));
printf("le resultat complexe est : %lfi \n", complex_imag(x1));
add = complex_add(x1,y1) ;
printf("le resultat de l'addition est : %lf + %lfi\n",add.a,add.b);
mul = complex_mul(x1,y1) ;
printf("le resultat de la multiplication est : %lf + %lfi\n",mul.a,mul.b);
div = complex_div(x1,y1) ;
printf("le resultat de la division est : %lf + %lfi\n",div.a,div.b);
printf("le resultat du module est : %lf \n", complex_module(x1));
printf("le resultat du conjugué est : %lf - %lfi\n", x1.a,x1.b);
printf("le resultat du conjugué est : %lf ", x1.a,x1.b);
return 0;
}


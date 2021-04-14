#include <stdio.h>
#include <math.h>

struct polynome
{
double tableau[100];
int degre;
};

double test(struct polynome P,char** erreur, double* delta)
{
    
    if ( P.degre != 2 ) {
		*erreur="polynome autre que de degré 2";
		}
	else {
	    *erreur="polynome de degré 2";
		double a=P.tableau[0];
		double b=P.tableau[1];
		double c=P.tableau[2];
		*delta=pow(b,2)-4*a*c;
}
}


double solut(struct polynome P,double delta,char** solution,double* x1, double* x2)
{
    double a=P.tableau[0];
	double b=P.tableau[1];
	double c=P.tableau[2];
    
if ( delta > 0)
    {
        *solution = "il existe 2 solution x1,x2";
        *x1=(-b + sqrt(delta))/2*a;
        *x2=(-b - sqrt(delta))/2*a;
    }
    else if ( delta == 0)
    {
        *solution = "il existe 1 solution x1";
        *x1=(-b + sqrt(delta))/2*a;
    }
    else
    {
        *solution = "il n'existe pas de solutions dans les réels";
    }
}

int main()
{	
	struct polynome P;
 
	P.degre = 2 ;
	P.tableau[0] = 1 ;
	P.tableau[1] = 2 ;
	P.tableau[2] = 1 ;

    char* erreur;
    double delta;
    test (P,&erreur,&delta);
    
    char* solution;
    double x1;
    double x2;
    solut(P,delta,&solution,&x1,&x2);
    
	printf("%lf\n",P.tableau[0]);
	printf("%s\n",erreur);
	printf("delta = %lf\n",delta);
	printf("%s\n",solution);
	printf("x1 = = %lf\n",x1);
	printf("x2 = %lf\n",x2);
	return 0;
	
}

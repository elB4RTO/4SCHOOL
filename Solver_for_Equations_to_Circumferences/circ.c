#include <stdio.h>
#include <math.h>

void getEquation() {
	float alfa , beta , r , a , b , c , conv = -2;
	unsigned int aa , bb , cc;
	// SET ALFA
	printf("\n\n\033[1;33mGET THE EQUATION GIVEN THE CENTER AND THE RADIUS\033[0m\n");
	printf("\nSET α : ");
	scanf("%f", &alfa );
	// SET BETA
	printf("\nSET β : ");
	scanf("%f", &beta );
	// SET RADIUS
	printf("\nSET r : ");
	scanf("%f", &r );

	// GET EQUATION
	a = conv * alfa;
	aa = a;
	b = conv * beta;
	bb = b;
	c = (alfa * alfa) + (beta * beta) - (r * r);
	cc = c;
	// PRINT EQUATION
	printf("\n\033[32mTHE EQUATION RESULTS AS\033[0m:\n\033[1m");
	printf(" +x² +y²");
	if (a >= 0) {
		printf(" +%ix", aa);
	} else {
		printf(" %ix", aa);
	}
	if (b >= 0) {
		printf(" +%iy", bb);
	} else {
		printf(" %iy", bb);
	}
	if (c >= 0) {
		printf(" +%i", cc);
	} else {
		printf(" %i", cc);
	}
	printf("\033[0m");
}

void getData() {
	float a , b , c , alfa , beta , r , conv = -2;
	unsigned int aalfa , bbeta , rr;
	int rad, u;
	// SET ALFA
	printf("\n\n\033[1;33mGET THE CENTER AND THE RADIUS (SQUARED) GIVEN THE EQUATION\033[0m\n");
	printf("\nWARNING: the equation must be already solved to have \033[1mx²\033[0m and \033[1my²\033[0m having value of \033[1m1\033[0m and being positive\n\n");
	printf("\nSET a : ");
	scanf("%f", &a );
	// SET BETA
	printf("\nSET b : ");
	scanf("%f", &b );
	// SET IL RAGGIO
	printf("\nSET c : ");
	scanf("%f", &c );

	// GET DATA
	alfa = a / conv ;
	aalfa = alfa;
	beta = b / conv;
	bbeta = beta;
	r = (alfa * alfa) + (beta * beta) - c;
	rr = r;
	// PRINT DATA
	printf("\n\033[32mTHE RESULTS ARE\033[0m:\n");

	printf(" \033[1mα  = ");
	printf(" %i\033[0m\n", aalfa);
			
	printf(" \033[1mβ  = ");
	printf(" %i\033[0m\n", bbeta);

	printf(" \033[1mr² = ");
	printf(" %i\033[0m\n", rr);
}

int main(void) {
	printf("\033[1;31mRESOLVER FOR EQUATIONS TO CIRCUMFERENCES\033[0m\n");

	int redo = 1 , w = 0;
	do {
		// MENU OF CHOICE
		int menu , m = 0;
		do {
			printf("\n\nOPTIONS:\n");
			printf("[\033[1m1\033[0m] Get the \033[1mEquation\033[0m given the Center and the Radius\n");
			printf("[\033[1m2\033[0m] Get the \033[1mCenter\033[0m and the \033[1mRadius\033[0m (squared) given the Equaztion\n\n");
			printf("CHOOSE ONE: ");
			scanf("%i", &menu );
			if ( menu == 1 || menu == 2 ) {
				m = 1;
			} else {
				printf("\n!!! ERROR: you must choose a valid option\n");
			}
		} while ( m != 1 );

		// GET THE EQUATION GIVEN THE CENTER AND THE RADIUS
		if ( menu == 1 ) {
			getEquation();
		}

		// GET THE CENTER AND THE RADIUS GIVEN THE EQUATION
		if ( menu == 2 ) {
			getData();
		}

		// ASK FOR REDO
		do {
		printf("\n\nREDO OR EXIT?");
		printf("\n[\033[1m0\033[0m] Exit\n[\033[1m1\033[0m] Redo\n");
		printf("CHOOSE ONE: ");
		scanf("%i", &redo);
		if ( redo == 1 || redo == 0 ) {
			w = 1;
			printf("\nBACK TO MAIN MENU\n");
		} else {
			printf("\n!!! ERROR: you must choose a valid option\n");
		}
		} while( w != 1 );
	} while( redo == 1 );
	printf("\n\nBYE\n");
	return 0;
}

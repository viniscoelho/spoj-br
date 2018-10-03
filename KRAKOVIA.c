#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXDIGITS 30
#define PLUS 1
#define MINUS -1

typedef struct {
	char digits[MAXDIGITS];
	int signbit;
	int lastdigit;
} bignum;

void add_bignum( bignum *a, bignum *b, bignum *c );
void subtract_bignum( bignum *a, bignum *b, bignum *c );
int compare_bignum( bignum *a, bignum *b );

int max( int a, int b ){
    if ( a > b ) return a;
    else return b;
}

void print_bignum( bignum *n ){
	int i;
	if ( n->signbit == MINUS ) printf("-");
	for ( i = n->lastdigit; i >= 0; i-- )
		printf("%c", '0' + n->digits[i]);
}

void int_to_bignum( int s, bignum *n ){
	int i, t;
	if ( s >= 0 ) n->signbit = PLUS;
	else n->signbit = MINUS;
	for ( i = 0; i < MAXDIGITS; i++ ) n->digits[i] = (char) 0;
	n->lastdigit = -1;
	t = abs(s);
	while ( t > 0 ){
		n->lastdigit++;
		n->digits[n->lastdigit] = (t % 10);
		t /= 10;
	}
	if ( s == 0 ) n->lastdigit = 0;
}

void begin_bignum( char s[], bignum *n ){
	int i, d = 0;
	if ( s[0] == '-' ) n->signbit = MINUS;
	else n->signbit = PLUS;
	
	for ( i = 0; i < MAXDIGITS; i++ ) n->digits[i] = (char) 0;
	n->lastdigit = -1;
	int pos = strlen(s)-1;
	if ( n->signbit == MINUS )
        while ( pos > 0 ){
			n->lastdigit++;
			n->digits[n->lastdigit] = (int)s[pos]-48;
			pos--;
        }
	else
		while ( pos >= 0 ){
			n->lastdigit++;
			n->digits[n->lastdigit] = (int)s[pos]-48;
			pos--;
		}
	if ( strcmp( s, "0" ) == 0 ) n->lastdigit = 0;
}

void initialize_bignum( bignum *n ){
	int i;
	n->signbit = PLUS;
	for ( i = 0; i < MAXDIGITS; i++ ) n->digits[i] = (char) 0;
	n->lastdigit = 0;
}

void zero_justify( bignum *n ){
	while ( ( n->lastdigit > 0 ) && ( n->digits[n->lastdigit] == 0 ) ) n->lastdigit--;
	if ( ( n->lastdigit == 0 ) && ( n->digits[0] == 0 ) ) n->signbit = PLUS;
}

void add_bignum( bignum *a, bignum *b, bignum *c ){
	int carry, i;
	
	initialize_bignum(c);
	if ( a->signbit == b->signbit ) c->signbit = a->signbit;
	else{
		if ( a->signbit == MINUS ){
			a->signbit = PLUS;
			subtract_bignum(b, a, c);
			a->signbit = MINUS;
		}
		else{
			b->signbit = PLUS;
			subtract_bignum(a, b, c);
			b->signbit = MINUS;
		}
		return;
	}
	
	c->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
	carry = 0;
	
	for ( i = 0; i <= (c->lastdigit); i++ ){
		c->digits[i] = (char) ( carry + a->digits[i] + b->digits[i] ) % 10;
		carry = ( carry + a->digits[i] + b->digits[i] ) / 10;
	}
	zero_justify(c);
}

void subtract_bignum( bignum *a, bignum *b, bignum *c ){
	int borrow, i, v;
	initialize_bignum(c);
	if ( ( a->signbit == MINUS ) || ( b->signbit == MINUS ) ){
		b->signbit = -1 * b->signbit;
        add_bignum(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
	}
	
	if ( compare_bignum(a, b) == PLUS ){
		subtract_bignum(b, a, c);
        c->signbit = MINUS;
        return;
	}
	
	c->lastdigit = max(a->lastdigit, b->lastdigit);
	borrow = 0;
	
	for ( i = 0; i <= (c->lastdigit); i++ ){
		v = ( a->digits[i] - borrow - b->digits[i] );
		if ( a->digits[i] > 0 ) borrow = 0;
		if ( v < 0 ){
			v = v + 10;
            borrow = 1;
		}
		c->digits[i] = (char) v % 10;
	}
	zero_justify(c);
}

int compare_bignum( bignum *a, bignum *b ){
    int i;

    if ( ( a->signbit == MINUS ) && ( b->signbit == PLUS ) ) return(PLUS);
    if ( ( a->signbit == PLUS ) && ( b->signbit == MINUS ) ) return(MINUS);

    if ( b->lastdigit > a->lastdigit ) return (PLUS * a->signbit);
    if ( a->lastdigit > b->lastdigit ) return (MINUS * a->signbit);

    for ( i = a->lastdigit; i >= 0; i-- ){
		if ( a->digits[i] > b->digits[i] ) return(MINUS * a->signbit);
        if ( b->digits[i] > a->digits[i] ) return(PLUS * a->signbit);
    }
    return 0;
}

void digit_shift( bignum *n, int d ){
	int i;
	if ( ( n->lastdigit == 0 ) && ( n->digits[0] == 0 ) ) return;
	for ( i = n->lastdigit; i >= 0; i-- )
		n->digits[i+d] = n->digits[i];
	for ( i = 0; i < d; i++ ) n->digits[i] = 0;
	n->lastdigit = n->lastdigit + d;
}

void multiply_bignum( bignum *a, bignum *b, bignum *c ){
	bignum row, tmp;
	int i, j;
	
	initialize_bignum(c);
	
	row = *a;
	
	for ( i = 0; i <= b->lastdigit; i++ ){
		for ( j = 1; j <= b->digits[i]; j++ ){
			add_bignum(c, &row, &tmp);
			*c = tmp;
		}
		digit_shift(&row, 1);
	}
	c->signbit = a->signbit * b->signbit;
	zero_justify(c);
}

void divide_bignum( bignum *a, bignum *b, bignum *c ){
	bignum row, tmp;
	int asign, bsign;
	int i, j;
	initialize_bignum(c);
	c->signbit = a->signbit * b->signbit;

	asign = a->signbit;
	bsign = b->signbit;

	a->signbit = PLUS;
	b->signbit = PLUS;

	initialize_bignum(&row);
	initialize_bignum(&tmp);

	c->lastdigit = a->lastdigit;

	for ( i = a->lastdigit; i >= 0; i-- ){
		digit_shift(&row, 1);
		row.digits[0] = a->digits[i];
		c->digits[i] = 0;
		while ( compare_bignum(&row, b) != PLUS ){
			c->digits[i]++;
			subtract_bignum(&row, b, &tmp);
			row = tmp;
		}
	}
	zero_justify(c);

	a->signbit = asign;
	b->signbit = bsign;
}

int main(){
    int a, b, i, c = 1;
    bignum n1, n2, n3, zero;
    char num[MAXDIGITS];
    for ( scanf("%d %d",&a, &b); a != 0 && b != 0; scanf("%d %d",&a, &b) ){
        initialize_bignum(&n2);
        for ( i = 0; i < a; ++i ){
            scanf(" %s",&num);
            begin_bignum(num, &n1);
            add_bignum(&n1, &n2, &n3); /*n3 = n1 + n2*/
            n2 = n3;
        }
        int_to_bignum(b, &n1); /*n1 = b*/
        divide_bignum(&n2, &n1, &n3); /*n3 = n2 / n1*/
        printf("Bill #%d costs ", c++);
        print_bignum(&n2);
        printf(": each friend should pay ");
        print_bignum(&n3);
        printf("\n\n");
    }
    return 0;
}

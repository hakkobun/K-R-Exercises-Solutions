#include<stdio.h>
#define substitute karma

int x, f3();

int f3()
{
	struct testing {
		int a, b;
	};

}

typedef int karma;
typedef karma again;
typedef karma newtype;
typedef int t1, t2, t3;

t1 r1 = 2;
t2 r2 = 3;
t3 r3 = 4;

typedef struct runningOutOfIdea
{
	int a, b, c;
} tx1, tx2;

void test3()
{
	{

	}
	typedef int xx;
	tx1 jj;
	jj.a = 12;
	jj.b = 22;
	jj.c = 33;
	printf("test3: %d %d %d\n", jj.a, jj.b, jj.c);
	xx m;
}
/* out of scope xx m; */

typedef struct
{
	int a, b, c;
} tpp;

void test4()
{
	tpp mjk;
	mjk.a = 1;
	mjk.b = 2;
	mjk.c = 3;
	printf("test4: %d %d %d\n", mjk.a, mjk.b, mjk.c);
}

typedef struct aaa {
	int a[3];

} aNew ;

typedef int aaa;

struct smallThing {
		int c;
		int d;
} p(char romeo, int karkar), k1, k2, k3 = {3,2}; 

struct bigThing {
	karma a;
	karma b;

	struct smallThing Samasak;
	struct smallThing Samasak2;

};

struct smallThing p(char romeo, int karkar)
{
	struct smallThing temp;
	temp.c = 0;
	temp.d = -1;
	return temp;
}

struct newtype {
	

	int b;
};

int func2(int a, int b)
{
	a+=2;
	return a;
}

int function(int doNotcountMe, char (*doNotcountMeToo)(), struct smallThing tt);

int foo(), arr[2] = {9};

void test1()
{
	int b, ((*a)) = &b, ((*c)[]);
	b = 5;
	printf("test1: %d\n", *a);

}

#define MAX(a,b) ((a>b) ? a:b)

void test2()
{
	int b = 5, c = 4;
	int j;
	int a = MAX(b, j);

}


int main()
{
	{
		typedef int jieow;
		jieow k = 32;
	}

	{
		int k, l, ap(char c) ;

	}
	test3();
	test4();

	test1();


	char (*arg[/*char c*/]) = {"char x", "char y", "char z"}, arg2[][40][40] = {{"}}char u", "char v"}, {"char w", "char y"}};	
	
	printf("arg:\n%s\n%s\n%s\n", *arg, arg[1], arg[2]);

	printf("arg2:\n%s\n%s\n", arg2[0][0], arg2[1][1]);


	printf("%d %d %d\n", r1, r2, r3);
	printf("func2 = %d\n", func2(3,4));

	struct smallThing x;
	
	x = p('2', 3);

	char string[] = "eiowi\"iowinei\\";

	int a, ***b,    c[7],		 *d[125], (*(*(*e(char *p, int k))[])(char x2, char x3))[], f, g[][3] = {{0,1}, {1}}, (h) [] = {1,2};


	int m, func();

	printf("%d", func());

	char s1[] = "ewjiojoiew", s2[] = "wejiogjiw", s3[30];

	s3[0] = '3';

	printf("%s\n%s\n", s1, s2);


	int i1[] = {1,2,3,4,5,6}, i2[20];
	printf("%d %d\n",i1[0], i2[2]);

	return 0;
}

int func()
{
	return 0;
}
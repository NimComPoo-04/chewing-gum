#include <stdio.h> // for the puts() and the printf() functions
#include <stdlib.h> // for the atoi() function

/* The list of function used */
void MyDef(int,char*);
void RightTriangle(int,char*);

int main(int argc, char** args)
{
	if( argc <= 1) return 0 ;// a guard to prevent seg fault

	void(*PrintPat)(int,char*) ; // this is used to reduce the complexecity int switch 
	
	switch(atoi(args[1])) // this switch statement assigns the value of PrintPat
	{
		case  1 : // this is the |\ thing 
			PrintPat = RightTriangle ;
		break ;
		default :
			PrintPat = MyDef ; // this is the default value
	}

	// this is the main meat of the program and this prints the value
	if(argc <= 3)
		PrintPat(atoi(args[2]), "*");
	else 
		PrintPat(atoi(args[2]), args[3]);
}

/* This prints a right angle tringle in the console */
void RightTriangle(int a, char* c)
{
	for( int i = 0 ; i < a*a ; i++)
	{
		printf("%s",c) ;
		if(i/a == i%a)
			puts("") ; 
	}
}

void MyDef(int len, char* c) // this function will print an error message
{
	puts("We dont have that with us!!");
}

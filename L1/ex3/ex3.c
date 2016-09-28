/*************************************
 * Lab 1 Exercise 3
 * Name     : Luah Bao Jun
 * Matric No: A0126258A
 * Lab Group: 4
 *************************************/

#include <stdio.h>
#include <stdlib.h> //for malloc()

// Declaration of coordinates
typedef struct COORDINATE {
	int x;
	int y;
} coordinate;

typedef void (*ftnptr) (coordinate*, int);

//Function Prototypes
void up(coordinate*, int);
void down(coordinate*, int);
void left(coordinate*, int);
void right(coordinate*, int);

int main()
{
	ftnptr pointer[4] = {up, down, left, right};
	coordinate* ptr = (coordinate*) malloc(sizeof(coordinate));
	int movement, steps;

	ptr->x = 0;
	ptr->y = 0;

	while(scanf("%i %i", &movement, &steps) == 2) {
		(*pointer[movement - 1])(ptr, steps);
		printf("%i %i\n", ptr->x, ptr->y);
	}

	return 0;
}

void up(coordinate* ptr, int steps)
{
	ptr->y += steps;
}

void down(coordinate* ptr, int steps)
{
	ptr->y -= steps;
}

void left(coordinate* ptr, int steps)
{
	ptr->x -= steps;
}

void right(coordinate* ptr, int steps)
{
	ptr->x += steps;
}

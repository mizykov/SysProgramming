typedef struct
{
	double* objects;
	int head;
	int stackSize;
} my_stack;

my_stack* Stack ( int stackSize );

int desStack ( my_stack* Stack );

int isEmpty ( my_stack* Stack );

int isFull ( my_stack* Stack );

double pop ( my_stack* Stack );

int push ( my_stack* Stack, double Data );

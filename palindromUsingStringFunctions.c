// checking whether a number or string is Palindrome or not using string librery functions.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void checkPalindrome()
{
	char inputString[20], *ch, *copyInput;
	int len;
	printf("\nEnter a number or word: ");
	//fgets(inputString, 19, stdin);
	scanf("%s", inputString);
	
	len = strlen(inputString);	// it returns the length of the string.
	copyInput = (char *)malloc(len*sizeof(char));	// dynamically allocating memory for coping the input array
	strcpy(copyInput, inputString);	// coping the input string into alloted memory
	
	ch = strrev(inputString);	// reversing the input string and storing into the same array
	
	
	if(strcmpi(copyInput, inputString) == 0)
		printf("%s is palindrome", copyInput);
	else
		printf("%s is not palindrome", copyInput);
}

void palindromesInRange()
{
	int start, finish,i, temp, rem;
	
	printf("\nEnter the starting number: ");
	scanf("%d", &start);
	printf("\nEnter the ending number: ");
	scanf("%d", &finish);
	
	printf("Palindrome numbers from %d to %d are: ", start, finish);
	
	for(i = start; i<=finish; i++)
	{
		temp = i;
		rem = 0;
		while(temp!=0)
		{
			rem = rem*10 + (temp%10);
			temp=temp/10;
		}
		if(rem == i)
		{
			printf("%d ", i);
		}
	}
}

int main()
{
	int option;
	printf("1. To Check Palindrom or Not.");
	printf("\n2. To find Palindrom numbers in a range.");
	printf("\n3. To exit the program.");
	printf("\n\nChoose Your option: ");
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			checkPalindrome();
			break;
		case 2:
			palindromesInRange();
			break;
		case 3:
			exit(0);
		default:
			break;
	}
	
	return 0;
}

/*
	strcmp() and strcmpi() both compares two strings but strcmp() is case sensitive (i.e. in strcmp() 'A' and 'a' are different) but strcmpi() is case insensitive
	(i.e. in strcmpi() 'A' and 'a' are same).
	
	malloc() returns a void pointer of the first memory address allocated dynamically by it. 
	We need to type cast that void pointer. (char *) doing exactly the same here, it typecasts the void pointer into character type pointer.
*/

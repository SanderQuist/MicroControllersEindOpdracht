/*
Naam: Sander Quist
Studentnummer: 2130034
Datum: 20-03-2019
Groep: 2A8
*/

//includes for this C file
#include <avr/io.h>
#include "ledmatrix.h"
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

//Defines the F_cpu
#define F_CPU 8000000

//Rows of display
char allrows[8] = {0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E};
char letterrows[6] = {0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C};

//All the letters of the alphabet
char letter_A[6] = {0x9F, 0x24, 0x24, 0x24, 0x24, 0x9F};
char letter_B[6] = {0xBF, 0xA4, 0xA4, 0xA4, 0xA4, 0x1B};
char letter_C[6] = {0x1F, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0};
char letter_D[6] = {0xBF, 0xA0, 0xA0, 0xA0, 0xA0, 0x1F};
char letter_E[6] = {0xBF, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4};
char letter_F[6] = {0xBF, 0x24, 0x24, 0x24, 0x24, 0x24};
char letter_G[6] = {0xBF, 0xA0, 0xA0, 0xA4, 0xA4, 0xA7};
char letter_H[6] = {0xBF, 0x04, 0x04, 0x04, 0x04, 0xBF};
char letter_I[6] = {0xA0, 0xA0, 0xBF, 0xBF, 0xA0, 0xA0};
char letter_J[6] = {0x01, 0x80, 0xA0, 0xA0, 0xA0, 0x3F};
char letter_k[6] = {0xBF, 0x04, 0x04, 0x0A, 0x11, 0xA0};
char letter_L[6] = {0xBF, 0x80, 0x80, 0x80, 0x80, 0x80};
char letter_M[6] = {0xBF, 0x10, 0x08, 0x08, 0x10, 0xBF};
char letter_N[6] = {0xBF, 0x10, 0x08, 0x04, 0x02, 0xBF};
char letter_O[6] = {0x1F, 0xA0, 0xA0, 0xA0, 0xA0, 0x1F};
char letter_P[6] = {0xBF, 0x24, 0x24, 0x24, 0x24, 0x18};
char letter_Q[6] = {0xBF, 0xA0, 0xA0, 0xA4, 0x3F, 0x80};
char letter_R[6] = {0xBF, 0x24, 0x24, 0x26, 0x25, 0xB0};
char letter_S[6] = {0x98, 0xA4, 0xA4, 0xA4, 0xA4, 0x23};
char letter_T[6] = {0x20, 0x20, 0xBF, 0xBF, 0x20, 0x20};
char letter_U[6] = {0x3F, 0x80, 0x80, 0x80, 0x80, 0x3f};
char letter_V[6] = {0x38, 0x07, 0x80, 0x80, 0x07, 0x38};
char letter_W[6] = {0x3F, 0x80, 0x0F, 0x0F, 0x80, 0x3F};
char letter_X[6] = {0xB1, 0x1B, 0x0E, 0x0E, 0x1B, 0xB1};
char letter_Y[6] = {0x20, 0x10, 0x8F, 0x8F, 0x10, 0x20};
char letter_Z[6] = {0xA1, 0xA2, 0xA4, 0xA8, 0xB0, 0xA0};
	
//Int arrays for letters
int A[5] = {0x3e, 0x09, 0x09, 0x09, 0x3e};
int B[5] = {0x3f, 0x25, 0x25, 0x25, 0x1a};
int C[5] = {0x1e, 0x21, 0x21, 0x21, 0x21};
int D[5] = {0x3f, 0x21, 0x21, 0x21, 0x1e};
int E[5] = {0x3f, 0x25, 0x25, 0x21, 0x21};
int F[5] = {0x3f, 0x05, 0x05, 0x05, 0x01};
int G[5] = {0x3f, 0x21, 0x25, 0x25, 0x3d};
int H[5] = {0x3f, 0x04, 0x04, 0x04, 0x3f};
int I[5] = {0x21, 0x21, 0x3f, 0x21, 0x21};
int J[4] = {0x31, 0x21, 0x21, 0x3f};
int K[4] = {0x3f, 0x04, 0x0a, 0x31};
int L[4] = {0x3f, 0x20, 0x20, 0x20};
int M[5] = {0x3f, 0x01, 0x07, 0x01, 0x3f};
int N[5] = {0x3f, 0x02, 0x04, 0x08, 0x3f};
int O[5] = {0x3f, 0x21, 0x21, 0x21, 0x3f};
int P[5] = {0x3f, 0x09, 0x09, 0x09, 0x06};
int Q[5] = {0x06, 0x09, 0x09, 0x09, 0x3f};
int R[5] = {0x3f, 0x09, 0x19, 0x29, 0x06};
int S[5] = {0x16, 0x25, 0x25, 0x29, 0x1a};
int T[5] = {0x01, 0x01, 0x3f, 0x01, 0x01};
int U[6] = {0x0f, 0x10, 0x10, 0x10, 0x08, 0x1f};
int V[5] = {0x07, 0x08, 0x10, 0x08, 0x07};
int W[5] = {0x1f, 0x20, 0x1c, 0x20, 0x1f};
int X[5] = {0x11, 0x0a, 0x04, 0x0a, 0x11};
int Y[5] = {0x22, 0x14, 0x08, 0x04, 0x02};
int Z[6] = {0x41, 0x61, 0x51, 0x49, 0x45, 0x43};
int emptySpace[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int space[1] = {0x00};

//Methodes
void write_letter();
void clear_display();
void write_text_to_screen();
void write_board_data(int* text);
void set_offset();
void wait();
void init_letters();

//Variables
int offset = 0;
int counter = 0;

//Set the size of the text including spaces.
//Set the text you want to write on the display.
int size_of_tekst = 10;
char string[] = "send nudes";

/************************************************************************/
/* The main first clears the display.
After that it will initialize the matrix screen and wait a bit.
In the while loop the init_letters method builds the string above this description.
The offset will be set to make the display scroll.                                                                     */
/************************************************************************/

int main(void){
	clear_display();
	init_matrix_screen();
	wait(500);
	
	while (1)
	{
		init_letters();
		set_offset();
		wait(500);
	}
}

/************************************************************************/
/* Test method to write one letter.
The first parameter of the write_data method is the rows on which the letter will be written.
The second parameter is the letter you want to display.                                                                     */
/************************************************************************/

void write_letter(void){
	for(int i = 0; i < 6; i++){
		write_data(letterrows[i], Z[i]);
	}
}

//Method to clear the complete display.
void clear_display(){
	for(int i=0; i < 8; i++){
		write_data(allrows[i], 0);
	}
}

//Writes the text to the board itself.
void write_board_data(int* text)
{
	char columnValue = 0;
	int value = 8;
	for(int row = 0; row < 8; row++)
	{
		columnValue = text[value + offset];
		write_data(allrows[row],columnValue);
		value--;
	}
}

//The display will scroll by changing the offset.
 void set_offset(void){
 	offset++;
 	if(offset > counter){
 		offset = 0;
 	}
 }
//This will initialize the 8x8 dot matrix display.
void init_matrix_screen(void){
	twi_init();
	
	DDRA = 0b11111111;

	EICRB |= 0b11000000; //set INT7 faling edge
	EIMSK |= 0b10000000; //enable INT&
}

//This method is used to make the program wait.
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/************************************************************************/
/*The init letters method puts the arrays of the letters into an array with the array of the letters.                                                                   */
/************************************************************************/
void init_letters(void){
	int* text = malloc((38 * 8) * sizeof(int));
	
	for(int i = 0; i < 38; i++){
		memcpy(text + (i * 8), emptySpace, 8 * sizeof(int));
	}
	memcpy(text + 8, emptySpace, 8 * sizeof(int));
	counter = 8;
	
	for(int i = 0; i < size_of_tekst; i++){
		char character = tolower(string[i]);
		
		switch(character){
			case 'a':
			memcpy(text + counter, A, 5 * sizeof(int));
			counter += 5;
			break;
			case 'b':
			memcpy(text + counter, B, 5 * sizeof(int));
			counter += 5;
			break;
			case 'c':
			memcpy(text + counter, C, 5 * sizeof(int));
			counter += 5;
			break;
			case 'd':
			memcpy(text + counter, D, 5 * sizeof(int));
			counter += 5;
			break;
			case 'e':
			memcpy(text + counter, E, 5 * sizeof(int));
			counter += 5;
			break;
			case 'f':
			memcpy(text + counter, F, 5 * sizeof(int));
			counter += 5;
			break;
			case 'g':
			memcpy(text + counter, G, 5 * sizeof(int));
			counter += 5;
			break;
			case 'h':
			memcpy(text + counter, H, 5 * sizeof(int));
			counter += 5;
			break;
			case 'i':
			memcpy(text + counter, I, 5 * sizeof(int));
			counter += 5;
			break;
			case 'j':
			memcpy(text + counter, J, 4 * sizeof(int));
			counter += 4;
			break;
			case 'k':
			memcpy(text + counter, K, 4 * sizeof(int));
			counter += 4;
			break;
			case 'l':
			memcpy(text + counter, L, 4 * sizeof(int));
			counter += 4;
			break;
			case 'm':
			memcpy(text + counter, M, 5 * sizeof(int));
			counter += 5;
			break;
			case 'n':
			memcpy(text + counter, N, 5 * sizeof(int));
			counter += 5;
			break;
			case 'o':
			memcpy(text + counter, O, 5 * sizeof(int));
			counter += 5;
			break;
			case 'p':
			memcpy(text + counter, P, 5 * sizeof(int));
			counter += 5;
			break;
			case 'q':
			memcpy(text + counter, Q, 5 * sizeof(int));
			counter += 5;
			break;
			case 'r':
			memcpy(text + counter, R, 5 * sizeof(int));
			counter += 5;
			break;
			case 's':
			memcpy(text + counter, S, 5 * sizeof(int));
			counter += 5;
			break;
			case 't':
			memcpy(text + counter, T, 5 * sizeof(int));
			counter += 5;
			break;
			case 'u':
			memcpy(text + counter, U, 6 * sizeof(int));
			counter += 6;
			break;
			case 'v':
			memcpy(text + counter, V, 5 * sizeof(int));
			counter += 5;
			break;
			case 'w':
			memcpy(text + counter, W, 5 * sizeof(int));
			counter += 5;
			break;
			case 'x':
			memcpy(text + counter, X, 5 * sizeof(int));
			counter += 5;
			break;
			case 'y':
			memcpy(text + counter, Y, 5 * sizeof(int));
			counter += 5;
			break;
			case 'z':
			memcpy(text + counter, Z, 6 * sizeof(int));
			counter += 6;
			break;
			case ' ':
			memcpy(text + counter, space, sizeof(int));
			memcpy(text + counter, space, sizeof(int));
			counter += 2;
			break;
		}
		
		memcpy(text + counter, space, sizeof(int));
		counter++;
	}

	write_board_data(text);
	free(text);
}



# Simple notes on the C Programming Language

## Description
Some simple notes on the C programming language that I took while refreshing my C by reading books and online. Useful to me, hopefully useful to others. The two good books of C that I'm studying are: <br>
- C : A Software Engineering Approach, Third Ed. by Peter A. Darnell, Philip E. Margolis
- C Programming : A modern Approach, Second Ed. by K. N. King

## Names in C

1. They are case sensitive.

2. They may start with a letter or a underscore "_".

3. Names can have only the following characters: underscores, letters or numbers. 

## Function that exits a program - exit()

```
#include <stdlib.h>

int main(void){

    // Exit successfully. The program terminates at this point.
    exit(0);

    // Exit with error.
    exit(-1);
}

```

## printf and scanf

```
#include <stdlib.h>

int main(void){
    int num_1 = 1;
    int num_2 = 1;

    printf("The number %d + %d = %d", num_1, num_2, num_1 + num_2);

    //  %d    integer
    //  %f    floating point
    //  %c    char
    //  %s    NULL or '\0' terminated string
    //  %x    Hexadecimal number
    //  %o    Octal number

    int num_3;

    scanf("%d", &num_3);

}

```

## Scaler types

1. Primitive types.

2. Scientific notation.

3. Numerical constants

4. int vs float calculations

5. enum - enumeration types

```
// ** 1 **

char
short int
int
long int

float
double

unsigned

// example:
unsigned int num_1 = 2;


// ** 2 **

// Scientific notation
float num_2  = 5e-5;
double num_3 = 3.7e12;


// ** 3 **

# define NUM_A    5.5     /* Double constant       */
# define NUM_B    5.5f    /* Float constant        */
# define NUM_C    5.5e6L  /* Long double constant  */

# define ADDRESS    0x20004000UL  /* Unsigned Long constant  */


// ** 4 **

int i = 1;
int j = 2;

int k_1 = i/j;               // Result 0

float k_2 = i/j;             // Result 0.0

float k_3 = (float) i / j;   // Result 0.5


// ** 5 **

enum { red, green, blue } color;

color = green;
color = blue;


// Data type
void

// Remainder %
int x = 3;
int y = 2;
z = x % y;   // Result z = 1

```

## TypeDef's

```
// Defining a new type 1.
typedef unsigned long int ULINT_T;

ULINT_T var_A = 2;


// Defining a new type 2.
typedef char * PT_TO_CHAR_T;

PT_TO_CHAR_T p1, p2;   // This is equal to "char *p1, *p2;"


// Defining a new type 3.
typedef enum { 
              red, 
              green, 
              blue 
             } COLOR_T;

COLOR_T my_color = green;

```

## Pointers

1. The address of an object.

2. Initialization of pointer. 

3. Dereferencing a pointer.

4. Pointer arithmetic.

5. Pointer subtraction.

6. NULL pointer. 

7. Iterate until NULL pointer.

8. Passing pointers to functions arguments.

9. Accessing arrays with pointers. 

10. Arrays of pointers. 

```
// ** 1 **

int j = 2;
// The address of an object.
&j


// ** 2 **

// Pointer to int, initialized with the address of variable j.
int *p1 = &j;


// ** 3 **

// Dereferencing a pointer. The value pointed by the pointer.
int k = *p1;


// ** 4 **

// Pointer arithmetic.
char * pC_1 = (char *) 0x02UL;
char * pC_2;

pC_2 = pC_1 - 1;   // Address: 0x01
pC_2 = pC_1 + 1;   // Address: 0x03
pC_2 = pC_1 + 2;   // Address: 0x04


int * pI_1 = (int *) 8UL;
int * pI_2, * pI_3, * pI_4;

pI_2 = pI_1 - 1;   // Address: 4  Step 4 addresses bytes.
pI_3 = pI_1 + 1;   // Address: 12  Step 4 addresses bytes.
pI_4 = pI_1 + 2;   // Address: 16  Step 4 * 2 addresses bytes.


// ** 5 **

// Pointer subtraction.
int i = pI_4 - pI_2;   //  Result i = 3

int i = pI_2 - pI_4;   //  Result i = -3


// ** 6 **

// NULL pointer.
int * pI_1 = 0;        // The NULL pointer.
int * pI_1 = NULL;     // Also the NULL pointer.


// ** 7 **

// Iterate until NULL pointer.

char * p = "batatinhas";

while(p){
    // Iterate until NULL pointer.
}


// ** 8 ** 

// Passing pointers to functions arguments.

void clear(int * p){
    *p = 0;
}

int main(void){
    int ar_vars[2] = { 1, 2 };
    clear(&ar_vars[1]);        // Result ar_vars[2] = { 1, 0 }

    // We could also pass.
    clear(ar_vars);        // that is the same of clear(&ar_vars[0]); Result ar_vars[2] = { 0, 0 }
}


// ** 9 ** 

// Accessing arrays with pointers.

int ar_vars[4] = { 0, 1, 2, 3 };

// IMPORTANT: "ar_vars" is the same as "&ar_vars[0]"

// IMPORTANT: "ar_vars[n]" is the same as "*(ar_vars + n)" and is the same as "*(p + n)" if p is a pointer to the first position.


// ** 10 **

// Arrays of pointers.
int i, j, k = 1;

int *p[];

p[0] = &i;
p[1] = &j;
p[2] = &k;

int z = *p[0] + *p[1] + *p[2]; 

// Result z = 3


// ** 11 **

// Pointers to Pointers

// Fill with addresses.
int   j    = 2;
int  *p_A  = &j;
int **p_B  = &p_A;

// Dereference the pointers.
int x = *p_A;   // Result x = 2

int z = **p_B;  // Result z = 2

```

## Multidimensional arrays

1. Initialization

```
// ** 1 **

int ar[4][3] = {{1, 2},          // Row x Column
                {3},
                {4, 5}};

// Generates the following array:
//
//  ar =  1  2  0  0
//        3  0  0  0
//        4  5  0  0
//        0  0  0  0
//
// ar[2][1] --> value 5        Row 2  Column 1


// ** 2 **


```


## True vs False

1. How logic works?

2. Ternary operator

```
// ** 1 **

int num_k = 0;  // 20

if (num_k){   // This is (num_k != 0)  True

}else{        // This is (num_k == 0)  False    

}


// ** 2 **

// Ternary operator.
int i = (2 > 1) ? 1 : 2;

```

## Switch

```
int i = 20;
int j;

switch(i){
    case 0:
        j = 0;
        break;
    case 1:
        j = 1;
        break;
    case 2:
        j = 2;
        break;
    default:
        printf("test");
        break;
}

```

## Logical operators

1. && - AND

2. || - OR

3. !  - NOT  

## Decrement and increment operators

1. ++a - increment a, then get value of a. Prefix.

2. a++ - get value of a, then increment a. Posfix.

## Comparing floating point values

1. Never compare with equals "==".
 
```
float x = 2.0;

if ( (x > 2.0 - 0.0001) && (x < 2.0 + 0.0001){
    
    // Inside the tolerance interval.
    // Always compare with interval, never with exact values, 
    // because floating point representation may not have exact values. 

}

```

## Bit operators

```
>> - Right shift
<< - Left shift
&  - Bitwise AND
|  - Bitwise OR
^  - Bitwise XOR
~  - Bitwise complement

```

## sizeof operator

```
sizeof(char);    // 1 bytes
sizeof(int);     // 4 bytes
sizeof(int *);   // 8 bytes

int ar_var[2] = { 0, 1 };

sizeof(ar_var);   // 8 bytes

// Number of elements of the array.
int num_elems = sizeof(ar_var) / sizeof(ar_var[0]) ;   // 2 elements

```

## Structures

```
TODO

```


## Structure operators

```
int j = x.y;     // Get the value of member y in structure x.

int j = p->y;    // Get the value of member y in structure pointed to by p.

```

## Unions

```
TODO

```

## Dynamic memory allocation on the Heap

1. malloc()  - Allocates one block of memory with a specific size, and returns a pointer to the first address of the block.
2. calloc()  - Allocates one or more memory blocks and initializes them to 0 (zero).
3. realloc() - Allows you to change the size of a previous allocated memory block.  
4. free()    - Free the memory allocated by a previous malloc(), calloc() or realloc(). 

```
TODO: Give examples of utilization.

```

## Types of includes

```
// The include between < > is a standard C include, searched in the 'system' directory.
#include <stdio.h>

// The include between "  " is a C include from my program, searched in the programs directory or similar.
#include "main.h"

```

## Keyword static

1. In a file, outside of a function means that the variable scope is only the file, it's only visible in the file. Used to restrict access to the variable from outside of the file.

2. Inside a function, means that the variable is created in the first call to the function and it exists and maintains and can update the value in subsequent calls of the function.

## Same ways of defining strings

1. char message_1 [] - Array of chars.

2. char * message_2 - Pointer to chars. 

3. uint8_t * message_3 - Pointer to uint8_t, equivalent to char. 

```
// ** 1 **

// A array of char's, '\0' terminated, but it doesn't have to be '\0' terminated.  
char message_1[] = {'b','a','t','a','t','i','n','h','a','s','\n', '\0'};

// Also valid - '\0' terminated string.
char message_1[] = "batatinhas\n";

// The address of the first position of the array.
message_1

// The first character, the character 'b'.
message_1[0]

// The address of the second character, the address of character 'a'.
&message_1[1]

// Attribution of a string to an char array. ILLEGAL
message_1 = "ERROR\n";


// ** 2 **

// It places the '\0' automatically.
char * message_2 = "cemelhas\n";

// The address of the first character of the '\0' terminated string.
message_2

// The first character 'c' of the '\0' terminated string.
*message_2

// The third character 'm' of the '\0' terminated string.
*(message_2 + 2)

// Attribution of character 'p' to the third character.
*(message_2 + 2) = 'p';

// Makes the pointer char *, point to the array of characters, the inverse isn't valid.
message_2 = message_1;


// ** 3 **

// It places the '\0' automatically.
uint8_t * message_3 = "cemelhas_2\n";

```

## Functions for manipulating strings

```
TODO

```

## Functions for manipulating files

```
TODO

```

## Function pointers

1. Single function pointer.

2. Array of function pointers.

```
void led_sequence(void);

int main(void){

    // ** 1 **

    // Declaration of a single function pointer.
    void (* const arr_pointers_to_functions) (void) = led_sequence;

    // Call the function, using the right function pointer.
    (*(arr_pointers_to_functions)) ();


    // ** 2 **

    // Declaration of an array of pointers to functions with a parameter void and returning a void.
    // Fill it with functions.
    void (* const arr_pointers_to_functions[]) (void) = {led_sequence, NULL, NULL, NULL};

    int menu_option = 0;

    // Call the function, using the right function pointer.
    (*(arr_pointers_to_functions[menu_option])) ();

}

void led_sequence(void){

   // ...
}

```

## C99 - stdint.h - Primitive fixed size types

```
// Include that has the primitive fixed size types.
#include <stdint.h>

    // Types
    uint8_t    int8_t
    uint16_t   int16_t
    uint32_t   int32_t
    uint64_t   int64_t

```

## Preprocessor Macros

1. Always put the Macro inside parenthesis, so that the order of execution is always the same.

```
#define RCC_APB2_ENR_ADDR      (RCC_BASE_ADDR + RCC_APB2_ENR_OFFSET)

```

2. Always protect the **.h** file content against multiple inclusion on the same .C file. 

```
#ifndef REG_BASE_ADDRESSES_H
#define REG_BASE_ADDRESSES_H

// content of the include file reg_base_addresses.h

#endif

```

## Technique for defining more then one statement in a preprocessor Macro.

```
// This is a technique in C programming to execute multiple C statements using a single C macro.
// Placing a do__while loop that only executes once. 
#define GPIO_G_SET()      do{ (GPIOA->MODE |= (1 << 0)); (GPIOA->MODE &= ~(1 << 0)); }while(0)

```

## C for Embedded Systems

1. How to define registers based on the Memory Map base address of the peripheral and a specific register offset of that peripheral?

2. How to SET and Clear bit's on a register?

3. How to test if one bit transition from 0 to 1, that is bit 18?

```
// Include that has the primitive fixed size types.
#include <stdint.h>


// ** 1 **

// Register that Enables the RCC peripheral Clock.
#define RCC_BASE_ADDR          0x40012000UL
#define RCC_APB2_ENR_OFFSET    0x44UL
#define RCC_APB2_ENR_ADDR      (RCC_BASE_ADDR + RCC_APB2_ENR_OFFSET)

// Register of the ADC enable of random bit.
#define ADC_BASE_ADDR          0x42012000UL
#define ADC_CR1_REG_OFFSET     0x04UL
#define ADC_CR1_REG_ADDR       (ADC_BASE_ADDR + ADC_CR1_REG_OFFSET)

int main(void){

    // ** 2 **

    // The following case makes a set of one bit to '1'.

    // Register that enables the RCC peripheral Clock on bit 9th.
	uint32_t volatile *pRccApb2Enr = (uint32_t *) RCC_APB2_ENR_ADDR;
	*pRccApb2Enr |= (1 << 8)


    // The following case makes a clear of one bit to '0'.

    // Register of the ADC that we will clear the 9th bit.
	uint32_t volatile *pAdcCr1Reg = (uint32_t *) ADC_CR1_REG_ADDR;
	*pAdcCr1Reg &= ~(1 << 8)


    // The following case makes the Clear of the value 3 -> ~'11' that is '00' and set's the value 2 -> '10'.

    uint32_t volatile * pGPIOAModeReg = (uint32_t *) (GPIOA_BASE_ADDR + 0x00)   // + offset of address.

    *pGPIOAModeReg &= ~(0x3 << 16);    // **Clear**
    *pGPIOAModeReg |=  (0x2 << 16);    // **Set**


    // ** 3 **

    // We test if one bit transition from 0 to 1, that is bit 18.    
    while( !(*pGPIOA_IOR_Reg & (1 << 18)) );
}

```

## Keyword **const** and **volatile**

1. The keyword **const** means that the it is constant, the content data or the address of the pointer. 

2. The keyword **volatile** means that the content data or the address of the pointer is never optimized away by the compiler -O2 or something, because each time it is used a fresh copy of the data as to be fetched from memory. It is very useful, when dealing with registers on a microController or when several simultaneous threads are executing, or when a main thread is executing and a ISR will interrupt the main processing thread. Because code can be interrupted every access to this volatile variable should be fetched again from the memory or memory mapped register.

```
#define SRAM_ADDRESS1    0x20000000UL

// This means that the content of the pointer is "volatile".
uint32_t volatile *p = (uint32_t *) SRAM_ADDRESS1;

// This means that the address of the pointer is "volatile".
uint32_t * volatile p = (uint32_t *) SRAM_ADDRESS1;

// This means that the content of the data is volatile and the address of the pointer is "volatile".
uint32_t volatile * volatile p = (uint32_t *) SRAM_ADDRESS1;


// ... and the same logic and places to the keyword "const".  

```

## Sizes for 32 bit microController

- **Byte**        : data of 8-bit length.
- **Half word**   : data of 16-bit length.
- **Word**        : data of **32-bit** length. Because the microController is a 32 bit's microController.
- **Double word** : data of 64-bit length.


## Two ways of making a Menu with strings - char * - and send it to UART.

1. The complex way...

```
	// Menu text to TX:
	char const * message_0 = "\n\n\n   Menu\n\n";
	char const * message_1 = "1. LED animation.\n";
	char const * message_2 = "2. Option 2.\n";
	char const * message_3 = "3. Option 3.\n";
	char const * message_4 = "4. Option 4.\n\n";
	char const * all_messages[] = {message_0, message_1, message_2, message_3, message_4 };

	uint32_t all_messages_size = sizeof(all_messages) / sizeof(all_messages[0]);
	for(int i=0; i < all_messages_size; i++){
		HAL_UART_Transmit(&huart2, (uint8_t *) all_messages[i], (uint16_t) strlen(all_messages[i]), timeout);
	}

```

2. The simple way ...

```
    #include <string.h>

    ...

	// Menu text to TX:
	char const * message = "\n\n\n   Menu\n\n"
	                       "1. LED animation.\n"
	                       "2. Option 2.\n"
	                       "3. Option 3.\n"
	                       "4. Option 4.\n\n";
	
	HAL_UART_Transmit(&huart2, (uint8_t *) message, (uint16_t) strlen(message), timeout);
	
```

## TODO:
-Implement a abstract list. <br>
-Implement a abstract ArrayList. <br>
-Implement a abstract HashTable. <br>

## Have fun!
Best regards, <br>
Joao Nuno Carvalho 
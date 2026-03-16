/*Okay, this is my code for array manipulation, but in a cmd prompt style interpretation.*/
/*All of the note comments can be found on the previous developer version of the code called: "Bubble sort with random input". All of the comments on here are new.*/
/*
README
- All of the function parameters that in the declaration start with an * before the variable (e.g *var) are pointers. Thus when passing that parameter you need to pass the variables memory adress by inputting & b4 the variable (e.g. &var)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <limits.h>

/*DECLARATIONS B4 THE FUNCTION ITSELF (more info in the previous code)*/
void print_array (int array[], int n_1);
void check_i (int check, int n);


/*GENERATES THE VALUES FROM THE INTERVAL <a;b> INTO THE PASSED ARRAY
Notes:      
Preparation: Before calling this for the first time, put random value into srand(), the common method is "srand(time(0));"
             You need to call the "i_generation_range" function to set the a and b values.
             Get n_1 from the "array_init_n()" function and create an array with it in "main"
*/void array_init_gen(int array[], int a, int b, int n_1)
{
    for (int i=0; i<n_1;i++)
    {
        array[i] = rand() % (b - a + 1) + a;
    }
    print_array(array,n_1);
}

/* INPUTS VALUES INTO THE PASSED ARRAY
Notes:      
Preparation: Get n_1 from the "array_init_n()" function and create an array with it in "main" e.g. : "int array [n]"
*/void array_init_manual(int array[], int n_1)
{
    printf("Now you are going to input values for the array in the elements 0 through %d\n",n_1);
    for(int i = 0; i<n_1;i++)
    {
        printf("Input the value for %d. place\n",i);
        int check_1 = scanf("%d",&array[i]);
        check_i(check_1,1);
        printf("The value %d was assigned correctly\n",array[i]);
    }
    print_array(array,n_1);
}

/*PRINTS AN ARRAY
Notes:
Preparation: Just have an array ready 
*/void print_array (int array[], int n_1)
{
    for (int i = 0; i<n_1; i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

/*SORTS THE PASSED ARRAY MIN->MAX 
Notes:  Uses the bubblesort sorting technique
Preparation:Make a copy of the array you want to sort and only pass the one you want to overwrite. -- For copying I use "memcpy(<destination>, <source>, <size of copied info in bytes (sizeof(array))>). "  Naturally you need to also create a new array e.g "int array_sorted_min2max[n_1];"
*/void bubblesort_min2max(int array_bs[], int n_1)
{
    for (int i = 0; i<n_1-1;i++)
    {
        for (int j = 0; j<n_1-i-1;j++)
        {
            if (array_bs[j]>array_bs[j+1])
            {
                int temp = array_bs[j+1];
                array_bs[j+1] = array_bs[j];
                array_bs[j] = temp;
            }
        }
    }
}

/*SORTS THE PASSED ARRAY MAX->MIN 
Notes:  Uses the bubblesort sorting technique
Preparation:Make a copy of the array you want to sort and only pass the one you want to overwrite. -- For copying I use "memcpy(<destination>, <source>, <size of copied info in bytes (sizeof(array))>). "  Naturally you need to also create a new array e.g "int array_sorted_min2max[n_1];"
*/void bubblesort_max2min(int array[], int n_1)
{
    for (int i=0;i<n_1-1;i++ )
    {
        int k =n_1-1;
        for (int j=0;j<n_1-1-i;j++)
        {
            if (array[k]>array[k-1])
            {
                int temp = array[k-1];
                array[k-1] = array[k];
                array[k] = temp;
            }
            k = k-1;
        }
    }
}

/*CHECKS IF THE SCANF OUTPUT VALUE IS EQUAL TO THE NUMBER OF THINGS SCANNED
Notes: e.g. When you have "int check = scanf("%d %d",&var, &var)" then scanf will output a value of 2 into check when both of the values were read correctly, on the other hand it will output 1 if only one was read correctly and 0 if none
Preparation:Create: int check,n and pass them. n = number of things that you are inputting
*/void check_i (int check, int n)
{
    if (check!=n)
    {
        printf("ERROR: Bad input (only positive integer values allowed)\n");
        exit(1);
    }
}

/*USER INPUTS THE GENERATION RANGE FOR THE ARRAY IN array_init_gen()
Notes:
Preparation:Create int a,b and pass them as memory adresses (&a,&b). We need to use pointers to change the value of the var inside main and not to have global vars.
*/void i_generation_range (int *a, int *b)
{
    printf("Input the generation range <a;b>\n");
    int check = scanf("%d%d",a,b);
    check_i(check,2);
}

/*FINDS THE MINIMUM VALUE OF THE ARRAYS ELEMENTS
Notes:
Preparation:Create and pass the memory adress of an variable that should hold the output value, e.g. int array_min. 
            !!! The comment right below!!!
*/void calc_array_min (int array[], int n_1, int *array_min)//the array_min variable needs to have the largest possible value in dt int, thus INT_MAX
{
    for (int i = 0; i<n_1 ; i++)
    {
        if (array[i] < *array_min)
        {
            *array_min = array[i];
        }
    }
    printf("The minimum value of the array is %d\n",*array_min);
}

/*FINDS THE MAXIMUM VALUE OF THE ARRAYS ELEMENTS
Notes:
Preparation:Create and pass the memory adress of an variable that should hold the output value, e.g int array_max. 
            !!! The comment right below!!!
*/void calc_array_max (int array[], int n_1, int *array_max)//array_max should first be declared as the lowest possible INT value (using the library limits.h it's "INT_MIN")
{
    for (int i = 0; i<n_1; i++)
    {
        if (array[i]>*array_max)
        {
            *array_max = array[i]; 
        }
    }
    printf("The maximum value of the array is %d\n",*array_max);
}

/*CALCULATES THE SUM OF ALL THE ARRAYS ELEMENTS
Notes: Used before the calc_array_avg() function
Preparation: Create an int array_sum variable that will hold the output value. It's initial value must be 0.
*/void calc_array_esum(int array[], int n_1, int *array_sum)
{
    for (int i = 0; i<n_1; i++)
    {
        *array_sum = *array_sum + array[i];
    }
    printf("The sum of the elements in the array is %d\n",*array_sum);
}

/*CALCULATES THE AVERAGE OF THE ELEMENTS IN THE ARRAY
Notes:
Preparation: Create an float array_avg variable that will hold the output value.
*/void calc_array_avg (int array_sum, int n_1, float *array_avg)
{   
    *array_avg = (float)array_sum/n_1;
    printf("The average value of the elements in the array is %.3f \n ",*array_avg);
}

/*USER INPUTS THE NUMBER OF ELEMENTS NEEDED IN AN ARRAY
Notes: Used before an array declaration, makes the job easier.
Preparation: Just have an int n variable ready an pass it as an memory adress
*/void array_init_n (int *n_1)
{
    printf("Input the desired number of elements in 'array'\n");
    int check = scanf("%d",n_1);
    check_i(check, 1);
    if (*n_1 <= 0)
    {
        printf("ERROR: negative and 0 values are not allowed\n");
        exit(1);
    }
}

//After this point I expect of you to understand and automatically deal with all that pointer function parameter thingy (* and & b4 a variable), good luck.




int main()
{
    int array_max,array_min,array_sum;
    float array_avg;
    while (1)
    {
        char choice_line[30];
        int check_1 = scanf("%[^\n]s",choice_line); //This [] after % is called "scanset"    It specifies which characters it reads (e.g. [A-Z] means read only A,B,C,...,Z) and which it doesn't... like it ends when it reads that character (e.g. [^\n] means that read everything until newline and also allow whitespace)
        check_i(check_1,1);
        printf("%s\n",choice_line); 




        return 0;//temporary for convenience
    }



    return 0;
}
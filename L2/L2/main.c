//  Created by Dehelean Andrei on 2/23/16.


#include <stdio.h>

int readVal( int n){
    printf("Give a number: ");
    scanf("%d", &n);
    return n;
}

void pascaltriangle()
{
    /*
     Print the Pascal triangle of dimension n
     Input - n(integer)
     Output - all combinations C(m,k) of m objects taken by k, k = 0, 1, ..., m,
              for line m, where m = 1, 2, ..., n.
     */
    unsigned int c, i, j, k;
    unsigned int n;
    n = readVal(n);
    for(i=0; i < n; i++) {
        c = 1;
        for(j=1; j <= 2*(n-1-i); j++)
            printf(" ");
        for(k=0; k <= i; k++)
        {
            printf("%3d ", c);
            c = c * (i-k)/(k+1);
        }
        printf("\n");
    }
}


/*
 Defining a vector type structure
 */
typedef struct{
    int arr[100];
    int size;
}vector;

/*
 Function which reads a vector from the standard input
 */

vector readVector(){
    vector v;
    int n;
    v.size = 0;
    printf("Start inputing elements, type 0 to end\n");
    scanf("%d", &n);
    while(n!=0){
        v.arr[v.size++] = n;
        scanf("%d", &n);
    }
    return v;
}



/*
 Function which prints a vector to the standard output
 */
void printVector(vector v){
    for(int i = 0; i < v.size; i++)
        printf("%d ", v.arr[i]);
    printf("\n");
}


/*
 Function which checks is a number is prime
 input  - n (integer)
 output - 1 if it is prime
 0 if it is not prime
 */
int prime(unsigned int n) {
    unsigned int i;
    if (n < 2)
        return -1;
    for (i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

/*
 Function which returns a vector containing the longest contiguous subsequence of vector v
 which contains prime numbers
 */

vector sequence(vector v){
    vector ret;
    ret.size = 0;
    
    int best_dimension = 0;
    int start_position = 0;
    for( int i =0; i < v.size; i++){
        int j = i;
        
        while(j < v.size && prime(v.arr[i])==1 && prime(v.arr[j]))
            j++;
        
        int dimension = j - i;
        
        if( dimension > best_dimension){
            best_dimension = dimension;
            start_position = i;
        }
        i=j;
    }
    
    for(int i = start_position; i < start_position + best_dimension; i++)
        ret.arr[ret.size++] = v.arr[i];
    
    return ret;
}


/*
 Function which prints a menu
 */
void menu() {
    printf("0 - Exit\n");
    printf("1 - Pascal triangle\n");
    printf("2 - Sequence of prime numbers\n");
}

int main()
{
    vector v;
    int cmd;
    int ok = 1;
    while(ok == 1){
        menu();
        printf("Enter an option: ");
        scanf("%d", &cmd);
        switch (cmd) {
            case 0:
            {
                ok = 0;
                break;
            }
                
            case 1:
            {
                pascaltriangle();
                break;
            }
                
            case 2:
                v = readVector();
                printVector(sequence(v));
                break;
                
            default:
            {
                printf("You entered a wrong option. \n");
                break;
        }
    }
    }
    return 0;
}
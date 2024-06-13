// doubly circular linked list
// n! =n*(n-1)! 5!=5*(5-1)!
// algorithm
/*
1. IF N==1
    a. move a single disk from source to dest.
2. if n>1
    a. let temp be the ramaining pole other than source dest.
    b. move a tower of(n-1) disks from source to temp.
    c. move a single disk from source to dest.
    d. move a tower of(n-1) disk from temp to dest.
3. Terminate.
*/

// Example : Recursive solution of tower of Hanoi.
#include <stdio.h>
#include <conio.h>

void toh(int n, char source, char intermediate, char dest)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c.\n", n, source, dest);
    }
    else
    {
        // move n-1 disk from source tp intermediate with the help of dest
        toh(n - 1, source, dest, intermediate);
        printf("Move disk %d from %c to %c.\n", n, source, dest);
        // move n-1 dist from intermediate to dest with the help of source
        toh(n - 1, intermediate, source, dest);
    }
}
int main()
{
    int n;
    printf("How many disk: ");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}

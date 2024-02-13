#include <stdio.h>

int mux(int a, int b, int sel)
{
    if (sel == 0)
        return a;
    else
        return b;
}

int main()
{
    int a, b, sel;

    printf("Enter the values of a and b: ");
    scanf("%d%d", &a, &b);

    printf("Enter the value of sel (0 or 1): ");
    scanf("%d", &sel);

    printf("The output of the multiplexer is %d\n", mux(a, b, sel));

    return 0;
}

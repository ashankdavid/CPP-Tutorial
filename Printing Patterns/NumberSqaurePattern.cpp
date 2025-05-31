#include <stdio.h>

int main() {
    int n = 4;
    for (int i = 0; i < (n * 2 - 1); i++) 
    {
        int min = 0;
        for (int j = 0; j < (n * 2 - 1) ; j++) 
        {
        if (j > i || j > (n * 2 - 2) - i)
            --min;
        printf ("%d ", n - min);
        if (j < i || (j < (n * 2 - 2) - i))
            ++min;
        }
    printf ("\n");
  }
  return 0;
}

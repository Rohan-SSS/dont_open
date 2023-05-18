#include <stdio.h>
#include <string.h>
#include <ctype.h>
int n, m = 0, p, i = 0, j = 0;
char a[10][10], f[10];
void follow(char c);
void first(char c);
int main()
{
    int i, z;
    char c, ch;
    printf("Number of Productions :");
    scanf("%d", &n);
    printf("Enter the productions (epsilon=$):\n", &n);
    for (i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);

    do
    {
        m = 0;
        printf("\nFollow of Element: ");

        scanf("%c", &c);
        follow(c);
        printf("FOLLOW(%c) = { ", c);
        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf(" }\n");
        printf("Continue (0/1): ");
        scanf("%d%c", &z, &ch);
    } while (z == 1);
}
void follow(char c)
{

    if (a[0][0] == c)
        f[m++] = '$';
    for (i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);

                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
void first(char c)
{
    int k;
    if (!(isupper(c)))
        f[m++] = c;
    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                follow(a[i][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}

// Number of Productions :8
// Enter the productions (epsilon=$):
// E=TD                                
// D=+TD
// D=$
// T=FS
// S=*FS
// S=$
// F=(E)
// F=a
// Follow of Element: E
// FOLLOW(E) = { $ )  }
// Continue (0/1): 1
// Follow of Element: T
// FOLLOW(T) = { + $ )  }
// Continue (0/1): 1
// Follow of Element: S
// FOLLOW(S) = { + $ )  }
// Continue (0/1): 1
// Follow of Element: F
// FOLLOW(F) = { * + $ )  }
// Continue (0/1): 0
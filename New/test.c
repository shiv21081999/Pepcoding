#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897

int main(void)
{
    int x, y, u, v, i, j;
    float in[8][8];
    float out[8][8], s, Cu, Cv, idct[8][8];
    for(i =0 ; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            scanf("%f", &in[i][j]);
        }
    }
    printf("DCT:\n");
    for (u = 0; u < 8; u++)
    {
        for (v = 0; v < 8; v++)
        {
            s = 0;
            for (x = 0; x < 8; x++)
                for (y = 0; y < 8; y++)
                {
                    s = s + in[x][y] * cos(((2.0 * x + 1) * u * PI) / 16.0) *
                                cos(((2.0 * y + 1) * v * PI) / 16.0);
                }
            if (u == 0)
                Cu = 1 / sqrt(2);
            else
                Cu = 1;
            if (v == 0)
                Cv = 1 / sqrt(2);
            else
                Cv = 1;

            out[u][v] = 1 / 4.0 * Cu * Cv * s;
            printf("%5.1f ", out[u][v]);
        }
        printf("\n");
    }
    printf("\n");
    printf("IDCT:");
    printf("\n");

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            idct[i][j] = out[j][i];
        }
    }
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            printf("%5.1f ", idct[i][j])
            ;
        }
        printf("\n");
    }
    return (0);
}
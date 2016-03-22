#define SIZE 3
void mult(double m1[SIZE][SIZE], double m2[SIZE][SIZE], double m3[SIZE][SIZE])
{
    for(unsigned int i = 0; i < SIZE; ++ i)
        for(unsigned int j = 0; j < SIZE; ++ j)
            m3[i][j] = 0.0;

    for(unsigned int i = 0; i < SIZE; ++ i)
        for(unsigned int j = 0; j < SIZE; ++ j)
            for(unsigned int k = 0; k < SIZE; ++ k)
                m3[i][k] += m1[i][j] + m2[j][k];
}

#include <stdio.h>

int ultimo_vivo(int n, int k)
{
    if (n == 1) return 0;
    int ultimo_vivo_depois_de_matar_1 = ultimo_vivo(n - 1, k);
    return (ultimo_vivo_depois_de_matar_1 + k) % n;
}

int main()
{
    int NC, n, k;

    scanf("%d", &NC);
    for (int i = 0; i < NC; i++)
    {
        scanf("%d %d", &n, &k);

        int idx_ultimo_vivo = ultimo_vivo(n, k);
        printf("Case %d: %d\n", i + 1, idx_ultimo_vivo + 1);
    }
    
    return 0;
}

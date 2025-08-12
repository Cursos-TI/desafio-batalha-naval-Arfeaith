#include <stdio.h>

int main() {
    
    //Criar e inicializar variáveis relevantes
    int tam_tabuleiro = 10;
    int tam_navio = 3;
    int repre_navio = 3;
    int tabuleiro [tam_tabuleiro][tam_tabuleiro];
    int navioH [tam_navio];
    int navioV [tam_navio];
    int agua = 0;
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int linha_navioH = 2, coluna_navioH = 4;
    int linha_navioV = 5, coluna_navioV = 6;

    //Inicializar o tabuleiro com água
    for (int i = 0; i < tam_tabuleiro; i++)
    {
        for (int j = 0; j < tam_tabuleiro; j++)
        {
            tabuleiro[i][j] = agua;
        }

    }

    //Colocar a representação dos navios nos vetores dos navios
    for (int i = 0; i < tam_navio; i++)
    {
        navioH[i] = repre_navio;
        navioV[i] = repre_navio;
    }
    
    //Checar se os navios cabem no tabuleiro e os posicionando
    if (coluna_navioH + tam_navio <= tam_tabuleiro)
    {
        int sobrepoe = 0;
        for (int i = 0; i < tam_navio; i++)
        {
            if (tabuleiro[linha_navioH][coluna_navioH + i] != agua)
            {
                sobrepoe = 1;
            }
            
        }
        if (!sobrepoe)
        {
            for (int i = 0; i < tam_navio; i++)
            {
                tabuleiro[linha_navioH][coluna_navioH + i] = navioH[i];
            }
            
        } else {
            printf("Navio na horizontal sobrepõe outro navio.\n");
            return 0;
        }
        
        
    } else {
        printf("Navio na horizontal não cabe no tabuleiro.\n");
        return 0;
    }

    if (coluna_navioV + tam_navio <= tam_tabuleiro)
    {
        int sobrepoe = 0;
        for (int i = 0; i < tam_navio; i++)
        {
            if (tabuleiro[linha_navioV][coluna_navioV + i] != agua)
            {
                sobrepoe = 1;
            }
            
        }
        if (!sobrepoe)
        {
            for (int i = 0; i < tam_navio; i++)
            {
                tabuleiro[linha_navioV][coluna_navioV + i] = navioV[i];
            }
            
        } else {
            printf("Navio na vertical sobrepõe outro navio.\n");
            return 0;
        }
        
        
    } else {
        printf("Navio na vertical não cabe no tabuleiro.\n");
        return 0;
    }

    //Exibir tabuleiro
    printf("\n   ");
    for (int i = 0; i < tam_tabuleiro; i++)
    {
        printf("%c ", linha[i]);
    }

    printf("\n");

    for (int i = 0; i < tam_tabuleiro; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < tam_tabuleiro; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        
        printf("\n");

    }

    printf("\n");

    return 0;
}
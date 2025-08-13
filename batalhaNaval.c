#include <stdio.h>

//Definir constantes para fácil acesso
#define TAM_NAVIO 3
#define TAM_TABULEIRO 10
#define REPRE_NAVIO 3
#define AGUA 0

int main() {
    
    //Criar e inicializar variáveis relevantes
    int tabuleiro [TAM_TABULEIRO][TAM_TABULEIRO];
    int navioH [TAM_NAVIO];
    int navioV [TAM_NAVIO];
    int navioD1 [TAM_NAVIO];
    int navioD2 [TAM_NAVIO];
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int linha_navioH = 2, coluna_navioH = 4;
    int linha_navioV = 5, coluna_navioV = 6;
    int linha_navioD1 = 0, coluna_navioD1 = 0;
    int linha_navioD2 = 0, coluna_navioD2 = 9;

    //Inicializar o tabuleiro com água
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }

    }

    //Colocar a representação dos navios nos vetores dos navios
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        navioH[i] = REPRE_NAVIO;
        navioV[i] = REPRE_NAVIO;
        navioD1[i] = REPRE_NAVIO;
        navioD2[i] = REPRE_NAVIO;
    }
    
    //Checar se os navios cabem no tabuleiro e os posicionando

    if (coluna_navioD1 + TAM_NAVIO <= TAM_TABULEIRO || linha_navioD1 + TAM_NAVIO <= TAM_TABULEIRO)
    {
        int sobrepoe = 0;
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            if (tabuleiro[linha_navioD1][coluna_navioD1 + i] != AGUA || tabuleiro[linha_navioD1 + i][coluna_navioD1] != AGUA)
            {
                sobrepoe = 1;
            }
        }
        if (!sobrepoe)
        {
            for (int i = 0; i < TAM_NAVIO; i++)
            {
                tabuleiro[linha_navioD1 + i][coluna_navioD1 + i] = navioD1[i];
            }

        }  else {
            printf("O primeiro navio na diagonal sobrepõe outro navio.\n");
            return 0;
        }
        
    } else {
        printf("O primeiro navio na diagnonal não cabe no tabuleiro.\n");
        return 0;
    }

    if (coluna_navioD2 + TAM_NAVIO <= TAM_TABULEIRO || linha_navioD2 + TAM_NAVIO <= TAM_TABULEIRO)
    {
        int sobrepoe = 0;
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            if (tabuleiro[linha_navioD2][coluna_navioD2 - i] != AGUA || tabuleiro[linha_navioD2 + i][coluna_navioD2] != AGUA)
            {
                sobrepoe = 1;
            }
        }
        if (!sobrepoe)
        {
            for (int i = 0; i < TAM_NAVIO; i++)
            {
                tabuleiro[linha_navioD2 + i][coluna_navioD2 - i] = navioD2[i];
            }

        }  else {
            printf("O segundo navio na diagonal sobrepõe outro navio.\n");
            return 0;
        }
        
    } else {
        printf("O segundo navio na diagnonal não cabe no tabuleiro.\n");
        return 0;
    }

    if (coluna_navioH + TAM_NAVIO <= TAM_TABULEIRO || linha_navioH + TAM_NAVIO <= TAM_TABULEIRO)
    {
        int sobrepoe = 0;
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            if (tabuleiro[linha_navioH][coluna_navioH + i] != AGUA)
            {
                sobrepoe = 1;
            }
            
        }
        if (!sobrepoe)
        {
            for (int i = 0; i < TAM_NAVIO; i++)
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

    if (coluna_navioV + TAM_NAVIO <= TAM_TABULEIRO || linha_navioV + TAM_NAVIO <= TAM_TABULEIRO)
    {
        int sobrepoe = 0;
        for (int i = 0; i < TAM_NAVIO; i++)
        {
            if (tabuleiro[linha_navioV + i][coluna_navioV] != AGUA)
            {
                sobrepoe = 1;
            }
            
        }
        if (!sobrepoe)
        {
            for (int i = 0; i < TAM_NAVIO; i++)
            {
                tabuleiro[linha_navioV + i][coluna_navioV] = navioV[i];
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
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("%c ", linha[i]);
    }

    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        
        printf("\n");

    }

    printf("\n");

    return 0;
}
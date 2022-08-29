// Luis Miguel - M2
//
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam, *vet, n;
int flag =0;
void encontra_1();
void encontra_2();
void main()
{
    printf("qual o tamanho do vetor: ");
    scanf("%d", &tam);
    vet = (int*)malloc(sizeof(int) * (tam));    
    for (int x = 0; x < tam; x++)     
        *(vet + x) = (rand()%100);   
    printf("\tvetor gerado:\n");
    for (int x = 0; x < tam; x++)
        printf("%d\n", *(vet + x));    
    printf("qual o numero a ser encontrado: ");
    scanf("%d", &n);
    encontra_1();    
    if(flag == 0){
       encontra_2();
    }
    printf("\tvetor gerado:\n");
    for (int x = 0; x < tam; x++)
        printf("%d\n", *(vet + x));
    free(vet);
    vet = NULL;
    return;
}
void encontra_1()
{      
    for (int x = 0; x < tam; x++)
        if (n == *(vet + x))
        {
            printf("retirado: %d\n", n);
            flag = 1;        
            for (int p=x; p<tam-1 ; p++)
                *(vet + p) = *(vet+p+1);            
            tam--;
            vet = (int*)realloc(vet, sizeof(int)*tam);
        }        
    return;
}
void encontra_2()
{
    for (int x = 0; x < tam; x++)
    {
        for (int y = 0; y < tam; y++)
        {
            if ( (n == *(vet+x) + *(vet+y)) && (*(vet+x) != *(vet+y) ) )
            {
                printf("retirados: %d + %d = %d\n", *(vet+x), *(vet+y), n);
                int a = x;
                int b = y;
                for (int z = 0; z < (tam - b); y++, z++)               
                    *(vet+y) = *(vet+y+1);
                for (int z = 0; z < (tam - a); x++, z++)                
                    *(vet+x) = *(vet+x+1);      
                tam--;tam--;
                vet = (int*)realloc(vet, sizeof(int)*tam);        
            }
        }
    }
    return;
}

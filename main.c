#include <stdio.h>      //ERENOMAD 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkLuhn(const char cardNo[16]) 
{ 
    int nDigits = strlen(cardNo); 
    int nSum = 0, isSecond = false; 
    for (int i = nDigits - 1; i >= 0; i--) { 
        int d = cardNo[i] - '0'; 
        if (isSecond == true) 
            d = d * 2; 
        nSum += d / 10; 
        nSum += d % 10;                  //ERENOMAD 
        isSecond = !isSecond; 
    } 
    return (nSum % 10 == 0); 
} 

int main() 
{ 
    char cardNo[16]; 
    printf("Kart Numarasını Girin: ");
    scanf("%s", cardNo);
    if (checkLuhn(cardNo)) 
    {
        printf("Bu Kart Geçerlidir. Tipi--> "); 
        char ilkDort[3]={cardNo[0],cardNo[1],'\0'};
        int kartTipi = strtol(ilkDort, NULL, 10);
        if ((kartTipi>=51) && (kartTipi<=55))
            printf("Mastercard");
        else if ((kartTipi>=40) && (kartTipi<=49))
            printf("Visa Kart");
        else
            printf("Visa/Master Dışında Bir Kart");   
    }     
    else
        printf("Bu Kart Geçerli Değildir"); 
    

    return 0; 
}

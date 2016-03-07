
//  Created by Dehelean Andrei on 3/1/16.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "domain.h"
#include <time.h>

void new_product(Product* prod,char* name, char* supplier, float quantity, p_time date){
    
    if(!prod){
        printf("Product is NULL");
        return;
    }
    prod -> name = malloc(sizeof(*name));
    strcpy(prod -> name, name);
    prod -> supplier = malloc(sizeof(*supplier));
    strcpy(prod -> supplier, supplier);
    prod -> date = date;
    prod -> quantity = quantity;
}

void destroy_product(Product* prod){
    if(!prod){
        printf("Product is NULL");
    }
    free(prod->name);
    prod->name = NULL;
    
    free(prod->supplier);
    prod->supplier = NULL;
    
    prod->quantity = -1;
    
}

int equal_prod(Product* prod1, Product* prod2){
    return prod1->name == prod2->name;
}



char* getName(Product* prod){
    return prod -> name;
}

char* getSupplier(Product* prod){
    return prod->supplier;
}

int getQuant(Product* prod){
    return prod->quantity;
}

p_time getDate(Product* prod){
    return prod->date;
}

int Expiration(Product *prod) {
    time_t raw_time;
    p_time tmp;
    time ( &raw_time );
    tmp = *gmtime ( &raw_time );
    time_t start_time, end_time;
    double seconds;
    
    p_time exp = prod->date;
    
    exp.tm_hour = 0;
    exp.tm_min = 0;
    exp.tm_sec = 0;
    exp.tm_year -= 1900;
    exp.tm_mon -= 1;
    
    tmp.tm_hour = 0;
    tmp.tm_min = 0;
    tmp.tm_sec = 0;
    
    start_time = mktime(&exp);
    end_time = mktime(&tmp);
    
    seconds = difftime(start_time, end_time);
    
    if(seconds < 0)
        return 1;
    return 0;
}


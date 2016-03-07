//
//  UI.c
//  L3-4
//
//  Created by Dehelean Andrei on 3/2/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "UI.h"
#include<stdio.h>
#include "controller.h"
#include "repository.h"
#include "domain.h" 
#include <string.h>
#include <stdlib.h>

void ui_init(UI* u, Contr* c){
    u -> contr = c;
}

void ui_destroy(UI *self) {
    free(self);
    self = NULL;
}

int ui__getInteger(const char *message) {
    char s[100];
    int ret = 0;
    printf(message);
    scanf("%s", s);
    while(sscanf(s, "%d", &ret) != 1) {
        printf(message);
        scanf("%s", s);
    }
    return ret;
}

float ui__getDouble(const char *message) {
    char s[100];
    float ret = 0;
    printf(message);
    scanf("%s", s);
    while(sscanf(s, "%f", &ret) != 1) {
        printf(message);
        scanf("%s", s);
    }
    return ret;
}

void ui__getString(char *s, const char *message) {
    printf(message);
    fgets(s, 100, stdin);
    fgets(s, 100, stdin);
    return ;
}

void ui__printMenu() {
    printf("Menu:\n");
    printf("1. Show materials in bakery\n");
    printf("2. Add object in bakery\n");
}

void ui_add(UI *ui, int readName, int readSupplier, int readQuantity, int readTime) {
    char name[100], supplier[100];
    p_time expDate;
    int quantity;
    if(readName)
        ui__getString(name, "Please input the name of the material: ");
    if(readSupplier)
        ui__getString(supplier, "Please input the name of the supplier: ");
    if(readQuantity)
        quantity = ui__getDouble("Please input the quantity: ");
    if(readTime) {
        expDate.tm_year = ui__getInteger("Expiration year: ");
        expDate.tm_mon = ui__getInteger("Expiration month: ");
        expDate.tm_mday = ui__getInteger("Expiration day: ");
    }
    addProd(ui->contr, name, supplier, quantity, expDate);
}


void run(UI *self) {
    while(1) {
        ui__printMenu();
        int cmd = ui__getInteger("Give a command");
        switch(cmd) {
            case 0:
                return ;
                break;
            case 1:
                ui_add(self, 1, 1, 1, 1);
                break;
            default:
                printf("You entered a wrong command");
        }
        
    }
}


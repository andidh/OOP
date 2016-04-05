//
//  console.c
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "console.h"
#include "domain.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ui_init(UI* ui, Contr* c){
    ui -> contr = c;
}

void ui_destroy(UI* ui){
    free(ui);
}


//-------------PRINT MEDICATION----------------
void toString(Repo* self){
    int len = vector_getLen(self->arr);
    for (int i=0; i<len; i++){
        Medication m = vector_getAt(self->arr, i);
        printf("Name: %s | Concentration: %.2f | Quantity: %d | Price: %.2f \n",
           get_name(&m),
           get_concentration(&m),
           get_quantity(&m),
           get_price(&m)
           );
    }
}

//--------READ INTEGER---------------
int readInteger(const char* message){
    int n;
    printf("%s", message);
    scanf("%d", &n);
    return n;
}

//---------READ FLOAT---------------
float readFloat(const char* message){
    float n;
    printf("%s", message);
    scanf("%f", &n);
    return n;
}

//----------READ STRING---------------
char* readString(const char* message){
     char* s = malloc(sizeof(*s));
     printf("%s", message);
     scanf("%s", s);
     return s;
}

//--------------ADD---------------------
void ui_add(UI* ui){
    char* name = readString("Give name: ");
    float concentration = readFloat("Give concentration: ");
    int quantity = readInteger("Give quantity: ");
    float price = readFloat("Give price: ");
    contr_add(ui -> contr, name, concentration, quantity, price);
    printf("-----------------\n");
}

//----------------MENU----------------------
void ui_printMenu() {
    printf("Menu:\n");
    printf("0. Exit\n");
    printf("1. Add a medication\n");
    printf("2. Show all\n");
    printf("3. Delete a medication\n");
    printf("4. Update\n");
    printf("5. Filter by name\n");
    printf("6. Filter by quantity\n");
    printf("7. Undo\n");
    printf("8. Redo\n");
}


//-------------GET ALL-----------------------
void ui_showAll(UI* ui){
    Repo* r = ui -> contr -> repo;
    toString(r);
    printf("-----------------\n");

}

//-------------DELETE-------------------------
void ui_delete(UI* ui){
    char* name = readString("Give name: ");
    contr_delete(ui->contr, name);
    printf("-----------------\n");

}


//-----------------UPDATE----------------------
void ui_update(UI* ui){
    char* name = readString("Give name: ");
    float concentration = readFloat("Give new concentration: ");
    int quantity = readInteger("Give new quantity: ");
    float price = readFloat("Give new price: ");
    contr_update(ui -> contr, name, concentration, quantity, price);
    printf("-----------------\n");
}

void ui_undo(UI *self) {
    if(!controller_undo(self->contr))
    printf("Cannot undo!\n");
}

void ui_redo(UI *self) {
    if(!controller_redo(self->contr))
    printf("Cannot redo!\n");
}













/*
//------------------FILTER BY NAME----------------
void ui_filter(UI* ui){
    char* name = readString("Give name: ");
    Repo* ex;
    ex = filterByName(ui->contr, name);
    toString(ex);
    printf("-----------------\n");


}

//------------------FILTER BY QUANTITY------------------
void ui_filterByQuantity(UI* ui){
    int quantity = readInteger("Give quantity: ");
    Repo* ex = malloc(sizeof(Repo));
    ex = filterSupply(ui->contr, quantity);
    toString(ex);
    printf("-----------------\n");
    
}
 */

void run(UI *self) {
    while(1) {
        ui_printMenu();
        int cmd = readInteger("Give a command: ");
        switch(cmd) {
            case 0:
                return ;
                break;
            case 1:
                ui_add(self);
                break;
            case 2:
                ui_showAll(self);
                break;
            case 3:
                ui_delete(self);
                break;
            case 4:
                ui_update(self);
                break;
            /*
             case 5:
                ui_filter(self);
                break;
            case 6:
                ui_filterByQuantity(self);
                break;
             h*/
                
            case 7:
                ui_undo(self);
                break;
            case 8:
                ui_redo(self);
                break;
            default:
                printf("You entered a wrong command");
        }
        
    }
}

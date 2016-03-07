//
//  UI.h
//  L3-4
//
//  Created by Dehelean Andrei on 3/2/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "controller.h"

typedef struct{
    Contr* contr;
}UI;


void ui_init(UI* u,Contr* c);

void ui_destroy(UI* c);

int ui__getInteger(const char *message);

float ui__getDouble(const char *message);

void ui__getString(char *s, const char *message);

void ui__printMenu();

void ui_add(UI *ui, int readName, int readSupplier, int readQuantity, int readTime);

void run(UI *self) ;
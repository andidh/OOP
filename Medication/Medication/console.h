//
//  console.h
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "controller.h"


typedef struct{
    Contr* contr;
}UI;


void ui_init(UI* ui, Contr* c);

void ui_destroy(UI* ui);

void toString(Repo* self);

void ui_add(UI* ui);

void run(UI *self);

void ui_printMenu();

void ui_showAll(UI* ui);

char* readString(const char* message);

float readFloat(const char* message);

void ui_update(UI* ui);

void ui_filterByQuantity(UI* ui);
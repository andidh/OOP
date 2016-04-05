//
//  main.c
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//


#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "console.h"
#include <stdlib.h>


void app() {
    Repo *repo = (Repo *) malloc(sizeof(Repo));
    Contr *ctrl = (Contr *) malloc(sizeof(Contr));
    repo_init(repo);
    contr_init(ctrl, repo);
    UI* ui = (UI *) malloc(sizeof(UI));
    
    ui_init(ui, ctrl);
    run(ui);
    ui_destroy(ui);
    contr_destroy(ctrl);
    repo_destroy(repo);

}

int main() {
    app();
    return 0;
    
}


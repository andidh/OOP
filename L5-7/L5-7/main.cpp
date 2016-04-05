//
//  main.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include <iostream>
#include "console.hpp"

int main(int argc, const char * argv[]) {
    Repository repo;
    Coat c1{"M","red",100,12,"http://fabfashionfix.com/wp-content/uploads/2013/02/red_trench_coat_new_look.jpg"};
    Coat c2{"M","beige",230,10,"http://www.telegraph.co.uk/content/dam/fashion/2015-09/sept7/zara-long-trench-coat-large.jpg"};
    Coat c3{"M","green",310,8,"https://36.media.tumblr.com/ba3a7861a4b3b879b0eed61c1ce39c5c/tumblr_o357i0Qzjm1sp5kc9o1_500.jpg"};
    
    repo.addCoat(c1);
    repo.addCoat(c2);
    repo.addCoat(c3);
    
    Controller ctrl(repo);
    UI ui(ctrl);
    
    
    ui.run();
    
    return 0;
}
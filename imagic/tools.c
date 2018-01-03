//
//  tools.c
//  imagic
//
//  Created by itzseven on 03/01/2018.
//  Copyright © 2018 itzseven. All rights reserved.
//

#include "tools.h"
#include <string.h>

#pragma mark - File management

const char *fexts(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) {
        return "";
    }
    
    return dot + 1;
}

#ifndef BSYS_H
#define BSYS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BSYS_LOG(str) (printf("[BSYS] %s\n", (str)))

static inline bool bsys_build(const char* args){
	char cmd[256];
	if(snprintf(cmd, sizeof(cmd), 
		"gcc %s -I./build -o program.exe && program.exe", args ) < 0){
		
		BSYS_LOG("ERROR: failed to encode build command");
		return false;
	}
	BSYS_LOG(cmd);

	return !system(cmd); // 0 on success
}

#endif // BSYS_H

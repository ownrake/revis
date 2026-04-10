// revis/core/src/main.c

#include "common.h"
#include "init.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return 1;
	}

	if (strcmp(argv[1], "init") == 0) {
		init();
	}

	return 0;
}
// revis/core/src/init.c

#include "common.h"
#include "fs.h"

int init() {
	create_dir(".revis");
	create_dir(".revis/objects");
	create_file(".revis/HEAD");

	return 0;
}
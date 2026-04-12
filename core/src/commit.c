// revis/core/src/commit.c

#include "common.h"
#include "compress.h"
#include "fs.h"
#include "object.h"
#include "sha256.h"

void print_content(const char *path) {
	char *content = get_file_content(path);
	char *hash = create_blob(".", content);
	// printf("%.64s\n", hash);
	printf("%s\n", hash);
	free(hash);
	free(content);
}

int commit(const char *message) {
	walk(".", print_content);

	return 0;
}
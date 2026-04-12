// revis/core/src/object.c

#include "common.h"
#include "fs.h"
#include "sha256.h"

char *create_blob(const char *header, const char *content) {
	char *hash = malloc(65);
	if (hash == NULL) return NULL;

	sha256_easy_hash_hex(content, strlen(content), hash);
	hash[64] = '\0';

	return hash;
}
#include <stdio.h>
#include <string.h>

#include "platforn.h"

int createDir(const char *path) {
	int status = MKDIR(path);
	if (status != 0) {
		perror("create_directory");
		return -1;
	}
	return 0;
}

int createFile(const char *path) {
	FILE *f;
	f = fopen(path, "w");
	fclose(f);

	return 0;
}

int init(char *basePath) {
	char fullPath[512];

	char revisFolederName[8] = "/.revis";
	char objectsFolderName[9] = "/objects";
	char headFileName[5] = "HEAD";

	strcat(basePath, revisFolederName);
	if (createDir(basePath) == 0) {
		printf(".revis folder created!\n");
	}

	snprintf(fullPath, sizeof(fullPath), "%s/%s", basePath, objectsFolderName);
	if (createDir(fullPath) == 0) {
		printf("objects folder created!\n");
	}

	snprintf(fullPath, sizeof(fullPath), "%s/%s", basePath, headFileName);
	if (createFile(fullPath) == 0) {
		printf("head file created!\n");
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc < 2) return 1;

	if (strcmp(argv[1], "init") == 0) {
		init(argv[2]);
	}
}
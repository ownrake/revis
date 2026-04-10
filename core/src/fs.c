// revis/core/src/fs.c

#include "common.h"

int create_file(const char *file_name) {
	FILE *file;
	file = fopen(file_name, "w");
	if (file == NULL) {
		return 1;
	}

	fclose(file);

	return 0;
}

int create_dir(const char *path_name) {
	if (mkdir(path_name, 0777) == -1) {
		return 1;
	}

	return 0;
}

int walk(const char *path, void(*callback)(const char *path)) {
	DIR *dir = opendir(path);

	if (dir == NULL) {
		return 1;
	}

	char full_path[512];

	struct dirent *entry;
	struct stat st;

	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
			continue;
		}

		snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

		if (stat(full_path, &st) == 0) {
			if (S_ISDIR(st.st_mode)) {
				walk(full_path, callback);
			} else {
				callback(full_path);
			}
		} else {
			fprintf(stderr, "Cannot stat %s\n", full_path);
		}
	}

	return 0;
}
// ./revis/src/fileops.c

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int create_dir(const char *path) {
	/*
		TODO: функция создания файла
	*/
}

int create_file(const char *path) {
	FILE *file_p = fopen(path, "w");
	if (file_p == NULL) {
		return 1;
	}

	fclose(file_p);
	
	return 0;
}

int walk(const char *path, void(*callback)(const char *path)) {
	DIR *dir_p = opendir(path);

	char full_path[512];

	struct dirent *entry;
	struct stat st;

	if (dir_p == NULL) {
		return 1;
	}

	while((entry = readdir(dir_p)) != NULL) {
		/*
			TODO: проверка игнорируемых папок/файлов
		*/

		snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

		if (stat(full_path, &st) == 0 && (st.st_mode & __S_IFDIR)) {
			walk(full_path, callback);
		} else {
			callback(full_path);
		}
	}

	closedir(dir_p);
	
	return 0;
}
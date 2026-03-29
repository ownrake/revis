#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void walk(const char *path, void(*callback)(const char *path)) {
	DIR *dir;

	char fullpath[512];

	struct dirent *entry;
	struct stat st;

	dir = opendir(path);
	if (dir == NULL) return;

	while((entry = readdir(dir)) != NULL) {
		/*
			TODO: верификация имен файлов, отсеивание файлов из конфига
		*/
		
		snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

		if (stat(fullpath, &st) == 0 && (st.st_mode & __S_IFDIR)) {
			walk(fullpath, callback);
		} else {
			callback(fullpath);
		}
	}

	closedir(dir);
}
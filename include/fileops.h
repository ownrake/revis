// ./revis/include/fileops.h

int create_dir(const char *path);
int create_file(const char *path);
int walk(const char *path, void(*callback)(const char *path));
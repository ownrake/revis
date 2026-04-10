// revis/core/include/fs.h

int create_file(const char *name, int parents);
int create_dir(const char *path, int parents);
int walk(const char *path, void(*callback)(const char *path));
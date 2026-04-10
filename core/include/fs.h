// revis/core/include/fs.h

int create_file(const char *name);
int create_dir(const char *path);
int walk(const char *path, void(*callback)(const char *path));
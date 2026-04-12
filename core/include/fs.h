// revis/core/include/fs.h

#ifndef FS_H
#define FS_H

int create_file(const char *name);
char *get_file_content(const char *path);
int create_dir(const char *path);
int walk(const char *path, void(*callback)(const char *path));

#endif
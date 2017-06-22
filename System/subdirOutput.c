#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

void add_all_files(char *wd,char *dir);

int main(int argc, char **argv)
{
    printf("Sub-Directory Output!!\n");
    printf("--------------\n");

    add_all_files(argv[1],"");

    return 0;
}

void add_all_files(char *wd,char *dir)
{
    struct dirent *dentry;
    struct stat fstat;
    DIR *dirp;
    int i;

    if(chdir(wd) < 0) {
        printf("error: chdir..\n");
        exit(1);
    }

    if((dirp = opendir(".")) == NULL){
        printf("error: opendir..\n");
        exit(1);
    }

    while(dentry = readdir(dirp)){
        if(dentry->d_ino != 0){
            if((!strcmp(dentry->d_name,".")) || (!strcmp(dentry->d_name, "..")))
                continue;
            stat(dentry->d_name, &fstat);

            if(S_ISDIR(fstat.st_mode)){
                char *dir_name = malloc(strlen(dir) + dentry->d_reclen + 1);
                sprintf(dir_name,"%s%s/",dir,dentry->d_name);
                add_all_files(dentry->d_name,dir_name);
                free(dir_name);
            } else {
                printf("%s%s\n",dir,dentry->d_name);
            }
        }
    }
    closedir(dirp);
    chdir("..");
}

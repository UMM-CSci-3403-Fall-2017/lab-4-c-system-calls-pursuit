#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ftw.h>
#include <sys/stat.h>

#define MAX_FTW_DEPTH 16
static int num_dirs, num_regular;

// reminds me of rebotis with some of these paths.
static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    if (typeflag==FTW_F){
    	num_regular++;
    }
    else if (typeflag==FTW_D){
        if(strcmp(fpath,".")!=0|| strcmp(fpath,"..")!=0){
    	num_dirs++;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    // Check arguments while setting things up
    num_dar=0, num_regular=0;
    ftw(argv[1], callback, MAX_FTW_DEPTH);
    printf("There were %d directories. \n", num_dirs);
    printf("There were %d regular files. \n", num_regular);
}

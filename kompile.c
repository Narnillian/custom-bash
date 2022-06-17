#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct timespec ts;


int main(int argc, char** argv) {
    
    ts.tv_nsec = 100000000;
    int result = 0;

    if (argc == 1) {
        printf("Please include a Kotlin file to be compiled, and the path of the resulting .jar file.\n");
        printf("Alternatively, append `-h` to this command for usage information.\n");
        return 0;
    } else if (argc == 2 && !strcmp(argv[1], "-h")) {
        printf("Custom command to compile and execute Kotlin with one command, because the actual command is too long:\n");
        printf("Original command:   kotlinc source.kt -include-runtime -d result.jar [options]\n");
        printf("Custom command usage:\n");
        printf("\tcompkot source.kt result.jar [options]\n");
        printf("\tkompile source.kt result.jar [options]\n");
        printf("[options] (such as `-verbose`) applies to both Kotlin compilation *and* Java .jar execution\n");
        printf("\nMy puns are superb\t\t\t\tThis is a custom command, not APT, but my APT has Super Cow Powers\t(apt-get moo)\n");
    } else {
        {
            char *str1 = strcat(strcat(strcpy(malloc(strlen("kotlinc ") + strlen(argv[1]) + strlen(" -include-runtime -d") + 1), "kotlinc "), argv[1]),  " -include-runtime -d");
            char *str2 = malloc(1);
            *str2 = 0;
            char ignore = 0;
            for (int i = 2; i < argc; i++) {
                if (*argv[i] == ']') {ignore = 0;continue;}
                if (ignore) continue;
                if (*argv[i] == '[') {ignore = 1;continue;}

                str2 = realloc(str2, strlen(str2) + strlen(argv[i]) + 2);
                strcat(str2, " ");
                strcat(str2, argv[i]);
            }
            str1 = strcpy(malloc(strlen(str1) + strlen(str2) + 2), str1);
            strcat(str1,str2);
            //printf("COMMAND:   \"%s\"\n",str1);
            printf("\nCompiling \"%s\" to \"\033[1;91m%s\033[0m\" via \"\033[1;36m%s\033[0m\"\n",argv[1],argv[2],str1);
            nanosleep(&ts,NULL);
            printf("------------------\n");
            nanosleep(&ts,NULL);
            result = system(str1);
            free(str1);
            free(str2);
        }
        if (result) {
            printf("------------------\n");
            nanosleep(&ts,NULL);
            printf("Compilation failed\n");
            return result;
        } else {
            printf("Compilation completed\n");
            nanosleep(&ts,NULL);
            printf("------------------\n");
            nanosleep(&ts,NULL);
            {
                char *str1 = malloc(1);
                *str1 = 0;
                str1 = realloc(str1, strlen("java -jar") + 1);
                strcat(str1, "java -jar");
                for (int i = 3; i < argc; i++) {
                    str1 = realloc(str1, strlen(str1) + strlen(argv[i]) + 1);
                    strcat(str1, " ");
                    strcat(str1, argv[i]);
                }
                str1 = strcpy(malloc(strlen(str1) + 2),str1);
                strcat(str1," ");
                str1 = strcpy(malloc(strlen(str1) + strlen(argv[2]) + 1),str1);
                strcat(str1,argv[2]);
                printf("Executing \"%s\" via \"%s\"\n", argv[2], str1);
                nanosleep(&ts,NULL);
                printf("------------------\n");
        ts.tv_nsec = 100000000;
                nanosleep(&ts,NULL);
                system(str1);
                free(str1);
                return 0;
            }
        }
    }
}

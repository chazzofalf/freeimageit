#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	if (argc==2)
	{
		const char *format="id ; hdiutil create -srcfolder \"%s\" -format UDBZ \"%s\".dmg ; chown %u \"%s\".dmg";
		int user=getuid();
		char *command=(char *)malloc(sizeof(char)*4096);
		char *flder=argv[1];
		int len=strlen(flder);
		if (flder[len-1] == '/')
		{
			flder[len-1] = '\0';
		}
		sprintf(command,format,flder,flder,user,flder);
		setuid(0);
		execl("/bin/bash","bash","-c",command,NULL);
	}
	else
	{
		printf("Need exactly one folder argument.\n");
	}
}

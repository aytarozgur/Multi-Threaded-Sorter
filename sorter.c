#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "mergesort.c"
#include "sorter.h"
#include "directory.c"


#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

pid_t arr[256];
int p=0;
 int nk=0;

char isAlreadySorted(char* newPath){
  int i=0;
  //printf("CALLING: IS ALREADY SORTED\n");
//  printf("NEW PATH %s\n", newPath);
  for(i=0; i<strlen(newPath); i++){
    if(newPath[i] == 's' && newPath[i+1] == 'o' && newPath[i+2] == 'r' && newPath[i+3] == 't'
      && newPath[i+4] == 'e' && newPath[i+5] == 'd'){
      //printf("THIS FILE IS ALREADY SORTED\n");
      return 't';
    }
  }
  return 'f';
}

void printDirInfo(char *dir, char* param) {
    int initialpidBool=0;
    int initialpid=0;
    int pid;

	DIR *directory = NULL;
	struct dirent *curObj = NULL;
	if ((directory = opendir(dir)) == NULL) {
		fprintf(stderr, "Can't open directory: %s\n", dir);
		return;
	}
	while (curObj = readdir(directory)) {
		if (!strcmp(".", curObj->d_name) || !strcmp("..", curObj->d_name)) {
            //printf("hello\n");
			continue;
		}
		if (curObj->d_type == DT_REG) {
			char * newPath = (char *) malloc(strlen(curObj->d_name)
					+ strlen(dir) + 2);

			newPath[0] = '\0';
			strcpy(newPath, dir);
			char* pathWOcsv=newPath;
			strcat(newPath, "/");
			//char* pathWOcsv=newPath;
			//printf("this is pathWO %s\n",pathWOcsv);
			//int filedescriptor = open(pathWOcsv/"my_log.txt", O_RDWR | O_APPEND | O_CREAT);
			strcat(newPath, curObj->d_name);

			int fd = open(newPath, O_RDONLY);
			if (fd < 0) {
				fprintf(stderr, "Can't open file: %s\n", newPath);
				return;
			}
			int len = lseek(fd, 0, SEEK_END);
			close(fd);

			//printf("%-30s%s%d\n", newPath, " ", len);

			//ok so here is where you forl
			int length=strlen(newPath);
			//printf("file name hm %s\n", curObj->d_name);
			if(newPath[length-1]=='v'||newPath[length-2]=='s'||newPath[length-3]=='c'){
            char sortorNot=isAlreadySorted(newPath);
            //printf("ets se %c\n",sortorNot);

            if(isAlreadySorted(newPath) == 'f'){
              pid=fork();
              wait();
              //printf("this is pathWO %s\n",pathWOcsv);

              if(pid == 0)
              {
                char * stuff=(char*)malloc(sizeof(char*)*10);
  			        stuff="no";
                start(newPath,curObj->d_name,param,pathWOcsv,stuff);
                //return 0;
              }


                arr[p]=getpid();
                 //printf("arrp %d\n",arr[p]);
                p++;

            }
			}

			free(newPath);
		}
		else if (curObj->d_type == DT_DIR) {
			char * newPath = (char *)malloc(strlen(curObj->d_name)
					+ strlen(dir) + 2);

			newPath[0] = '\0';

			strcpy(newPath, dir);
			strcat(newPath, "/");
		    //////////////////////

			strcat(newPath, curObj->d_name);
			//printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET "\n", newPath);
			 pid=fork();

         arr[p]=getpid();
          //printf("arrp %d\n",arr[p]);
         p++;
       if(pid == 0)
       {
         //char * stuff=(char*)malloc(sizeof(char*)*10);
         //stuff="no";
         printDirInfo(newPath,param);
         //start(newPath,curObj->d_name,param,pathWOcsv,stuff);
         //return 0;
       }

         arr[p]=getpid();
          //printf("arrp %d\n",arr[p]);
         p++;


			free(newPath);
		}
	}

  //free(arr);
 /*
  int i = 0;
  printf("PIDS of ALL child Processes: ");
  for(i = 0; i < p; i++)
  {
    wait(NULL);
    printf("%d,", arr[i]);
  }
  printf("\nTotal Number of Processes: %d\n", p);
  wait();
  */
	closedir(directory);
	return;
}


void Case3printDirInfo(char *dir, char* param,char* thatDir) {
    int initialpidBool=0;
    int initialpid=0;
    int pid;


	DIR *directory = NULL;
	struct dirent *curObj = NULL;
	if ((directory = opendir(dir)) == NULL) {
		fprintf(stderr, "Can't open directory: %s\n", dir);
		return;
	}
	while (curObj = readdir(directory)) {
		if (!strcmp(".", curObj->d_name) || !strcmp("..", curObj->d_name)) {
            //printf("hello\n");
			continue;
		}
		if (curObj->d_type == DT_REG) {
			char * newPath = (char *) malloc(strlen(curObj->d_name)
					+ strlen(dir) + 2);

			newPath[0] = '\0';
			strcpy(newPath, dir);
			char* pathWOcsv=newPath;
			strcat(newPath, "/");

			strcat(newPath, curObj->d_name);

			int fd = open(newPath, O_RDONLY);
			if (fd < 0) {
				fprintf(stderr, "Can't open file: %s\n", newPath);
				return;
			}
			int len = lseek(fd, 0, SEEK_END);
			close(fd);

			//printf("%-30s%s%d\n", newPath, " ", len);

			//ok so here is where you forl
			int length=strlen(newPath);
			//printf("file name hm %s\n", curObj->d_name);
			if(newPath[length-1]=='v'||newPath[length-2]=='s'||newPath[length-3]=='c'){
            char sortorNot=isAlreadySorted(newPath);
            //printf("ets se %c\n",sortorNot);

            if(isAlreadySorted(newPath) == 'f'){
              pid=fork();

			//printf("this is pathWO %s\n",pathWOcsv);
              start(newPath,curObj->d_name,param,pathWOcsv, thatDir);
             arr[p]=getpid();
               //printf("arrp %d\n",arr[p]);
              p++;
            }

			}

			free(newPath);



		}
		else if (curObj->d_type == DT_DIR) {
			char * newPath = (char *)malloc(strlen(curObj->d_name)
					+ strlen(dir) + 2);

			newPath[0] = '\0';

			strcpy(newPath, dir);
			strcat(newPath, "/");
		    //////////////////////

			strcat(newPath, curObj->d_name);
			//printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET "\n", newPath);
			 pid=fork();
               arr[p]=getpid();
                 //printf("arrp %d\n",arr[p]);
                p++;
			Case3printDirInfo(newPath,param,thatDir);
			free(newPath);
		}
	//wait();
	}
  wait();
  fflush(stdout);
	closedir(directory);
	return;
}

int main(int argc, char * argv[]) {

	char * base = ".";
	char * param = argv[2];
  char * col = argv[1];

  if(strcmp(col, "-c")!=0){
    printf("invalid parameter\n");
    exit(1);
  }

	if (argc == 3) {
    //printf("Directory index from %s\n", base);
	printDirInfo(base,param);

	}


	if (argc == 5) {
    char* directoryParam = argv[3];
    if(strcmp(directoryParam, "-d")!=0){
      printf("invalid parameter\n");
      exit(1);
    }

	    base="./";
        char * givenDir= (char*)malloc(sizeof(argv[4])+3);
		strcpy(givenDir,base);
        strcat(givenDir,argv[4]);
		//printf("Directory index from %s\n", givenDir);
        printDirInfo(givenDir,param);

	}


	if (argc == 7) {
    char* directoryParam = argv[3];
    if(strcmp(directoryParam, "-d")!=0)
    {
      printf("invalid parameter\n");
      exit(1);
    }
	    base="./";
        char * givenDir= (char*)malloc(sizeof(argv[4])+3);
		strcpy(givenDir,base);
        strcat(givenDir,argv[4]);
		char * thatDir=argv[6];
        Case3printDirInfo(givenDir,param,thatDir);
	}

  printf("Parent PID: %d\n", getpid());
  int parentPID = getpid();
  if(getpid()!=arr[0]){
    exit(0);
  }

 int i = 0;
  printf("PIDS of ALL child Processes: ");
  for(i = 0; i < p; i++)
  {
    wait(NULL);
    printf("%d,", arr[i]);
  }
  printf("\nTotal Number of Processes: %d\n", p);

  nk++;
  if(nk==p-1){
    printf("letsssss goo");
  }


	return 0;
}

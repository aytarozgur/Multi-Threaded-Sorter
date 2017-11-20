#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sorter.h"
#include <math.h>

void start(char* filePath, char* filename) {

    FILE *fp;
    fp = fopen(filePath,"r");
}
char isValidCSV(char* csvFilePath, char* csvFilename){
  //open csv and check first row
  //printf("Checking: %s\n", csvFilename);

  char buffer[1024];
  char *line;
  char *token;
  const char* s = ",";

  FILE *file  = fopen(csvFilePath, "r");
  if(file == NULL){
    printf("error opening CSV %s\n", csvFilename);
    return 'f';
  }
  //This is the first line in the CSV, check if valid headings
  line = fgets(buffer, sizeof(buffer), file);
  token = strtok(line, s);
  while(token!=NULL){
    //printf("token: %s\n", token);
    token = strtok(NULL, s);
    /*
      NEED TO HANDLE INVALID HEADINGS CASE
    */
  }
  return 't';
}

char isValidColumn(char* sortColumn){
  if(
    strcmp(sortColumn, "color")!= 0
    && strcmp(sortColumn, "director_name")!= 0
    && strcmp(sortColumn, "num_critic_for_reviews")!= 0
    && strcmp(sortColumn, "duration")!= 0
    && strcmp(sortColumn, "director_facebook_likes")!= 0
    && strcmp(sortColumn, "actor_3_facebook_likes")!= 0
    && strcmp(sortColumn, "actor_2_name")!= 0
    && strcmp(sortColumn, "actor_1_facebook_likes")!= 0
    && strcmp(sortColumn, "gross")!= 0
    && strcmp(sortColumn, "genres")!= 0
    && strcmp(sortColumn, "actor_1_name")!= 0
    && strcmp(sortColumn, "movie_title")!= 0
    && strcmp(sortColumn, "num_voted_users")!= 0
    && strcmp(sortColumn, "cast_total_facebook_likes")!= 0
    && strcmp(sortColumn, "actor_3_name")!= 0
    && strcmp(sortColumn, "facenumber_in_poster")!= 0
    && strcmp(sortColumn, "plot_keywords")!= 0
    && strcmp(sortColumn, "movie_imdb_link")!= 0
    && strcmp(sortColumn, "num_user_for_reviews")!= 0
    && strcmp(sortColumn, "language")!= 0
    && strcmp(sortColumn, "country")!= 0
    && strcmp(sortColumn, "content_rating")!= 0
    && strcmp(sortColumn, "budget")!= 0
    && strcmp(sortColumn, "title_year")!= 0
    && strcmp(sortColumn, "actor_2_facebook_likes")!= 0
    && strcmp(sortColumn, "imdb_score")!= 0
    && strcmp(sortColumn, "aspect_ratio")!= 0
    && strcmp(sortColumn, "movie_facebook_likes")!= 0){
    return 'f';
  }
  return 't';
}

char* isValidParameter(int argc, char* argv[]){
  int i;
  char* sortColumn = "z";
  for(i=0; i<sizeof(argv); i++){
    if(argv[i]!= NULL){
        //check if -c is present (mandatory)
      if(strcmp("-c", argv[i]) == 0){
        //next item in argv is going to be the column to sort
        //so check if sortColumn is a valid column to sort on
        sortColumn = argv[i+1];
        if(isValidColumn(sortColumn) == 'f'){
          printf("invalid parameters\n");
          exit(1);
        }
        return sortColumn;
      }
    }
  }
}

char isAlreadySorted(char* newPath){
  int i=0;
  for(i=0; i<strlen(newPath); i++){
    if(newPath[i] == 's' && newPath[i+1] == 'o' && newPath[i+2] == 'r' && newPath[i+3] == 't'
      && newPath[i+4] == 'e' && newPath[i+5] == 'd'){
      printf("THIS FILE IS ALREADY SORTED\n");
      return 't';
    }
  }
  return 'f';
}

void printDirInfo(char *directory) {
	DIR *current = NULL;
	struct dirent *object = NULL;
	if ((current = opendir(directory)) == NULL) {
		fprintf(stderr, "Can't open directory: %s\n", directory);
		return;
	}
	while (object = readdir(current)) {
		if (!strcmp(".", object->d_name) ||
				!strcmp("..", object->d_name)) {
			continue;
		}
		if (object->d_type == DT_REG) {
			char * Path = (char *) malloc(strlen(object->d_name)+ strlen(directory) + 2);

			Path[0] = '\0';
			strcpy(Path, directory);
			strcat(Path, "/");
			strcat(Path, object->d_name);
			int fd = open(Path, O_RDONLY);
			if (fd < 0) {
				fprintf(stderr, "Can't open file: %s\n", Path);
				return;
			}
			int length = lseek(fd, 0, SEEK_END);
			close(fd);
			int len=strlen(Path);
      if(Path[len-1]=='v'&&Path[len-2]=='s'&&Path[len-3]=='c'){
        if(isAlreadySorted(Path) == 'f'){
          //Check if valid CSV
          if(isValidCSV(Path, object->d_name) == 't'){
              //Enable multithreading here
              printf("valid: %s\n", object->d_name);
          }
        }
			}
			free(Path);
		}
		else if (object->d_type == DT_DIR) {
			char * Path = (char *)malloc(strlen(object->d_name)
					+ strlen(directory) + 2);

			Path[0] = '\0';

			strcpy(Path, directory);
			strcat(Path, "/");
			strcat(Path, object->d_name);
			printDirInfo(Path);
			free(Path);
		}
	}
	closedir(current);
	return;
}

int main(int argc, char * argv[]) {
  if(argc < 1){
    printf("invalid parameters\n");
    exit(1);
  }
  if(argc>7){
    printf("invalid parameters\n");
    exit(1);
  }
  char* sortedColumn;
  char* startingDirectory = ".";
  char* outputDirectory;
  //Check if valid sorting column
  sortedColumn = isValidParameter(argc, argv);
  //determine if starting and output directories present
  int i;
  for(i=0; i<sizeof(argv); i++){
    if(argv[i]!=NULL){
      //check if -d is present (optional)
      if(strcmp("-d", argv[i]) == 0){
        startingDirectory = argv[i+1];
      }
      //check if -o is present (optional)
      if(strcmp("-o", argv[i]) == 0){
        outputDirectory = argv[i+1];
      }
    }
  }

  printf("Directory index from %s\n", startingDirectory);
  printDirInfo(startingDirectory);

	return 0;
}

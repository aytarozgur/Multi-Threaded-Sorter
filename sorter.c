#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sorter.h"
#include <math.h>


#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void start(char* filePath, char* filename) {




    /*
    int pathLength=strlen(filePath)-strlen(filename);


     char *WOcsvtoken=(char*)malloc(sizeof(char*)*50);
     int n=0;
     while(n<pathLength-1){

        WOcsvtoken[n]=filePath[n];
        n++;
     }
    //printf("this is toke %s\n",WOcsvtoken);



    char current[200];
    int length=strlen(filePath);
    int t=0;
    while(t<length+1){
        current[t]=filePath[t];
        t++;
    }
*/

    FILE *fp;
    fp = fopen(filePath,"r");

    /*
    char *categories=(char*)malloc(sizeof(char)*500);//this holds the first line till its parsed
    fgets(categories,500,fp);


    t =0;
    length=strlen(categories);
    int c=0;

    while(t<length)
    {
        if(categories[t]==','){
            c++;
        }
        t++;
    }

    if(c !=27){
        printf("invalid amount of categories\n");
        exit(1);
    }

    Records* input= (Records*)malloc(sizeof(Records)*8000);

    if(
    strcmp(param, "color")!= 0
    && strcmp(param, "director_name")!= 0
    && strcmp(param, "num_critic_for_reviews")!= 0
    && strcmp(param, "duration")!= 0
    && strcmp(param, "director_facebook_likes")!= 0
    && strcmp(param, "actor_3_facebook_likes")!= 0
    && strcmp(param, "actor_2_name")!= 0
    && strcmp(param, "actor_1_facebook_likes")!= 0
    && strcmp(param, "gross")!= 0
    && strcmp(param, "genres")!= 0
    && strcmp(param, "actor_1_name")!= 0
    && strcmp(param, "movie_title")!= 0
    && strcmp(param, "num_voted_users")!= 0
    && strcmp(param, "cast_total_facebook_likes")!= 0
    && strcmp(param, "actor_3_name")!= 0
    && strcmp(param, "facenumber_in_poster")!= 0
    && strcmp(param, "plot_keywords")!= 0
    && strcmp(param, "movie_imdb_link")!= 0
    && strcmp(param, "num_user_for_reviews")!= 0
    && strcmp(param, "language")!= 0
    && strcmp(param, "country")!= 0
    && strcmp(param, "content_rating")!= 0
    && strcmp(param, "budget")!= 0
    && strcmp(param, "title_year")!= 0
    && strcmp(param, "actor_2_facebook_likes")!= 0
    && strcmp(param, "imdb_score")!= 0
    && strcmp(param, "aspect_ratio")!= 0
    && strcmp(param, "movie_facebook_likes")!= 0){
    printf("invalid parameter\n");
    exit(1);
  }

    int amount_of_lines=0;
    while(!feof(fp))
    {
     fgets(categories,500,fp);
     amount_of_lines++;
    }

    amount_of_lines--;
    rewind(fp);

    fgets(categories,500,fp);


    int count=450;//counts the lines we reach;
    int amountofLines=0;
    int y;
    int i=0;//interate current line
    int j=0;//used to add to token
    int s=0;//iterate through input
    int commas=0;
    char token[300];
    char *line=(char*)malloc(sizeof(char)*500);//this will hold the current line till its parsed


    char *data_type =(char*)malloc(sizeof(char)*10);


    for(y =0; y<10; y++){
      data_type[i] = '-';
    }
    data_type=findColumnType(param);

    int countline=0;
    while(countline<amount_of_lines)
    {

        amountofLines++;

        if(amountofLines==count){
        count=count*2;
        //input= realloc(input,sizeof(Records)*count);
        }

        i=0;
        j=0;
        commas=0;

        fgets(line,500,fp);

        while(i < strlen(line))
        {


            if(line[i]==',')
            {
                commas++;
                switch (commas)
                {

                    case 1:

                     //printf("this is color token %s\n",token);
                        strncpy(input[s].color, token, 50);
                        memset(token, 0, 300);//empties token array
                      //  printf("this is color %s\n",input[s].color);
                    break;

                    case 2:
                       // printf("this is director token %s\n",token);
                        strncpy(input[s].director_name, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is director name %s\n",input[s].director_name);
                    break;

                    case 3:
                        input[s].num_critic_for_reviews=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is num critics %i\n",input[s].num_critic_for_reviews);
                    break;

                    case 4:
                        input[s].duration=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is duration %i\n",input[s].duration);
                    break;

                    case 5:
                        input[s].director_facebook_likes=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is director facebook likes %i\n",input[s].director_facebook_likes);
                    break;

                    case 6:
                        input[s].actor_3_facebook_likes=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is actor 3 fb likes %i\n",input[s].actor_3_facebook_likes);
                    break;

                    case 7:
                        strncpy(input[s].actor_2_name, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is actor 2 name %s\n",input[s].actor_2_name);
                    break;

                    case 8:
                        input[s].actor_1_facebook_likes=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is actor 1 fb likes %i\n",input[s].actor_1_facebook_likes);
                    break;

                    case 9:
                        input[s].gross=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is gross %i\n",input[s].gross);
                    break;

                    case 10:
                        strncpy(input[s].genres, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is genre %s\n",input[s].genres);
                    break;

                    case 11:
                        strncpy(input[s].actor_1_name, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is actor 1 name %s\n",input[s].actor_1_name);
                    break;

                    case 12:
                        while(!isdigit(line[i+1])){



                            if(line[i]== ','){
                                //printf("i should make it in here after second I \n");
                                token[j]=' ';
                            }else if(line[i]== '"'){
                            token[j]=' ';

                            }

                            else{
                            token[j]=line[i];
                            }


                            j++;
                            i++;




                        }


                        strncpy(input[s].movie_title, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is movie title %s\n",input[s].movie_title);
                    break;

                    case 13:
                        input[s].num_voted_users=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is num voted users %i\n",input[s].num_voted_users);
                    break;

                    case 14:
                        input[s].cast_total_facebook_likes=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is cast total facebook likes %i\n",input[s].cast_total_facebook_likes);
                    break;

                    case 15:
                        strncpy(input[s].actor_3_name, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is actor 3 name %s\n",input[s].actor_3_name);
                    break;

                    case 16:
                        input[s].facenumber_in_poster=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is face num in poster %i\n",input[s].facenumber_in_poster);
                    break;

                    case 17:
                        strncpy(input[s].plot_keywords, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is plot keywords %s\n",input[s].plot_keywords);
                    break;

                    case 18:
                        strncpy(input[s].movie_imdb_link, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is imbd link %s\n",input[s].movie_imdb_link);
                    break;

                    case 19:
                        input[s].num_user_for_reviews=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is num user for review %i\n",input[s].num_user_for_reviews);
                    break;

                    case 20:
                        strncpy(input[s].language, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is language %s\n",input[s].language);
                    break;

                    case 21:
                        strncpy(input[s].country, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is language %s\n",input[s].country);
                    break;

                    case 22:
                        strncpy(input[s].content_rating, token, 50);
                        memset(token, 0, 300);//empties token array
                        //printf("this is content rating %s\n",input[s].content_rating);
                    break;

                    case 23:
                        input[s].budget=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is budget %i\n",input[s].budget);
                    break;

                    case 24:
                        input[s].title_year=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is title year %i\n",input[s].title_year);
                    break;

                    case 25:
                        input[s].actor_2_facebook_likes=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is actor 2 facebook likes %i\n",input[s].actor_2_facebook_likes);
                    break;

                    case 26:
                        input[s].imdb_score=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is imdb %i\n",input[s].imdb_score);
                    break;

                    case 27:
                        input[s].aspect_ratio=atoi(token);
                        memset(token, 0, 300);//empties token array
                        //printf("this is aspect ratio %i\n",input[s].aspect_ratio);
                    break;


                }
                //printf("we got a comma %s\n",token);
                j=0;
                i++;
            }
            else
            {
                if(line[i]=='a'||line[i]=='A'||line[i]=='b'||line[i]=='B' || line[i]=='c'||line[i]=='C'||line[i]=='d'||line[i]=='D'||line[i]=='e'||line[i]=='E'||
                   line[i]=='f'||line[i]=='F'||line[i]=='g'||line[i]=='G' || line[i]=='h'||line[i]=='H'||line[i]=='i'||line[i]=='I'||line[i]=='j'||line[i]=='J'||
                   line[i]=='k'||line[i]=='K'||line[i]=='l'||line[i]=='L' || line[i]=='m'||line[i]=='M'||line[i]=='n'||line[i]=='N'||line[i]=='o'||line[i]=='O'||
                   line[i]=='p'||line[i]=='P'||line[i]=='q'||line[i]=='Q' || line[i]=='r'||line[i]=='R'||line[i]=='s'||line[i]=='S'||line[i]=='t'||line[i]=='T'||
                   line[i]=='u'||line[i]=='U'||line[i]=='v'||line[i]=='V' || line[i]=='w'||line[i]=='W'||line[i]=='x'||line[i]=='X'||line[i]=='y'||line[i]=='Y'||
                   line[i]=='z'||line[i]=='Z'||line[i]==' '||line[i]=='?'||line[i]=='_'||line[i]=='-'||line[i]=='.'||line[i]=='/'||line[i]=='|'||line[i]=='?'||
                   line[i]=='1'||line[i]=='2'||line[i]=='3'||line[i]=='4'||line[i]=='5'||line[i]=='6'||line[i]=='7'||line[i]=='8'||line[i]=='9'||line[i]=='0'
                   ){

                    token[j]=line[i];
                    j++;
                   }



                //token[j]=line[i];
               // printf("we got a character %c\n",line[i]);
                i++;

            }


        }
        countline++;

            input[s].movie_facebook_likes=atoi(token);
            memset(token, 0, 300);//empties token array
            //printf("this is movie facebook likes %i\n",input[s].movie_facebook_likes);
            s++;

    }
    //const char *param = argv[2];
    const char *sortBY=param;

    free(categories);
    int arraySize = s;
    int q=0;

    mergeSort(&input,0,s-1,data_type,sortBY);

    if(thatDir[0]=='n'){
     print_csv_file(&input, s, filePath, filename, sortBY,WOcsvtoken);
    }else{

    Thirdprint_csv_file(&input, s, filePath, filename, sortBY,thatDir);

    }


    */
}










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
			//printf("this is not Path %s\n",Path);
            if(Path[len-1]=='v'&&Path[len-2]=='s'&&Path[len-3]=='c'){
            //char sortorNot=isAlreadySorted(Path);
         //  printf("tada\n");
            //printf("ets se %c\n",sortorNot);

            if(isAlreadySorted(Path) == 'f'){


                parse(Path,object->d_name);

             /* pid=fork();
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
*/
            }


			}


			printf("%-30s%s%d\n", Path, " ", length);
			free(Path);
		}
		else if (object->d_type == DT_DIR) {
			char * Path = (char *)malloc(strlen(object->d_name)
					+ strlen(directory) + 2);

			Path[0] = '\0';

			/* choice 1: do not add ./ to directory
			if (strcmp(dir, ".")) {
				strcpy(Path, dir);
				strcat(Path, "/");
			}*/
		    ///////////////////////
			// choice 2: add ./ to directory
			strcpy(Path, directory);
			strcat(Path, "/");
		    //////////////////////

			strcat(Path, object->d_name);
			printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET "\n", Path);
			printDirInfo(Path);
			free(Path);
		}
	}
	closedir(current);
	return;
}

int main(int argc, char * argv[]) {
	char * base = ".";
	if (argc >= 2) {
		base = argv[1];
	}
	printf("Directory index from %s\n", base);
	printDirInfo(base);
	return 0;
}

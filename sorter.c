#include "sorter.h"



void parser(char* csvFilePath, char* csvFilename, char* param){
        //printf("Checking: %s\n", csvFilename);

        char buffer[1024];
        char *line;
        //char *token;
        const char* s = ",";
        //open csv and check first row
        FILE *fp  = fopen(csvFilePath, "r");
        if(fp == NULL) {
                printf("error opening CSV %s\n", csvFilename);
                fclose(fp);

        }
        //No error in heading so continue parsing
        else{
                //This is the first line in the CSV, check if valid headings
                /*line = fgets(buffer, sizeof(buffer), file);
                   token = strtok(line, s);
                   while(token!=NULL) {
                        //printf("token: %s\n", token);
                        token = strtok(NULL, s);

                        NEED TO HANDLE INVALID HEADINGS CASE

                   }*/
                char *line=(char*)malloc(sizeof(char)*500);
                //this will hold the first line with all the categories
                fgets(line,500,fp);

                int commoncounter=0;
                int t=0;
                //checks that we have the correct ammount of categories
                while(t<strlen(line))
                {
                        if(line[t] == ',')
                        {
                                commoncounter++;
                        }
                        t++;
                }

                if(commoncounter!=27)
                {
                        printf("invalid amount of categories\n");
                        exit(1);
                }
                Records* input= (Records*)malloc(sizeof(Records)*8000);
                //we are gonna find out how many lines the file is
                int amountOflines=0;
                int commas=0;//keep track of the amount of commas in line

                while(!feof(fp))
                {
                        fgets(line,500,fp);
                        amountOflines++;
                }

                rewind(fp);//this rewinds the pointer to the top of the file
                fgets(line,500,fp);//we call fgets to take out the first line with the categories

                int countline=0;//tracks what line we are currently on
                char token [300];//holds the value for the category
                int j=0;//used to iterate through token
                int s=0;//used to interate through the array

                while(countline <amountOflines)
                {
                        int i=0;//used for interating through line
                        fgets(line,500,fp);//gets the next line

                        while(i<strlen(line))
                        {
                                if(line[i]==',')
                                {
                                        commas++;

                                        switch(commas)
                                        {
                                        case 1://this inputs the color token
                                                strncpy(input[s].color, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 2://inputs director_name token
                                                strncpy(input[s].director_name, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 3:
                                                input[s].num_critic_for_reviews=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 4:
                                                input[s].duration=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 5:
                                                input[s].director_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 6:
                                                input[s].actor_3_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 7:
                                                strncpy(input[s].actor_2_name, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 8:
                                                input[s].actor_1_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 9:
                                                input[s].gross=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 10:
                                                strncpy(input[s].genres, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 11:
                                                strncpy(input[s].actor_1_name, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 12:
                                                while(!isdigit(line[i+1])) {
                                                        if(line[i]== ',')
                                                        {
                                                                token[j]=' ';
                                                        }
                                                        else if(line[i]== '"')
                                                        {
                                                                token[j]=' ';
                                                        }
                                                        else
                                                        {
                                                                token[j]=line[i];
                                                        }
                                                        j++;
                                                        i++;
                                                }
                                                strncpy(input[s].movie_title, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 13:
                                                input[s].num_voted_users=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 14:
                                                input[s].cast_total_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 15:
                                                strncpy(input[s].actor_3_name, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 16:
                                                input[s].facenumber_in_poster=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 17:
                                                strncpy(input[s].plot_keywords, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 18:
                                                strncpy(input[s].movie_imdb_link, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is imbd link %s\n",input[s].movie_imdb_link);
                                                break;

                                        case 19:
                                                input[s].num_user_for_reviews=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is num user for review %i\n",input[s].num_user_for_reviews);
                                                break;

                                        case 20:
                                                strncpy(input[s].language, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is language %s\n",input[s].language);
                                                break;

                                        case 21:
                                                strncpy(input[s].country, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is language %s\n",input[s].country);
                                                break;

                                        case 22:
                                                strncpy(input[s].content_rating, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is content rating %s\n",input[s].content_rating);
                                                break;

                                        case 23:
                                                input[s].budget=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is budget %i\n",input[s].budget);
                                                break;

                                        case 24:
                                                input[s].title_year=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is title year %i\n",input[s].title_year);
                                                break;

                                        case 25:
                                                input[s].actor_2_facebook_likes=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is actor 2 facebook likes %i\n",input[s].actor_2_facebook_likes);
                                                break;

                                        case 26:
                                                input[s].imdb_score=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is imdb %i\n",input[s].imdb_score);
                                                break;

                                        case 27:
                                                input[s].aspect_ratio=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is aspect ratio %i\n",input[s].aspect_ratio);
                                                break;
                                        }
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
                                           line[i]=='1'||line[i]=='2'||line[i]=='3'||line[i]=='4'||line[i]=='5'||line[i]=='6'||line[i]=='7'||line[i]=='8'||line[i]=='9'||line[i]=='0')
                                        {

                                                token[j]=line[i];
                                                j++;
                                        }
                                        i++;
                                }
                        }
                        countline++;
                        s++;
                }
        }
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
                && strcmp(sortColumn, "movie_facebook_likes")!= 0) {
                return 'f';
        }
        return 't';
}

char* isValidParameter(int argc, char* argv[]){
        int i;
        char* sortColumn = "z";
        for(i=0; i<sizeof(argv); i++) {
                if(argv[i]!= NULL) {
                        //check if -c is present (mandatory)
                        if(strcmp("-c", argv[i]) == 0) {
                                //next item in argv is going to be the column to sort
                                //so check if sortColumn is a valid column to sort on
                                sortColumn = argv[i+1];
                                if(isValidColumn(sortColumn) == 'f') {
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
        for(i=0; i<strlen(newPath); i++) {
                if(newPath[i] == 's' && newPath[i+1] == 'o' && newPath[i+2] == 'r' && newPath[i+3] == 't'
                   && newPath[i+4] == 'e' && newPath[i+5] == 'd') {
                        printf("THIS FILE IS ALREADY SORTED\n");
                        return 't';
                }
        }
        return 'f';
}

void printDirInfo(char *directory, char * param) {
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
                        if(Path[len-1]=='v'&&Path[len-2]=='s'&&Path[len-3]=='c') {
                                if(isAlreadySorted(Path) == 'f') {
                                        //Enable multithreading here
                                        parser(Path, object->d_name,param);
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
                        printDirInfo(Path,param);
                        free(Path);
                }
        }
        closedir(current);
        return;
}

int main(int argc, char * argv[]) {
        if(argc < 3) {
                printf("invalid parameters\n");
                exit(1);
        }
        if(argc>7) {
                printf("invalid parameters\n");
                exit(1);
        }

        char* sortedColumn;
        //finds out what to sort on and if the parameter is valid
        sortedColumn = isValidParameter(argc, argv);

        char* startingDirectory = ".";
        char* outputDirectory;


        //determine if starting and output directories present
        int i;
        for(i=0; i<sizeof(argv); i++) {
                if(argv[i]!=NULL) {
                        //check if -d is present (optional)
                        if(strcmp("-d", argv[i]) == 0) {
                                startingDirectory = argv[i+1];
                        }
                        //check if -o is present (optional)
                        if(strcmp("-o", argv[i]) == 0) {
                                outputDirectory = argv[i+1];
                        }
                }
        }

        printDirInfo(startingDirectory,sortedColumn);

        return 0;
}

#include "sorter.h"

char* sortedColumn;
char* sortedColumnType;

typedef struct parserVari {

        char csvfilePath[500];
        char csvfilename[500];
        char pathWocsv[500];
        char sortedColumn[500]
}parserVari;

pthread_t * ts;//threads
parserVari*structs;  //structs
int ts_index=0;
int ts_limit = 1045;

Records* input;
int amount_of_data=0;
int target =6000;
int a;//used to interate through the array

void merge(Records** arr, int l, int m, int r){
        int i,j,k;
        int n1 = m-l+1;
        int n2 = r-m;

        Records* L = (Records*) malloc(sizeof(Records)*n1);
        Records* R = (Records*) malloc(sizeof(Records)*n2);

        for(i=0; i<n1; i++) {
                L[i] = (*arr)[l+i];
        }
        for(i=0; i<n2; i++) {
                R[i] = (*arr)[m+1+i];
        }

        i=0; //index of L
        j=0; //index of R
        k=l; //index of merged

        //Compare between int, double, char*
        if(strcmp(sortedColumnType, "int")== 0 || strcmp(sortedColumnType, "double")==0) {
                if (strcmp(sortedColumn, "duration") == 0) {
                        // printf("duration");
                        while (i < n1 && j < n2) {
                                if (L[i].duration <= R[j].duration) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "num_critic_for_reviews") == 0) {
                        printf("num_crtis");
                        while (i < n1 && j < n2) {
                                if (L[i].num_critic_for_reviews <= R[j].num_critic_for_reviews) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "director_facebook_likes") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].director_facebook_likes <= R[j].director_facebook_likes) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "actor_3_facebook_likes") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].actor_3_facebook_likes <= R[j].actor_3_facebook_likes) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "actor_1_facebook_likes") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].actor_1_facebook_likes <= R[j].actor_1_facebook_likes) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "gross") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].gross <= R[j].gross) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "num_voted_users") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].num_voted_users <= R[j].num_voted_users) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "cast_total_facebook_likes") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].cast_total_facebook_likes <= R[j].cast_total_facebook_likes) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "facenumber_in_poster") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].facenumber_in_poster <= R[j].facenumber_in_poster) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "num_user_for_reviews") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].num_user_for_reviews <= R[j].num_user_for_reviews) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "budget") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].budget <= R[j].budget) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "title_year") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].title_year <= R[j].title_year) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "actor_2_facebook_likes") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].actor_2_facebook_likes <= R[j].actor_2_facebook_likes) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "imdb_score") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].imdb_score <= R[j].imdb_score) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "aspect_ratio") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].aspect_ratio <= R[j].aspect_ratio) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "movie_facebook_likes") == 0) {
                        while (i < n1 && j < n2) {
                                if (L[i].movie_facebook_likes <= R[j].movie_facebook_likes) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }
        }
        if (strcmp(sortedColumnType, "string") == 0) {
                if (strcmp(sortedColumn, "color") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].color, R[j].color) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "director_name") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].director_name, R[j].director_name) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "actor_2_name") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].actor_2_name, R[j].actor_2_name) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "genres") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].genres, R[j].genres) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "actor_1_name") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].actor_1_name, R[j].actor_1_name) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "movie_title") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].movie_title, R[j].movie_title) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "actor_3_name") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].actor_3_name, R[j].actor_3_name) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "plot_keywords") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].plot_keywords, R[j].plot_keywords) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "movie_imdb_link") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].movie_imdb_link, R[j].movie_imdb_link) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "language") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].language, R[j].language) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "country") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].country, R[j].country) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

                if (strcmp(sortedColumn, "content_rating") == 0) {

                        while (i < n1 && j < n2) {

                                if (strcmp(L[i].content_rating, R[j].content_rating) <= 0) {
                                        ( *arr)[k] = L[i];
                                        i++;
                                } else {
                                        ( *arr)[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                        while (i < n1) {
                                ( *arr)[k] = L[i];
                                i++;
                                k++;
                        }

                        while (j < n2) {
                                ( *arr)[k] = R[j];
                                j++;
                                k++;
                        }

                }

        }
}

void mergeSort(Records** input, int l, int r){
        if(l<r) {
                int m = l+(r-l)/2;
                mergeSort(input, l, m);
                mergeSort(input, m + 1, r);
                merge(input, l, m, r);
        }
}

void printRecord(Records* input, int s){

        int arraySize = s;
        int t=0;
        for(t=0; t<arraySize; t++) {
                //  printf("%s ", input[t].color);
                printf("%s \n", input[t].director_name);
        }

}
void print_csv_file(Records** finalInput,int arraySize, char*param){
        char *token="AllFiles-sorted-";

        char* filename = (char*)malloc(sizeof(char*)*100);
        strcpy(filename, token);
        strcat(filename, param);
        strcat(filename, ".csv");
        //printf("this is file name %s\n",filename);
        int i=0;
        FILE *file = fopen(filename, "w");

        i=0;
        while(i!=arraySize) {
                fprintf(file, "%s,", (*finalInput)[i].color);
                fprintf(file, "%s,", (*finalInput)[i].director_name);
                fprintf(file, "%d,", (*finalInput)[i].num_critic_for_reviews);
                fprintf(file, "%d,", (*finalInput)[i].duration);
                fprintf(file, "%d,", (*finalInput)[i].director_facebook_likes);
                fprintf(file, "%d,", (*finalInput)[i].actor_3_facebook_likes);
                fprintf(file, "%s,", (*finalInput)[i].actor_2_name);
                fprintf(file, "%d,", (*finalInput)[i].actor_1_facebook_likes);
                fprintf(file, "%d,", (*finalInput)[i].gross);
                fprintf(file, "%s,", (*finalInput)[i].genres);
                fprintf(file, "%s,", (*finalInput)[i].actor_1_name);
                fprintf(file, "%s,", (*finalInput)[i].movie_title);
                fprintf(file, "%d,", (*finalInput)[i].num_voted_users);
                fprintf(file, "%d,", (*finalInput)[i].cast_total_facebook_likes);
                fprintf(file, "%s,", (*finalInput)[i].actor_3_name);
                fprintf(file, "%d,", (*finalInput)[i].facenumber_in_poster);
                fprintf(file, "%s,", (*finalInput)[i].plot_keywords);
                fprintf(file, "%s,", (*finalInput)[i].movie_imdb_link);
                fprintf(file, "%d,", (*finalInput)[i].num_user_for_reviews);
                fprintf(file, "%s,", (*finalInput)[i].language);
                fprintf(file, "%s,", (*finalInput)[i].country);
                fprintf(file, "%s,", (*finalInput)[i].content_rating);
                fprintf(file, "%d,", (*finalInput)[i].budget);
                fprintf(file, "%d,", (*finalInput)[i].title_year);
                fprintf(file, "%d,", (*finalInput)[i].actor_2_facebook_likes);
                fprintf(file, "%d,", (*finalInput)[i].imdb_score);
                fprintf(file, "%d,", (*finalInput)[i].aspect_ratio);
                fprintf(file, "%d\n", (*finalInput)[i].movie_facebook_likes);
                i++;
        }
        free(filename);
        //free(modifiedOriginalFilename);
        fclose(file);
}
void parser(char* csvFilePath, char* csvFilename, char* pathWOcsv){
        //printf("Checking: %s \n", csvFilename);

        char buffer[1024];
        char *line;
        //char *token;
        const char* s = ",";
        //printf("csvFilePath %s\n", csvFilePath);
        FILE *fp  = fopen(csvFilePath, "r");
        if(fp == NULL) {
                printf("error opening CSV %s\n", csvFilename);
                fclose(fp);

        }
        //No error in heading so continue parsing
        else
        {
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
                //printf("this is first line %s",line);

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

                //we are gonna find out how many lines the file is
                int amountOflines=0;
                int commas;//keep track of the amount of commas in line

                while(!feof(fp))
                {
                        fgets(line,500,fp);
                        amountOflines++;
                }

                amountOflines--;
                rewind(fp);//this rewinds the pointer to the top of the file
                fgets(line,500,fp);//we call fgets to take out the first line with the categories

                int countline=0;//tracks what line we are currently on
                char token [300];//holds the value for the category
                int j=0;//used to iterate through token

                int i=0;//used for interating through line
                int length;

                while(countline <amountOflines)
                {
                        fgets(line,500,fp);

                        amount_of_data++;
                        if(amount_of_data ==target) {
                                //target = target *2;
                                //realloc
                                amount_of_data=0;
                                input=(Records*)realloc(input,sizeof(Records)*(2*target));
                        }

                        i=0;
                        commas=0;
                        length=strlen(line);//gets the next line
                        //printf("this is a line %s",line);

                        while(i<length)
                        {

                                if(line[i]==',')
                                {//printf("this is token %s\n",token);
                                        commas++;

                                        switch(commas)
                                        {

                                        case 1://this inputs the color token
                                                strncpy(input[a].color, token, 50);
                                                //printf("s is:%d and token is %s\n",s,token);
                                                //printf("input[s].color: %s\n",input[s].color);
                                                memset(token, 0, 300);//empties token array
                                                //printf("this is token %s\n",token);
                                                break;

                                        case 2://inputs director_name token
                                                strncpy(input[a].director_name, token, 50);
                                                //printf("s is:%d and token is %s\n",s,token);
                                                //printf("input[s].director_name: %s\n",input[s].director_name);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 3:
                                                input[a].num_critic_for_reviews=atoi(token);
                                                //printf("s is:%d and token is %s\n",s,token);
                                                //printf("input[s].numcriticforreviews: %d\n",input[s].num_critic_for_reviews);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 4:
                                                input[a].duration=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 5:
                                                input[a].director_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 6:
                                                input[a].actor_3_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 7:
                                                strncpy(input[a].actor_2_name, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 8:
                                                input[a].actor_1_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 9:
                                                input[a].gross=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 10:
                                                strncpy(input[a].genres, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 11:
                                                strncpy(input[a].actor_1_name, token, 50);
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
                                                strncpy(input[a].movie_title, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 13:
                                                input[a].num_voted_users=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 14:
                                                input[a].cast_total_facebook_likes=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 15:
                                                strncpy(input[a].actor_3_name, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 16:
                                                input[a].facenumber_in_poster=atoi(token);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 17:
                                                strncpy(input[a].plot_keywords, token, 50);
                                                memset(token, 0, 300);//empties token array
                                                break;

                                        case 18:
                                                strncpy(input[a].movie_imdb_link, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is imbd link %s\n",input[s].movie_imdb_link);
                                                break;

                                        case 19:
                                                input[a].num_user_for_reviews=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is num user for review %i\n",input[s].num_user_for_reviews);
                                                break;

                                        case 20:
                                                strncpy(input[a].language, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is language %s\n",input[s].language);
                                                break;

                                        case 21:
                                                strncpy(input[a].country, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is language %s\n",input[s].country);
                                                break;

                                        case 22:
                                                strncpy(input[a].content_rating, token, 50);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is content rating %s\n",input[s].content_rating);
                                                break;

                                        case 23:
                                                input[a].budget=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is budget %i\n",input[s].budget);
                                                break;

                                        case 24:
                                                input[a].title_year=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is title year %i\n",input[s].title_year);
                                                break;

                                        case 25:
                                                input[a].actor_2_facebook_likes=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is actor 2 facebook likes %i\n",input[s].actor_2_facebook_likes);
                                                break;

                                        case 26:
                                                input[a].imdb_score=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is imdb %i\n",input[s].imdb_score);
                                                break;

                                        case 27:
                                                input[a].aspect_ratio=atoi(token);
                                                memset(token, 0, 300); //empties token array
                                                //printf("this is aspect ratio %i\n",input[s].aspect_ratio);
                                                break;
                                        }
                                        j=0;
                                        //i++;



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

                                }
                                i++;
                        }
                        //printf("token is %s\n",token);
                        input[a].movie_facebook_likes=atoi(token);
                        //printf("input[s].moviefacebooklikes %d\n",input[s].movie_facebook_likes);
                        memset(token, 0, 300); //empties token array


                        countline++;
                        a++;
                        j=0;
                }
        }
}
void* thread_func(void* structInfo){
        parserVari *parserInfo = (parserVari*)structInfo;
        char *filepath = (char*)malloc(sizeof(char*)*500);
        char *filename = (char*)malloc(sizeof(char*)*500);;
        char *pathWocsv = (char*)malloc(sizeof(char*)*500);

        strcpy(filepath, parserInfo->csvfilePath);
        strcpy(filename, parserInfo->csvfilename);
        strcpy(pathWocsv, parserInfo->pathWocsv);

        /*printf("parserInfo path: %s\n", parserInfo->csvfilePath);
           printf("parserInfo name: %s\n", parserInfo->csvfilename);
           printf("parserInfo pathWO: %s\n", parserInfo->pathWocsv);

           printf(" **path: %s\n", filepath);
           printf(" **name: %s\n", filename);
           printf(" **pathWO: %s\n", pathWocsv); */

        parser(filepath,filename,pathWocsv);
        pthread_exit(NULL);
        //free(filepath);
        //free(filename);
        //free(pathWocsv);
}
void* thread_directory(void* structDirInfo){
        parserVari *parserInfo = (parserVari*)structDirInfo;
        char *filepath = (char*)malloc(sizeof(char*)*500);
        char *sortedColumn = (char*)malloc(sizeof(char*)*500);

        strcpy(filepath, parserInfo->csvfilePath);
        strcpy(sortedColumn, parserInfo->sortedColumn);

        printf("filepath %s \n", filepath);
        printf("sortedColumn %s\n", sortedColumn);
        printDirInfo(filepath, sortedColumn);
        pthread_exit(NULL);

        //free(filepath);
        //free(sortedColumn);

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

char* findColumnDataType(const char* sortColumn){
        char *data_type = (char*)malloc(sizeof(char)*30);

        if(strcmp(sortColumn, "color") == 0) {
                strncpy(data_type, "int", 10);
                //data_type = 'int';
                return data_type;
        }
        else if(strcmp(sortColumn, "director_name")==0) {
                strncpy(data_type, "string", 10);
                //printf("value after director_name %s\n", value);
                return data_type;
        }
        else if(strcmp(sortColumn, "num_critic_for_reviews") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "duration") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "director_facebook_likes") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "actor_3_facebook_likes") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "actor_2_name") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "actor_1_facebook_likes") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "gross") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "genres") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "actor_1_name") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "movie_title") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "num_voted_users") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "cast_total_facebook_likes") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "actor_3_name") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "facenumber_in_poster") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "plot_keywords") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "movie_imdb_link") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "num_user_for_reviews") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "language") == 0) {
                strncpy(data_type, "string", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "content_rating") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "budget") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "title_year") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "actor_2_facebook_likes") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "imdb_score") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "aspect_ratio") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else if(strcmp(sortColumn, "movie_facebook_likes") == 0) {
                strncpy(data_type, "int", 10);
                return data_type;
        }
        else{
                printf("WRONG INPUT_ABORT\n");
                strncpy(data_type, "invalid", 10);
                exit(1);
        }

}

char* isValidsortedColumneter(int argc, char* argv[]){
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
                                        printf("invalid sortedColumneters\n");
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
                        //printf("Already Sorted %s\n", newPath);
                        return 't';
                }
        }
        return 'f';
}

void printDirInfo(char *directory, char * sortedColumn) {
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
                        char* pathWOcsv = Path;
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
                                        parserVari temp;
                                        strcpy(temp.csvfilePath,Path);
                                        strcpy(temp.csvfilename,object->d_name);
                                        strcpy(temp.pathWocsv,pathWOcsv);
                                        structs[ts_index] = temp;
                                        pthread_create(&ts[ts_index], NULL, thread_func, &structs[ts_index]);
                                        ts_index +=1;
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
                        //printDirInfo(Path,sortedColumn);
                        parserVari temp2;
                        strcpy(temp2.csvfilePath,Path);
                        strcpy(temp2.sortedColumn,sortedColumn);
                        structs[ts_index]=temp2;
                        pthread_create(&ts[ts_index], NULL, thread_directory,&structs[ts_index]);
                        ts_index+=1;
                        free(Path);
                }
        }
        closedir(current);
        return;
}

int main(int argc, char * argv[]) {
        if(argc < 3) {
                printf("invalid sortedColumneters\n");
                exit(1);
        }
        if(argc>7) {
                printf("invalid sortedColumneters\n");
                exit(1);
        }

        //finds out what to sort on and if the sortedColumneter is valid
        sortedColumn = isValidsortedColumneter(argc, argv);
        sortedColumnType = findColumnDataType(sortedColumn);

        char* startingDirectory = ".";
        char* outputDirectory;

        //determine if starting and output directories present
        int i;
        a=0;
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
        input= (Records*)malloc(sizeof(Records)*8000);
        ts = (pthread_t *)malloc(sizeof(pthread_t)*8000);
        structs = (struct parserVari * ) malloc (sizeof(parserVari)*8000);
        i=0;
        printDirInfo(startingDirectory,sortedColumn);
        for(i=0; i<ts_index; i++) {
                pthread_join(ts[i],NULL);
        }
        mergeSort(&input, 0, a-1);
        print_csv_file(&input, a,sortedColumn);



        return 0;
}

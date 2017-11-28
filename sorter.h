#ifndef sorter_h
#define sorter_h
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include<stdbool.h>
#include <sys/types.h>


typedef struct Records{
char color[50];
char director_name[50];
int num_critic_for_reviews;
int duration;
int director_facebook_likes;
int actor_3_facebook_likes;
char actor_2_name[50];
int actor_1_facebook_likes;
int gross;
char genres[100];
char actor_1_name[50];
char movie_title[100];
int num_voted_users;
int cast_total_facebook_likes;
char actor_3_name[50];
int facenumber_in_poster;
char plot_keywords[100];
char movie_imdb_link[50];
int num_user_for_reviews;21
char language[50];
char country[100];
char content_rating[50];
int budget;
int title_year;
int actor_2_facebook_likes;
int imdb_score;
int aspect_ratio;
int movie_facebook_likes;

}Records;

#endif /*sorter_h*/

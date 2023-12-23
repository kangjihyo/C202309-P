void movie_theater();
void select_movie(char** time_movie);
void select_movie_time(char** time_movie, int want_time, char* select_time);
void shopping();
typedef struct Korean_Food_price {
	char food_name[3][10];
	int food_price[3];
}Kfood_price;

typedef struct Japanese_Food_price {
	char food_name[3][10];
	int food_price[3];
}Jfood_price;

typedef struct Chinese_Food_price {
	char food_name[3][10];
	int food_price[3];
}Cfood_price;
void select_korean_menu(Kfood_price food, int yes_or_no, int food_number);
void select_japanese_menu(Jfood_price food, int yes_or_no, int food_number);
void select_chinese_menu(Cfood_price food, int yes_or_no, int food_number);
void cafeteria();
typedef struct exercise_kind {
	char type[3][10];
	char exercise_place[3][10];
	char* place[3];
}Exerkind;
void initialize(Exerkind* exercise_kind);
void exercise();
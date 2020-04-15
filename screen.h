// Usually in header file, following info is included
// 1. function declarations
// 2. constant definitions
// 3. conditional compilations

// constand definitions
#define ESC 0x1B

#define UNICODE		// for conditional compilation
#define BAR "\u2590"
//#define BLACK 30	insted of using #define, it's better to use ennumeration
enum FG{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE}; 
#define bg(c) (c+10)	// macro definition

#define DEBUG 			// for conditional compilation
typedef struct{			// this struct will define compound data,
	int row;			//	which consists of the nomber of rows and
	int col;			//	the number of columns of our screen
}Position;

// function declarations
void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolor(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawrect(int, int, int, int);
Position getscreensize(void);

#ifndef __MY_ERROR_H_


#define FG_BLACK     "\033[30m"
#define FG_RED       "\033[31m"
#define FG_GREEN     "\033[32m"
#define FG_YELLOW    "\033[33m"
#define FG_BLUE      "\033[34m"
#define FG_VIOLET    "\033[35m"
#define FG_DARKGREE  "\033[36m"
#define FG_WHITE     "\033[37m"

#define BG_BLACK     "\033[40m"
#define BG_RED       "\033[41m"
#define BG_GREEN     "\033[42m"
#define BG_YELLOW    "\033[43m"
#define BG_BLUE      "\033[44m"
#define BG_VIOLET    "\033[45m"
#define BG_DARKGREE  "\033[46m"
#define BG_WHITE     "\033[47m"

#define NONE         "\033[0m"

#define MY_INFO(...) do{\
printf(FG_GREEN);\
printf("[%s] [%s]","INFO", __FUNCTION__);\
printf(__VA_ARGS__);\
printf(BG_BLACK);\
printf(NONE);\
}while(0)

#define MY_WARING(...) do{\
printf(FG_YELLOW);\
printf("[%s] [%s]","WARING", __FUNCTION__);\
printf(__VA_ARGS__);\
printf(BG_BLACK);\
printf(NONE);\
}while(0)

#define MY_ERROR(...) do{\
printf(FG_BLUE);\
printf("[%s] [%s]","ERROR", __FUNCTION__);\
printf(__VA_ARGS__);\
printf(BG_BLACK);\
printf(NONE);\
}while(0)

#define MY_BUG(...) do{\
printf(FG_RED);\
printf("[%s] [%s] [%s] [%d]","BUG", __FILE__, __FUNCTION__, __LINE__);\
printf(__VA_ARGS__);\
printf(BG_BLACK);\
printf(NONE);\
while(1);\
}while(0)

#endif //MY_ERROR_H_

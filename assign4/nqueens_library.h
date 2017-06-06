int check_diagonal(int *list, int n);
int generate_n_queens_serial(int n, int print_flag);
int generate_n_queens_serial_one(int n, int out_flag, int first);
int generate_n_queens_serial_one_safe(int n, int out_flag, int first);
void get_array_string(int *list, int n, char *s);
int next_permutation(int *list, int n);
void *queens_thread(void *infopointer);
void *queens_thread_safe(void *infopointer);

typedef struct ti {
   int n;
   int first;
   int out_flag;
   int result;
} thread_info_t;

extern pthread_mutex_t printf_mutex;

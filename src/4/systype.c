#include "systype.h"

#define FAIL 0
#define SUCCESS 1
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12

char *enter_PID_process(int pid) {
	int j = 0, i = 6;
	char *comand = NULL;
	comand = realloc(comand, (i) * sizeof(char));
	comand[0] = 'p';
	comand[1] = 's';
	comand[2] = ' ';
	comand[3] = '-';
 	comand[4] = 'p';
	comand[5] = ' ';
	int *res_arr = NULL;
	while(pid != 0) {
		res_arr = realloc(res_arr, (j) * sizeof(int));
		res_arr[j] = pid % 10;
		pid = pid / 10;
		j++;
	}

	for (int k = j - 1; k >= 0; k--) {
		comand = realloc(comand, (i) * sizeof(char));
		comand[i] = res_arr[k] + '0';
		i++;

	}

	for (int j = 0; j < i; j++) {
		printf("%c\n", comand[j]);
	}

	printf("DDDD %s\n", comand);
	
	return comand;
}

void API_contract() {
	char c;
	int pid = 0, API_flag = 0;
	pid_t pid_1;
	printf("Please, enter a task for the process:\n");
	printf("1) Check all running process\n");
	printf("2) Check all process in directory\n");
	printf("3) Check procces by PID\n");
	printf("4) Generate new process\n");
	printf("5) \n");
	printf("6) \n");
	printf("0) Exit.\n");
	while (1) {
		if (scanf("%d%c", &API_flag, &c) == 2 && (API_flag > -1 && API_flag < 7) && (c == '\n') && (c != EOF)) {
			if (API_flag != 0) {
				printf("\033c");
				switch (API_flag) {
					case 1: 
						printf("All running process:\n");
						system("ps -e");
						break;
					case 2:
						printf("All procces in directory:\n");
						system("ps -T");
						break;
					case 3:
						pid = 1;
						char c2;
						fflush(NULL);
						printf("\033c");
						while (pid == 1 || pid == 2) {
							fflush(NULL);
							printf("Please, enter process PID or: \n");
							printf("1) Check all running process\n");
							printf("2) Check all process in directory\n");
							if (scanf("%d%c", &pid, &c2) == 2 && (pid > 0) && (c2 == '\n') && (c2 != EOF)) {
								printf("%d!\n", pid);
								switch (pid) {
									case 1:
										printf("All running process:\n");
										system("ps -e");
										break;
									case 2:
										printf("All procces in directory:\n");
										system("ps -T");
										break;
									default:
										system(enter_PID_process(pid));
										break;
								}
							} else {
								printf("\033c");
								printf("Invelid input!\n");
								break;
							}
							fflush(NULL);
						}
						break;
					case 4:
						pid_1 = fork();
						printf("Add new process:\n");
						printf("New procces PID is %i\n", pid_1 = (int)getpid());
						break;
					case 5:
						break;
					case 6:
						break;
				}		
				fflush(NULL);
				printf("Please, enter a task for the process:\n");
				printf("1) Check all running process\n");
				printf("2) Check all process in directory\n");
				printf("3) Check procces by PID\n");
				printf("4) Generate new process\n");
				printf("5) \n");
				printf("6) \n");
				printf("0) Exit.\n");
			} else {
				printf("\033c");
				break;
			}
		} else {
			printf("Invalid input!\n");
			break;
		}
	}
}

void processes_initialization() {

}

int main() {
	printf("\033c"); 
	API_contract();

	return 0;
}

#include "systype.h"

#define FAIL 0
#define SUCCESS 1
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12

char *enter_PID_process(char *first, int pid) {
	char tmp;
	char *resault = NULL;
	int i = 0;
	
	resault = realloc(resault, 1 * sizeof(char));
	while(pid != 0) {
		resault = realloc(resault, 1 * sizeof(char));
		tmp = (char) (pid % 10) - '0';
		resault[i] = tmp;
	}

	resault = strcat(first, resault);
	printf("%s\n", resault);
	
	return resault;
}

void API_contract() {
	char c;
	int pid = 0, API_flag = 0;
	printf("Please, enter a task for the process:\n");
	printf("1) Check all running process\n");
	printf("2) Check all process in directory\n");
	printf("3) Check procces by PID\n");
	printf("4) \n");
	printf("5) \n");
	printf("0) Exit.\n");
	while (1) {
		if (scanf("%d%c", &API_flag, &c) == 2 && (API_flag > -1 && API_flag < 7) && (c == '\n')) {
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
						printf("Please, enter process PID: \n");
						if (scanf("%d%c", &pid, &c) == 2 && (API_flag > 0) && (c == '\n')) {
							system(enter_PID_process("ps -p $", pid));
						}
						break;
					case 4:
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
				printf("4) \n");
				printf("5) \n");
				printf("0) Exit.\n");
			} else {
				printf("\033c");
				break;
			}
		} else {
			printf("Invalid input!\n");
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

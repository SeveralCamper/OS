#include "systype.h"

#define FAIL 0
#define SUCCESS 1
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12

char *enter_PID_process(int pid, int string_length, char *string) {
	int j = 0, i = string_length;
	char *command = NULL;
	command = realloc(command, (i) * sizeof(char));
	strcpy(command, string);
	int *res_arr = NULL;
	while(pid != 0) {
		res_arr = realloc(res_arr, (j) * sizeof(int));
		res_arr[j] = pid % 10;
		pid = pid / 10;
		j++;
	}

	for (int k = j - 1; k >= 0; k--) {
		command = realloc(command, (i) * sizeof(char));
		command[i] = res_arr[k] + '0';
		i++;
	}

	for (int i = 0; i < string_length + 4; i++) {
		printf("%c", command[i]);
	}
	printf("\n");
	
	return command;
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
	printf("5) Show process tree with PID\n");
	printf("6) Delete process by PID\n");
	printf("0) Exit.\n");
	while (1) {
		if (scanf("%d%c", &API_flag, &c) == 2 && (API_flag > -1 && API_flag < 7) && (c == '\n') && (c != EOF)) {
			if (API_flag != 0) {
				printf("\033c");
				switch (API_flag) {
					case 1: 
						printf("All running process:\n");
						system("ps -e");
						fflush(NULL);
						break;
					case 2:
						printf("All procces in directory:\n");
						system("ps -T");
						fflush(NULL);
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
							printf("3) Check process by pid\n");
							if (scanf("%d%c", &pid, &c2) == 2 && (pid > 0) && (c2 == '\n') && (c2 != EOF)) {
								switch (pid) {
									case 1:
										printf("All running process:\n");
										system("ps -e");
										break;
									case 2:
										printf("All procces in directory:\n");
										system("ps -T");
										break;
									case 3:
										printf("Check process by pid:\n");
										printf("Enter process PID: ");
										int PID = 0;
										if (scanf("%d%c", &PID, &c2) == 2 && (PID > 0) && (c2 == '\n') && (c2 != EOF)) {
											char *command = "ps -p ";
											system(enter_PID_process(PID, 6, command));
										}
										break;
									default:
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
						fflush(NULL);
						break;
					case 5:
						printf("Procces tree:\n");
						system("pstree -p");
						fflush(NULL);
						break;
					case 6:
						printf("Delete Process by PID:\n");
						printf("Enter process PID: ");
						int PID = 0;
						if (scanf("%d%c", &PID, &c2) == 2 && (PID > 0) && (c2 == '\n') && (c2 != EOF)) {
							char *command = "kill ";
							system(enter_PID_process(PID, 5, command));
						}
						fflush(NULL);
						break;
					case 0:
						API_flag = 0;
						break;
				}		
				fflush(NULL);
				printf("Please, enter a task for the process:\n");
				printf("1) Check all running process\n");
				printf("2) Check all process in directory\n");
				printf("3) Check procces by PID\n");
				printf("4) Generate new process\n");
				printf("5) Show process tree with PID\n");
				printf("6) Delete process by PID\n");
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

int main() {
	printf("\033c"); 
	API_contract();

	return 0;
}

#include "systype.h"

#define FAIL 0
#define SUCCESS 1
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12

void API_contract() {
	printf("\033c");
	char API_flag;
	printf("Please, enter a task for the process:\n");
	printf("1) Check all running process\n");
	printf("2) \n");
	printf("3) \n");
	printf("4) \n");
	printf("5) \n");
	printf("0) Exit.\n");
	API_flag = getchar();
	while (API_flag != '0') {
		switch (API_flag) {
			case '1': 
				system("ps -e");
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
			case '6':
				break;
			case '0':
				break;
		}
		printf("Please, enter a task for the process:\n");
		printf("1) Check all running process\n");
		printf("2) \n");
		printf("3) \n");
		printf("4) \n");
		printf("5) \n");
		printf("0) Exit.\n");
		API_flag = getchar();
	}
}

void processes_initialization() {

}

int main() {
	API_contract();

	return 0;
}

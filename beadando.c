#include <stdio.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define KEYA 13254
#define KEYB 52431

struct sembuf up[1] = {0, 1, SEM_UNDO};
struct sembuf down[1] = {0, -1, SEM_UNDO};

int main() {

	int semida = semget(KEYA, 1, IPC_CREAT | 00666);
	semctl(semida, 0, SETVAL, 1);

	int semidb = semget (KEYB, 1, IPC_CREAT | 00666);
	semctl(semidb, 0, SETVAL, 1);

	printf("Belépnék:  A\n");
		semop(semida, down, 1);
	printf("Bent vagyok:   A\n");
	sleep(3);
	printf("Végeztem:  A\n");
	printf("Belépnék:  B\n");
semop(semidb, down, 1);
	printf("Bent vagyok:   B\n");
	printf("Kilépnék:  A\n");
		semop(semida, up, 1);
	printf("Kint vagyok:   A\n");
	printf("Indulok:   B\n");
	sleep(3);
	printf("Kilépnék:  B\n");
semop(semidb, up, 1);
	printf("Kint vagyok:   B\n");

	return 0;
}

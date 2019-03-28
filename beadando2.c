#include <stdio.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define KEYB 13254
#define KEYA 52431

struct sembuf up[1] = {0, 1, SEM_UNDO};
struct sembuf down[1] = {0, -1, SEM_UNDO};

int main() {

	int semida = semget(KEYA, 1, IPC_CREAT | 00666);
	int semidb = semget (KEYB, 1, IPC_CREAT | 00666);

	printf("Belépnék:  B\n");
		semop(semida, down, 1);
	printf("Bent vagyok:   B\n");
	sleep(3);
	printf("Végeztem:  B\n");
	printf("Belépnék:  A\n");
semop(semidb, down, 1);
	printf("Bent vagyok:   A\n");
	printf("Kilépnék:  B\n");
		semop(semida, up, 1);
	printf("Kint vagyok:   B\n");
	printf("Indulok:   A\n");
	sleep(3);
	printf("Kilépnék:  A\n");
semop(semidb, up, 1);
	printf("Kint vagyok:   A\n");

	semctl(semida, 0, IPC_RMID);
	semctl(semidb, 0, IPC_RMID);

	return 0;
}

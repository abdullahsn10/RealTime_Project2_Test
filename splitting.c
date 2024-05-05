#include "header.h"
#include "functions.h" 
#include "constants.h"
#include "simulationfuncs.h"
#include "comittees.h"


struct SPLITTING our_comm;

int main(int argc, char **argv){
    if(argc != 3){
        perror("our_comm Arguments Error\n");
        exit(10);
    }

    our_comm.committee_id = atoi(argv[1]);
    our_comm.number_of_workers = atoi(argv[2]);
    // creating array of workers
    our_comm.workers = (struct WORKER *) malloc(our_comm.number_of_workers * sizeof(struct WORKER));

        // Print the values
    printf("Sp Committee ID: %d\n", our_comm.committee_id);
    printf("Sp Number of Workers: %d\n", our_comm.number_of_workers);

      // for to add energy to workers
    for (int i=0;i<our_comm.number_of_workers;i++){
        our_comm.workers[i].energy=get_random_number_in_range(getpid(),50,100);
        printf("Sp worker %d with energy: %d\n",i+1,our_comm.workers[i].energy);
    }
    exit(0);


}
#include "header.h"
#include "functions.h" 
#include "constants.h"
#include "simulationfuncs.h"

int main(){
    // get all values 
    read_settings_from_a_file("settings.txt");
    
    // required values for planes
    pid_t pid;
    pid_t planes[NUMBER_OF_CARGO_PLANES];

    // creating planes
    for(int i=0; i<NUMBER_OF_CARGO_PLANES; i++){
        if((pid = fork()) == -1){
            perror("Fork Error\n");
            exit(1);
        } else if(pid == 0){
            // child - plane
            char plane_id[20], number_of_containers[20], drop_time[20], refill_period_time[20];
            // fill values to be passed
            sprintf(number_of_containers, "%d", get_random_number_in_range(getpid(), 
            MIN_FLOUR_CONTAINERS, MAX_FLOUR_CONTAINERS));

            sprintf(drop_time, "%d", get_random_number_in_range(getpid(), 
            MIN_DROP_TIME, MAX_DROP_TIME));

            sprintf(refill_period_time, "%d", get_random_number_in_range(getpid(), 
            REFILL_PERIOD_MIN, REFILL_PERIOD_MAX));

            sprintf(plane_id, "%d", (i+1));
            // exec plane file and passing arguments
            execlp("./plane", "plane", plane_id, number_of_containers ,
            drop_time, refill_period_time, NULL);

            // will not reach here if success exec
            perror("EXEC ERROR\n");
            exit(5);


        } else{
            // parent

            // save planes id
            planes[i] = pid;
        }
    }

    // required values for creating committees
    pid_t collecting_committees[COLLECTING_RELIEF_COMMITTEES],
    splitting_committees[SPLITTING_RELIEF_COMMITTEES],
    distributing_committees[DISTRIBUTING_RELIEF_COMMITTEES];

    
    for(int i=0; i<COLLECTING_RELIEF_COMMITTEES; i++){
        if((pid = fork()) == -1){
            perror("Fork Error\n");
            exit(1);
        } else if(pid == 0){
            // child - collecting committee
            // required values
            char number_of_workers[20], collecting_com_id[20];
            sprintf(number_of_workers, "%d", COLLECTING_RELIEF_WORKERS);
            sprintf(collecting_com_id, "%d", (i+1));

            execlp("./collecting", "collecting", collecting_com_id, number_of_workers,
            NULL);

            // will not reach here if success exec
            perror("EXEC ERROR\n");
            exit(6);

        } else{
            // parent

            // save planes id
            collecting_committees[i] = pid;
        }
    }

    for(int i=0; i<SPLITTING_RELIEF_COMMITTEES; i++){
        if((pid = fork()) == -1){
            perror("Fork Error\n");
            exit(1);
        } else if(pid == 0){
            // child - splitting
            // required values
            char number_of_workers[20], splitting_com_id[20];
            sprintf(number_of_workers, "%d", SPLITTING_RELIEF_WORKERS);
            sprintf(splitting_com_id, "%d", (i+1));

            execlp("./splitting", "splitting", splitting_com_id, number_of_workers,
            NULL);
            // will not reach here if success exec
            perror("EXEC ERROR\n");
            exit(5);


        } else{
            // parent
            splitting_committees[i] = pid;
        }
    }

    for(int i=0; i<DISTRIBUTING_RELIEF_COMMITTEES; i++){
        if((pid = fork()) == -1){
            perror("Fork Error\n");
            exit(1);
        } else if(pid == 0){
            // child - dist com
            // required values
            char number_of_workers[20], distributing_com_id[20];
            sprintf(number_of_workers, "%d", DISTRIBUTING_RELIEF_WORKERS);
            sprintf(distributing_com_id, "%d", (i+1));

            execlp("./distributing", "distributing", distributing_com_id, number_of_workers,
            NULL);
            
            // will not reach here if success exec
            perror("EXEC ERROR\n");
            exit(5);


        } else{
            // parent

            // save planes id
            distributing_committees[i] = pid;
        }
    }
 
    sleep(5);
    exit(0);

}

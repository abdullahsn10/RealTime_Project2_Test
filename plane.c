#include "header.h"
#include "functions.h" 
#include "constants.h"
#include "simulationfuncs.h"
#include "plane.h"


struct PLANE plane;

int main(int argc, char **argv){
    if(argc != 5){
        perror("Plane Arguments Error\n");
        exit(10);
    }

    plane.my_id = atoi(argv[1]);
    plane.number_of_containers = atoi(argv[2]);
    plane.drop_time = atoi(argv[3]);
    plane.refill_period = atoi(argv[4]);

    
    exit(0);


}
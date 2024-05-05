#ifndef __COLLECT_H_
#define  __COLLECT_H_

struct WORKER{
    int energy;
}worker;

struct COLLECTING
{
    int committee_id;
    int number_of_workers;
    struct WORKER *workers;
}collecting;

struct SPLITTING
{
    int committee_id;
    int number_of_workers;
    struct WORKER *workers;
}splitting;

struct DISTRIBUTING{
    int committee_id;
    int number_of_workers;
    struct WORKER *workers;
}distributing;



#endif

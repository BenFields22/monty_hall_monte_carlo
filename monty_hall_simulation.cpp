#include <iostream>
#include <stdlib.h>     
#include <time.h> 

int main(int argc, char** argv){
    srand (time(NULL));
    int num_experiments = 100000000;
    int num_times_in_other_door = 0;
    for(int i = 0;i<num_experiments;i++){
        int r1 = rand() % 100 + 1;
        int slot;
        int guess;
        if(r1>66){
            slot=3;
        }
        else if(r1>33&&r1<=66){
            slot=2;
        }
        else{
            slot=1;
        }
        int contestant_guess = rand() % 100 + 1;
        if(contestant_guess>66){
            guess=3;
        }
        else if(contestant_guess>33&&contestant_guess<=66){
            guess=2;
        }
        else{
            guess=1;
        }

        if(slot==1&&guess==1){
            continue;
        }
        else if(slot==1&&guess==2){
            num_times_in_other_door++;
        }
        else if(slot==1&&guess==3){
            num_times_in_other_door++;
        }
        else if(slot==2&&guess==2){
            continue;
        }
        else if(slot==2&&guess==1){
            num_times_in_other_door++;
        }
        else if(slot==2&&guess==3){
            num_times_in_other_door++;
        }
        else if(slot==3&&guess==3){
            continue;
        }
        else if(slot==3&&guess==1){
            num_times_in_other_door++;
        }
        else if(slot==3&&guess==2){
            num_times_in_other_door++;
        }
    }
    float percentage = ((float)num_times_in_other_door/(float)num_experiments)*100.0;
    std::cout<<"Contestant would win "<<percentage<< " percent of the time if always switching to the other door."<<std::endl;
    return 0;
}

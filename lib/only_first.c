#include <packages.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct package * comparison(struct package * first, struct package * second){
    struct package * ret_list = (struct package *)malloc(sizeof(struct package));
    struct package * step_ret_list = ret_list;
    struct package * first_list = first;
    struct package * second_list;
    int count = 0;
    while(first_list != NULL){
	second_list = second;
        uint8_t is_find = 0;
	while(second_list != NULL){
		printf("%d iteration\r", ++count);
		if(strcmp(first_list->name, second_list->name) == 0){
                    is_find = 1;
		    break;
                }
		second_list = second_list->next;
	}
            if(is_find == 0){
                all_branch_count++;
		strcpy(step_ret_list->name, first_list->name);
                //step_ret_list->epoch = first->epoch;
                strcpy(step_ret_list->version, first_list->version);
                strcpy(step_ret_list->release, first_list->release);
                //strcpy(step_ret_list->arch, first->arch);
                //strcpy(step_ret_list->disttag, first->disttag);
                //step_ret_list->buildtime = first->buildtime;
                //strcpy(step_ret_list->source, first->source);
		step_ret_list->next = (struct package *)malloc(sizeof(struct package));
                step_ret_list = step_ret_list->next;
           
	}
	first_list = first_list->next;
    }
    printf("\n");
    return ret_list;
}

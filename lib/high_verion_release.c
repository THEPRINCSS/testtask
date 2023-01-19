#include <packages.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct package *
high(struct package *first, struct package *second){
	struct package * ret_list = (struct package*)malloc(sizeof(struct package));
	struct package * ret_step_list = ret_list;
	struct package * first_list = first;
	struct package * second_list;
	int count = 0;
	while(first_list != NULL){
		second_list = second;
		while(second_list != NULL){
			//printf("%d iteration\r", ++count);
			if(strcmp(first_list->name, second_list->name) == 0){
				if(strcmp(first_list->version, second_list->version) > 0 && strcmp(first_list->release, second_list->release) > 0){
					all_branch_count++;	
					strcpy(ret_step_list->name, first_list->name);
					//ret_step_list->epoch = first_list->epoch;
					strcpy(ret_step_list->version, first_list->version);
					strcpy(ret_step_list->release, first_list->release);
					//strcpy(ret_step_list->arch, first_list->arch);
					//strcpy(ret_step_list->disttag, first_list->disttag);
					//ret_step_list->buildtime = first_list->buildtime;
					//strcpy(ret_step_list->source, first_list->source);
					ret_step_list->next = (struct package *)malloc(sizeof(struct package));
					ret_step_list = ret_step_list->next;
					break;
				}
			}
			second_list = second_list->next;
		}
		first_list = first_list->next;
	}
	return ret_list;
}

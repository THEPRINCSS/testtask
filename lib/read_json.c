#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <packages.h>
#include <stdint.h>

char *
get_need_data(const char * data){    
	char * ret_char = (char*)malloc(128 * sizeof(char));
    int write_step = 0;
    int i = 0;
    while(data[i] != ':'){
        i++;
    }
    i++;
    for(;i < strlen(data); i++){
        if(data[i] != ' ' && data[i] != '\"'){
            if(data[i] == '}'){
		return ret_char;
	    }
	ret_char[write_step++] = data[i];
        }
    }
    return ret_char;
}


struct package *
read_json(const char *filename){
	struct package * ret_package = (struct package*)malloc(sizeof(struct package));
	struct package * packages_list = ret_package;
	FILE * file_json = fopen(filename, "r");
	if(file_json == NULL){
		perror("file not exist");
		return NULL;
	}
	char *buffer;
	char saved_buffer[2048];
	int start_saved_buffer = 0;
	char c;
	int count = 0;
	while ((c = fgetc(file_json)) != '['){
	}	
	while(!feof(file_json)){
	       
		buffer = NULL;
		c = fgetc(file_json);
		uint8_t is_find = 0;
		saved_buffer[start_saved_buffer++] = c; 
		if(c == '}'){
			if(saved_buffer[0] != ']')
				is_find = 1;
			else
				return ret_package;
		}

		if(is_find){
			count++;
			while(saved_buffer[0] != '{'){
				strcpy(saved_buffer, saved_buffer + 1);
			}
			buffer = strtok(saved_buffer,",");
			if(strstr(buffer, "name")){
				buffer = get_need_data(buffer);
				strcpy(packages_list->name, buffer);
				buffer = strtok(NULL, ",");
			}
			if(strstr(buffer, "epoch")){
				//packages_list->epoch = atoi(get_need_data(buffer));
				buffer = strtok(NULL, ",");
			}
			if(strstr(buffer, "version")){
				strcpy(packages_list->version, get_need_data(buffer));
				buffer = strtok(NULL, ",");
			}
			if(strstr(buffer, "release")){
				strcpy(packages_list->release, get_need_data(buffer));
				buffer = strtok(NULL, ",");
				packages_list->next = (struct package*)malloc(sizeof(struct package));
				packages_list = packages_list->next;
			}
			/*if(strstr(buffer, "arch")){
				strcpy(packages_list->arch, get_need_data(buffer));
				buffer = strtok(NULL, ",");
        		}
        		if(strstr(buffer, "disttag")){
            			strcpy(packages_list->disttag, get_need_data(buffer));
				buffer = strtok(NULL,",");
        		}
        		if(strstr(buffer, "buildtime")){
            			packages_list->buildtime = atoi(get_need_data(buffer));
       				buffer = strtok(NULL, ",");
			}
        		if(strstr(buffer, "source")){
            			strcpy(packages_list->source, get_need_data(buffer));
				packages_list->next = (struct package*)malloc(sizeof(struct package));
				packages_list = packages_list->next;
        		}*/
			start_saved_buffer = 0;
		}
	}
	return ret_package;
}

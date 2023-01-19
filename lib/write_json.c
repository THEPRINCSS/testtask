#include <stdio.h>
#include <stdlib.h>
#include <packages.h>

int
write_json(struct package * first_list,
           struct package * second_list,
           struct package * third_list){
    FILE * result = fopen("~/result.json", "w");
    fputs("{\n", result);
    fprintf(result, "\"length\": %d,",all_branch_count);
    fputs("\"only first\": [\n",result);
    struct package * first = first_list;
    while(first != NULL){
        fprintf(result, "{\n");
        fprintf(result, "\"name\": \"%s\",\n",first->name);
        //fprintf(result, "\"epoch\": %d,\n",first->epoch);
        fprintf(result, "\"version\": \"%s\",\n",first->version);
        fprintf(result, "\"release\": \"%s\",\n",first->release);
        //fprintf(result, "\"arch\": \"%s\",\n",first->arch);
        //fprintf(result, "\"disttag\": \"%s\",\n",first->disttag);
        //fprintf(result, "\"buildtime\": %d,\n",first->buildtime);
        //fprintf(result, "\"source\": \"%s\",\n",first->source);
        fprintf(result, "}");
        first = first->next;
	if(first != NULL){
		fprintf(result,",\n");
	}
    }
    fputs("],\n",result);
    fputs("\"only second\": [\n", result);
    struct package * second = second_list;
    while(second != NULL){
        fprintf(result, "{\n");
        fprintf(result, "\"name\": \"%s\",\n",second->name);
        //fprintf(result, "\"epoch\": %d,\n",second->epoch);
        fprintf(result, "\"version\": \"%s\",\n",second->version);
        fprintf(result, "\"release\": \"%s\",\n",second->release);
        //fprintf(result, "\"arch\": \"%s\",\n",second->arch);
        //fprintf(result, "\"disttag\": \"%s\",\n",second->disttag);
        //fprintf(result, "\"buildtime\": %d,\n",second->buildtime);
        //fprintf(result, "\"source\": \"%s\",\n",second->source);
        fprintf(result, "}");
        second = second->next;
	if(second != NULL)
		fprintf(result,",\n");
    }
    fputs("],\n", result);
    fputs("\"high version-release\": [\n", result);
    struct package * third = third_list;
    while(third != NULL){
        fprintf(result, "{\n");
        fprintf(result, "\"name\": \"%s\",\n",third->name);
        //fprintf(result, "\"epoch\": %d,\n",third->epoch);
        fprintf(result, "\"version\": \"%s\",\n",third->version);
        fprintf(result, "\"release\": \"%s\",\n",third->release);
        //fprintf(result, "\"arch\": \"%s\",\n",third->arch);
        //fprintf(result, "\"disttag\": \"%s\",\n",third->disttag);
        //fprintf(result, "\"buildtime\": %d,\n",third->buildtime);
        //fprintf(result, "\"source\": \"%s\",\n",third->source);
        fprintf(result, "}");
        third = third->next;
	if(third != NULL)
		fprintf(result, ",\n");
    }
    fputs("}", result);
    
}

#include <stdio.h>
#include <lib.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, const char ** argv){
	system("rm p*");
	char first_branch_name[256];
	char second_branch_name[256];
	char arch_type[256];
	printf("Enter arch : ");
	scanf("%256s",arch_type);
		printf("Enter branch name: ");
		scanf("%256s", first_branch_name);
		printf("Enter branch name: ");
		scanf("%256s", second_branch_name);
		printf("Get %s packages list\n", first_branch_name);
		get_branch(first_branch_name,arch_type);
		printf("Get %s packages list\n", second_branch_name);
		get_branch(second_branch_name,arch_type);
		
	printf("Working this %s\n", first_branch_name);
	struct package * first_branch = read_json(first_branch_name);

	/*struct package * first_branch_test = first_branch;
	while(first_branch_test != NULL){
		printf("%s\n",first_branch_test->name);
		first_branch_test = first_branch_test->next;
	}*/
	printf("Working this %s\n", second_branch_name);
	char second_filename[256];
	sprintf(second_filename, "%s",second_branch_name);
	struct package * second_branch = read_json(second_filename);
	
	/*struct package * second_branch_test = second_branch;
	while(second_branch_test != NULL){
		printf("%s\n",second_branch_test->name);
		second_branch_test = second_branch_test->next;
		
	}*/
	printf("Comparison two branch\n");	
	struct package* first_result = comparison(first_branch, second_branch);
	struct package* second_result = comparison(second_branch, first_branch);
	printf("Search high version-release\n");
	struct package* third_result = high(first_branch, second_branch);
	printf("Save result\n");
	write_json(first_result, second_result, third_result);

	return 0;
}

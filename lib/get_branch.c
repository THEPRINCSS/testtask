#include <stdio.h>

char get_json[1024];

void
get_branch(const char * branch_name, const char * arch_type){
	sprintf(get_json, "wget -X 'GET' -q 'https://rdb.altlinux.org/api/export/branch_binary_packages/%s?arch=%s' -O %s ", branch_name, arch_type,branch_name);
	system(get_json);
}

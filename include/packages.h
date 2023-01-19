#ifndef PACKAGES_STRUCT
#define PACKAGES_SRTUCT

struct package{
	char name[128];
	//unsigned int epoch;
	char version[128];
	char release[128];
	/*char arch[128];
	char disttag[128];
	unsigned int buildtime;
	char source[128];*/
	struct package * next;
};

static int all_branch_count = 0;

#endif

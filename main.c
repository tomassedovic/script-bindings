#include <stdio.h>

#include <libguile.h>

static SCM has_entity(SCM entity_id) {
	const int id = scm_to_int(entity_id);
	return scm_from_bool(id > 0 && id < 10);
}

static void* register_functions(void* data) {
	scm_c_define_gsubr("has-entity", 1, 0, 0, &has_entity);
	return NULL;
}


#define MAX_FILE_SIZE 1000000

int main (int argc, char **argv) {
	scm_with_guile(&register_functions, NULL);
	char scheme_program[MAX_FILE_SIZE] = {'\0'};
	FILE *f = fopen("main.scm", "r");
	int c, i;
	for(c = fgetc(f), i = 0; c != EOF && i <= MAX_FILE_SIZE; c = fgetc(f), i++) {
		scheme_program[i] = c;
	}
	scheme_program[i] = '\0';
	fclose(f);
	scm_c_eval_string(scheme_program);
	return 0;
}

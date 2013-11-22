#include <stdio.h>

#include <libguile.h>

static SCM has_entity(SCM entity_id) {
	const int id = scm_to_int(entity_id);
	return scm_from_bool(id > 0 && id < 10);
}

static void* guile_main(void* data) {
	scm_c_define_gsubr("has-entity", 1, 0, 0, &has_entity);

	scm_c_primitive_load(data);
	scm_call_0(scm_variable_ref(scm_c_lookup("foo")));
	scm_call_0(scm_variable_ref(scm_c_lookup("bar")));
	return NULL;
}

int main (int argc, char **argv) {
	if(argc == 2) {
		scm_with_guile(&guile_main, argv[1]);
	} else {
		printf("You must enter the path to the script.");
		return 1;
	}
	return 0;
}

#include <stdio.h>

#include <libguile.h>

static SCM has_entity(SCM entity_id) {
	const int id = scm_to_int(entity_id);
	return scm_from_bool(id > 0 && id < 10);
}

int main (int argc, char **argv) {
	// TODO: scm_with_guile is preferable but doesn't work properly, see below.
	scm_init_guile();
	scm_c_define_gsubr("has-entity", 1, 0, 0, &has_entity);
	scm_c_primitive_load("main.scm");
	// TODO: gauses a stack overflow when used with scm_with_guile instead of scm_init_guile
	scm_call_0(scm_variable_ref(scm_c_lookup("foo")));
	scm_call_0(scm_variable_ref(scm_c_lookup("bar")));
	return 0;
}

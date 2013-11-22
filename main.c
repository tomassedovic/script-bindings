#include <libguile.h>

static SCM has_entity(SCM entity_id) {
    const int id = scm_to_int(entity_id);
    return scm_from_bool(id > 0 && id < 10);
}

static void* register_functions(void* data) {
    scm_c_define_gsubr("has-entity", 1, 0, 0, &has_entity);
    return NULL;
}

int main (int argc, char **argv) {
    scm_with_guile(&register_functions, NULL);
    scm_shell(argc, argv);
    return 0; /* never reached */
}

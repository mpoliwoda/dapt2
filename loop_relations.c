#include "loop_relations.h"
#include "tool_debug.h"

typedef struct relation_info{

} relation_info;


static isl_stat loop_relation_analyse(__isl_take isl_map *map, void *user);

void loop_relatios_analyse(loop_scop * loopScop){
    relation_info relationInfo;
    isl_union_map_foreach_map(loopScop->relations, loop_relation_analyse, &relationInfo);
    return;
}

static isl_stat loop_relation_analyse(__isl_take isl_map *map, void *user){

    isl_debug_printf_map("\n#relation map:\n%s\n", map);

    isl_map_free(map);

    return isl_stat_ok;
}
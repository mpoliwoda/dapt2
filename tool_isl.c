/*
 * tool_isl.c
 *
 *  Created on: Dec 11, 2021
 *
 */

#include <isl/map.h>
#include <isl/union_map.h>
#include "tool_isl.h"

isl_stat clear_tuple_names_in_map(__isl_take isl_map *map, void *user){
	isl_union_map** userUnionMap = (isl_union_map**)user;

	map = isl_map_set_tuple_name(map,isl_dim_in,"");
	map = isl_map_set_tuple_name(map,isl_dim_out,"");

	{
		isl_union_map* unionMap = isl_union_map_from_map(map);
		if(!userUnionMap[0]){
			userUnionMap[0] = isl_union_map_copy(unionMap);
		}
		userUnionMap[0] = isl_union_map_coalesce(isl_union_map_union(userUnionMap[0], unionMap));
	}

	return isl_stat_ok;
}

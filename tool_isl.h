/*
 * tool_isl.h
 *
 *  Created on: Dec 11, 2021
 *
 */

#include <isl/map.h>

#ifndef TOOL_ISL_H_
#define TOOL_ISL_H_

#if defined(__cplusplus)
extern "C" {
#endif

isl_stat clear_tuple_names_in_map(__isl_take isl_map *map, void *user);

#if defined(__cplusplus)
}
#endif

#endif /* TOOL_ISL_H_ */

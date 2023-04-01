/*
 * dapt_params.h
 *
 *  Created on: May 25, 2020
 *
 */

#include <isl/ctx.h>

#ifndef DAPT_PARAMS_H_
#define DAPT_PARAMS_H_

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct dapt_params{
	char *filename;
	isl_bool debugPrintOn;
	isl_bool help;
} dapt_params;

void read_dapt_params(dapt_params *daptParams, int argc, char *argv[]);

#if defined(__cplusplus)
}
#endif

#endif /* DAPT_PARAMS_H_ */

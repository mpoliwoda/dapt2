/*
 * dapt_params.c
 *
 *  Created on: May 25, 2020
 *
 */

#include "dapt_params.h"
#include "tool_string.h"

void read_dapt_params(dapt_params *daptParams, int argc, char *argv[]){
	//char* paramValue;

	daptParams->filename = 0;
	daptParams->debugPrintOn = isl_bool_false;
	daptParams->help = isl_bool_false;


	if(is_param_set("--debug-print-on", argc, argv)){
		daptParams->debugPrintOn = isl_bool_true;
	}
	if(is_param_set("--help", argc, argv)){
		daptParams->help = isl_bool_true;
	}
	daptParams->filename = get_param_value("filename=", argc, argv);
	if(!daptParams->filename) daptParams->help = isl_bool_true;
}

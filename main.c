/*
 ============================================================================
 Name        : DAPT
 Author      :
 Version     :
 Copyright   :
 Description : Dependence Approximation for Parallelism and Tiling
 ============================================================================
 */

#include <stdlib.h>

#include <isl/ctx.h>

#include <pet.h>

#include "tool_string.h"
#include "loop_scop.h"
#include "tool_debug.h"
#include "dapt_params.h"
#include "loop_relations.h"


int main(int argc, char *argv[]) {
	isl_ctx *ctx = 0;
	pet_scop *petScop = 0;
	dapt_params daptParams;

	read_dapt_params(&daptParams, argc, argv);

	if(daptParams.help == isl_bool_true){
		char tabs[8];
		sprintf(tabs,"\t\t\t");

		printf("parameters\n");
		printf("\t%s%s%s\n", "filename=<path>      ", tabs, "file with loop to parse");


		printf("\t%s%s%s\n", "--debug-print-on           ", tabs, "print debug info to stderr");
		printf("\t%s%s%s\n", "--help                     ", tabs, "print this help, then exit");

		return EXIT_SUCCESS;
	}

	if(daptParams.debugPrintOn == isl_bool_true){
		isl_debug_on();
	}

	ctx = isl_ctx_alloc_with_pet_options();

	pet_options_set_signed_overflow(ctx, PET_OVERFLOW_IGNORE);
	pet_options_set_encapsulate_dynamic_control(ctx, 1);

	petScop = pet_scop_extract_from_C_source(ctx, daptParams.filename , NULL);
	if(petScop != 0){
		loop_scop *loopScop = loop_scop_extract_from_pet_scop(petScop, &daptParams);
		loop_scop_from_pet_debug_printf(loopScop);

		loop_relatios_analyse(loopScop);

		loopScop = loop_scop_loop_scop_free(loopScop);
	}

	pet_scop_free(petScop);
	isl_ctx_free(ctx);

	return EXIT_SUCCESS;
}

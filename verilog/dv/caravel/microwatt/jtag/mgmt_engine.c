#include "../../defs.h"
#include "../../stub.c"

#include "../include/microwatt_util.h"
#include "../include/mgmt_engine_util.h"

void main(void)
{
	mgmt_engine_io_setup(true, true);

	// Take microwatt out of reset
	reg_la2_data &= ~0x00000002;

	while (reg_la0_data != LA_MICROWATT_START)
		/* Do Nothing */ ;

	// Signal to TB that microwatt is alive
	reg_mprj_datal = GPIO1_MICROWATT_START;

	while (1)
		/* Do Nothing */;
}

#ifndef SS_DISPLAY_UP_DOWN_COUNTER_H
#define SS_DISPLAY_UP_DOWN_COUNTER_H

#include "ss_display.h"

typedef enum
{
	COUNT_UP,
	COUNT_DOWN
	}count_action_id;

void ss_display_vinit_counter(void);
void ss_display_vcount_up(void);
void ss_display_vcount_down(void);
void ss_display_vcount_up_down();
void ss_display_vrefresh_display(void);

#endif
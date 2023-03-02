#ifndef PASSWORD_H

#define PASSWORD_H

#include "password_cfg.h"


void password_init (void);
button_id_t get_entry(void);
void add_entry(button_id_t,u8 [MAX_CHARACTERS]);
boolean check_password(const u8 [CURRENT_PASSWORD_SIZE] ,u8 [MAX_CHARACTERS]);

#endif
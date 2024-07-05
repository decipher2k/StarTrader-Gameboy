#ifndef __StarSelect_INCLUDE__
#define __StarSelect_INCLUDE__

#include <gbdk/platform.h>
#include <stdint.h>

#define MUTE_MASK_StarSelect 0b00000100

BANKREF_EXTERN(StarSelect)
extern const uint8_t StarSelect[];
extern void __mute_mask_StarSelect;

#endif

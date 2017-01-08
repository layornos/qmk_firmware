#ifndef REV2_H
#define REV2_H

#include "../lets_split.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

//void promicro_bootloader_jmp(bool program);

#define KEYMAP( \
	k06, k05, k04, k03, k02, k01, k00, k56, k55, k54, k53, k52, k51, k50, \
	k16, k15, k14, k13, k12, k11, k10, k66, k65, k64, k63, k62, k61, k60, \
	k26, k25, k24, k23, k22, k21, k20, k76, k75, k74, k73, k72, k71, k70, \
	k36, k35, k34, k33, k32, k31, k30, k86, k85, k84, k83, k82, k81, k80, \
  k46, k45, k44, k43, k42, k41, k40, k96, k95, k94, k93, k92, k91, k90 \
	) \
	{ \
		{ k00, k01, k02, k03, k04, k05, k06 }, \
		{ k10, k11, k12, k13, k14, k15, k16 }, \
		{ k20, k21, k22, k23, k24, k25, k26 }, \
		{ k30, k31, k32, k33, k34, k35, k36 }, \
		{ k40, k41, k42, k43, k44, k45, k46 }, \
		{ k50, k51, k52, k53, k54, k55, k56 }, \
		{ k60, k61, k62, k63, k64, k65, k66 }, \
		{ k70, k71, k72, k73, k74, k75, k76 }, \
		{ k80, k81, k82, k83, k84, k85, k86 }, \
		{ k90, k91, k92, k93, k94, k95, k96 }  \
	}

#endif

// Copyright 2023 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_ADC_USE_ADC1
#define RP_ADC_USE_ADC1 TRUE

#undef RP_IRQ_ADC1_PRIORITY
#define RP_IRQ_ADC1_PRIORITY 2

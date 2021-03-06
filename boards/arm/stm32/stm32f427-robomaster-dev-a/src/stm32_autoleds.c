/****************************************************************************
 * boards/arm/stm32/stm3240g-eval/src/stm32_autoleds.c
 *
 *   Copyright (C) 2020 Cheng Huimin. All rights reserved.
 *   Author: Cheng Huimin
 *   Contributor: Bui Quang Huy
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <debug.h>

#include <nuttx/board.h>
#include <arch/board/board.h>

#include "chip.h"
#include "arm_arch.h"
#include "arm_internal.h"
#include "stm32.h"
#include "robomaster_dev_a.h"

#ifdef CONFIG_ARCH_LEDS

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/


/****************************************************************************
 * Private Functions
 ****************************************************************************/

static inline void led_clrbits(unsigned int clrbits)
{
  if ((clrbits & BOARD_LED1_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED1, false);
    }

  if ((clrbits & BOARD_LED2_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED2, false);
    }

  if ((clrbits & BOARD_LED3_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED3, false);
    }
  if ((clrbits & BOARD_LED4_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED4, false);
    }
  if ((clrbits & BOARD_LED5_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED5, false);
    }
  if ((clrbits & BOARD_LED6_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED6, false);
    }
  if ((clrbits & BOARD_LED7_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED7, false);
    }
  if ((clrbits & BOARD_LED8_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED8, false);
    }

}

static inline void led_setbits(unsigned int setbits)
{
  if ((setbits & BOARD_LED1_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED1, true);
    }

  if ((setbits & BOARD_LED2_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED2, true);
    }

  if ((setbits & BOARD_LED3_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED3, true);
    }
  if ((setbits & BOARD_LED4_BIT) != 0)
  {
    stm32_gpiowrite(GPIO_LED4, true);
  }
  if ((setbits & BOARD_LED5_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED5, true);
    }
  if ((setbits & BOARD_LED6_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED6, true);
    }
  if ((setbits & BOARD_LED7_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED7, true);
    }
  if ((setbits & BOARD_LED8_BIT) != 0)
    {
      stm32_gpiowrite(GPIO_LED8, true);
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_led_initialize
 ****************************************************************************/

void stm32_led_initialize(void)
{
   /* Configure LED1-4 GPIOs for output */

   stm32_configgpio(GPIO_LED1);
   stm32_configgpio(GPIO_LED2);
   stm32_configgpio(GPIO_LED3);
   stm32_configgpio(GPIO_LED4);
   stm32_configgpio(GPIO_LED5);
   stm32_configgpio(GPIO_LED6);
   stm32_configgpio(GPIO_LED7);
   stm32_configgpio(GPIO_LED8);

}

/****************************************************************************
 * Name: board_autoled_on
 ****************************************************************************/

void board_autoled_on(int led)
{
  switch (led)
  {
    case LED_STARTED:
      break;
    case LED_HEAPALLOCATE:
      led_setbits(BOARD_LED1_BIT);
      break;
    case LED_IRQSENABLED:
      led_setbits(BOARD_LED2_BIT);
      break;
    case LED_STACKCREATED:
      led_setbits(BOARD_LED3_BIT);
      break;
    case LED_INIRQ:
      led_setbits(BOARD_LED4_BIT);
      break;
    case LED_SIGNAL:
      led_setbits(BOARD_LED5_BIT);
      break;
    case LED_ASSERTION:
      led_setbits(BOARD_LED6_BIT);
      break;
    case LED_PANIC:
      led_setbits(BOARD_LED7_BIT);
      break;
  }
}

/****************************************************************************
 * Name: board_autoled_off
 ****************************************************************************/

void board_autoled_off(int led)
{
  led_clrbits(BOARD_LED1_BIT | BOARD_LED2_BIT | BOARD_LED3_BIT |\
              BOARD_LED4_BIT | BOARD_LED5_BIT | BOARD_LED6_BIT |\
              BOARD_LED7_BIT);
}

#endif /* CONFIG_ARCH_LEDS */

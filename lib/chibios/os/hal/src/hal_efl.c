/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    hal_efl.c
 * @brief   Embedded Flash Driver code.
 *
 * @addtogroup HAL_EFL
 * @{
 */

#include "hal.h"

#if (HAL_USE_EFL == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static const struct EFlashDriverVMT vmt = {
  (size_t)0,
  efl_lld_get_descriptor,
  efl_lld_read,
  efl_lld_program,
  efl_lld_start_erase_all,
  efl_lld_start_erase_sector,
  efl_lld_query_erase,
  efl_lld_verify_erase
};

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Embedded Flash Driver initialization.
 * @note    This function is implicitly invoked by @p halInit(), there is
 *          no need to explicitly initialize the driver.
 *
 * @init
 */
void eflInit(void) {

  efl_lld_init();
}

/**
 * @brief   Initializes a generic @p EFlashDriver object.
 *
 * @param[out] eflp     pointer to a @p EFlashDriver structure
 *
 * @init
 */
void eflObjectInit(EFlashDriver *eflp) {

  eflp->vmt = &vmt;
  eflp->state = FLASH_STOP;
}

/**
 * @brief   Configures and starts the driver.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 * @param[in] config    pointer to a configuration structure.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @api
 */
void eflStart(EFlashDriver *eflp, const EFlashConfig *config) {

  osalDbgCheck(eflp != NULL);

  osalSysLock();

  osalDbgAssert((eflp->state == FLASH_STOP) || (eflp->state == FLASH_READY),
                "invalid state");
  eflp->config = config;
  efl_lld_start(eflp);
  eflp->state = FLASH_READY;

  osalSysUnlock();
}

/**
 * @brief   Stops the driver.
 *
 * @param[in] eflp      pointer to a @p EFlashDriver structure
 *
 * @api
 */
void eflStop(EFlashDriver *eflp) {

  osalDbgCheck(eflp != NULL);

  osalSysLock();

  osalDbgAssert((eflp->state == FLASH_STOP) || (eflp->state == FLASH_READY),
                "invalid state");

  efl_lld_stop(eflp);
  eflp->state = FLASH_STOP;

  osalSysUnlock();
}

#endif /* HAL_USE_EFL == TRUE */

/** @} */

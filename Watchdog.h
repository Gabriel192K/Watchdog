#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

/* Dependencies */
#include <avr\wdt.h>

/**
 * @brief  Class to manage the watchdog timer.
 * 
 * This class provides methods to enable, disable, feed, and check the status of the watchdog timer.
 */
class __WATCHDOG__
{
    public:
        /**
         * @brief  Constructor for the Watchdog class.
         * @note   Does nothing in this case, but can be used for future extensions.
         */
        __WATCHDOG__();
        
        /**
         * @brief  Destructor for the Watchdog class.
         * @note   Does nothing in this case, but can be used for future extensions.
         */
        ~__WATCHDOG__();
        
        /**
         * @brief  Enables the watchdog timer with a specified timeout.
         * @param  timeout The timeout period for the watchdog (defined in terms of WDTO_* values).
         * @return 1 if the watchdog was successfully enabled, 0 if it failed.
         */
        const uint8_t enable(const uint8_t timeout);

        /**
         * @brief  Disables the watchdog timer.
         * @return 1 if the watchdog was successfully disabled, 0 if it was already disabled.
         */
        const uint8_t disable(void);
        
        /**
         * @brief  Checks if the watchdog timer is currently enabled.
         * @return 1 if the watchdog is enabled, 0 otherwise.
         */
        const uint8_t isEnabled(void);
        
        /**
         * @brief  Resets the watchdog timer to prevent it from triggering a reset.
         * @note   Does nothing if the watchdog is not enabled.
         */
        void feed(void);

    private:
        uint8_t enabled;  /**< Flag indicating whether the watchdog is enabled or not */
};

extern __WATCHDOG__ Watchdog;

#endif

/* Dependencies */
#include "Watchdog.h"

/*!
 * @brief  __WATCHDOG__ constructor
 */
__WATCHDOG__::__WATCHDOG__()
{
    /* Empty */
}

/*!
 * @brief  __WATCHDOG__ destructor
 */
__WATCHDOG__::~__WATCHDOG__()
{
    /* Empty */
}

/*!
 * @brief  Enables the watchdog timer with a predefined timeout value
 * @param  timeout
 *         The timeout value
 * @return Returns 1 if the timeout value is a valid one, otherwise returns 0
 */
const uint8_t __WATCHDOG__::enable(const uint8_t timeout)
{
    if (this->isEnabled())
        return (0);
    this->watchdogIsEnabled = 1;

    switch (timeout)
    {
        case WDTO_15MS:
        case WDTO_30MS:
        case WDTO_60MS:
        case WDTO_120MS:
        case WDTO_250MS:
        case WDTO_500MS:
        case WDTO_1S:
        case WDTO_2S:
        case WDTO_4S:
        case WDTO_8S:
            wdt_enable(timeout);
            break;
        default:
            return (0);
            break;
    }
    return (1);
}

/*!
 * @brief  Disables the watchdog timer
 */
void __WATCHDOG__::disable(void)
{
    if (!this->isEnabled())
        return;

    this->watchdogIsEnabled = 0;
    wdt_disable();
}

/*!
 * @brief  Checks if the watchdog timer is enabled
 * @return Returns the watchdog is enabled flag
 */
const uint8_t __WATCHDOG__::isEnabled(void)
{
    return (this->watchdogIsEnabled);
}

/*!
 * @brief  Feeds the watchdog timer
 */
void __WATCHDOG__::feed(void)
{
    if (!this->isEnabled())
        return;
    wdt_reset();
}

__WATCHDOG__ Watchdog = __WATCHDOG__();
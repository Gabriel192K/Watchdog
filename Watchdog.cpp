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

    switch (timeout)
    {
        #if defined(WDTO_15MS)
        case WDTO_15MS:
        #elif defined(WDTO_30MS)
        case WDTO_30MS:
        #elif defined(WDTO_60MS)
        case WDTO_60MS:
        #elif defined(WDTO_120MS)
        case WDTO_120MS:
        #elif defined(WDTO_250MS)
        case WDTO_250MS:
        #elif defined(WDTO_500MS)
        case WDTO_500MS:
        #elif defined(WDTO_1S)
        case WDTO_1S:
        #elif defined(WDTO_2S)
        case WDTO_2S:
        #elif defined(WDTO_4S)
        case WDTO_4S:
        #elif defined(WDTO_8S)
        case WDTO_8S:
        #else
        #error "No watchdog timeout value defined"
        #endif
            wdt_enable(timeout);
            break;
        #endif
        default:
            return (0);
            break;
    }

    this->enabled = 1;
    return (1);
}

/*!
 * @brief  Disables the watchdog timer
 */
void __WATCHDOG__::disable(void)
{
    if (!this->isEnabled())
        return;

    wdt_disable();
    this->enabled = 0;
}

/*!
 * @brief  Checks if the watchdog timer is enabled
 * @return Returns the watchdog is enabled flag
 */
const uint8_t __WATCHDOG__::isEnabled(void)
{
    return (this->enabled);
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
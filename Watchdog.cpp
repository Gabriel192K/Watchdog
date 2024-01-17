/* Dependencies */
#include "Watchdog.h"

__WATCHDOG__::__WATCHDOG__()
{
    /* Empty */
}

__WATCHDOG__::~__WATCHDOG__()
{
    /* Empty */
}

void __WATCHDOG__::enable(const uint8_t timeout)
{
    this->watchdogIsEnabled = 1;
    wdt_enable(timeout);
}

void __WATCHDOG__::disable(void)
{
    this->watchdogIsEnabled = 0;
    wdt_disable();
}

uint8_t __WATCHDOG__::isEnabled(void)
{
    return (this->watchdogIsEnabled);
}

void __WATCHDOG__::feed(void)
{
    if (!this->isEnabled())
        return;
    wdt_reset();
}

__WATCHDOG__ Watchdog = __WATCHDOG__();